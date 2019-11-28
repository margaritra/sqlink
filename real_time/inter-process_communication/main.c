/*create a kernel module that allows for inter-process communication in Linux.*/

#include <linux/module.h> /* for MODULE_*, module_* */
#include <linux/moduleparam.h> /* for module_param, MODULE_PARM_DESC */
#include <linux/fs.h> /* for fops */
#include <linux/device.h> /* for class_create */
#include <linux/slab.h> /* for kmalloc, kfree */
#include <linux/cdev.h> /* for cdev_* */
#include <linux/sched.h> /* for TASK_INTERRUPTIBLE and more constants , for create threads */
#include <linux/spinlock.h> /* for spinlock_t and ops on it */
#include <linux/wait.h> /* for wait_queue_head_t and ops on it */
#include <linux/uaccess.h> /* for copy_to_user, access_ok */
#include <linux/mutex.h>
#include <linux/kthread.h>
#include <linux/delay.h> /*for sleep*/
#include "mq.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rachel and Margarita");
MODULE_DESCRIPTION("message queue module");
MODULE_VERSION("4.15.0");

/* this variable will store the class */
static struct class *my_class;
/* this variable will hold our cdev struct */
static struct cdev cdev;
/* this is the first dev_t allocated to us... */
static dev_t first_dev;
/* number of minors we need... */
static int mq_count = 8;
/* this is our first minor (0 by default)*/
static int first_minor;

/*struct of the linked-list*/
struct my_mq_t {
	size_t size;
	size_t capacity;
	struct list_head list;
	struct device *mq_device; 
	wait_queue_head_t read_queue;
	wait_queue_head_t write_queue;
	struct mutex mq_mutex;
};

/* dynamic array of m_queues*/
static struct my_mq_t* m_queues; 

/*single node - contain the message*/
struct list_struct {
	char* buff;
	size_t size;
	struct list_head node;
};

static int mq_open(struct inode* inode, struct file *file)
{
	int q_num = iminor (inode) -MINOR(first_dev);
	file->private_data = m_queues + q_num;
	return 0;
}

static int queue_not_empty(struct my_mq_t* mq) {
	int ret;
	mutex_lock(&mq->mq_mutex);/*we ask if the queue is not empty*/
	ret=mq->size>0;
	if(!ret) {
		mutex_unlock(&mq->mq_mutex); /*if empty sleep + unlock until message is writing*/
	}
	return ret;
}

static int queue_has_space(struct my_mq_t* mq) {
	int ret;
	mutex_lock(&mq->mq_mutex);/*we ask for size of queue -> have to lock!*/
	ret=mq->size<mq->capacity;
	if(!ret) {
		mutex_unlock(&mq->mq_mutex); /*if no space -> sleep + unlock (till the next read)*/
	}
	return ret;
}

/*we design the api, (unsigned long input_data -always we need to cast)*/
static long mq_ioctl(struct file *file, unsigned int op, unsigned long arg)
{
	int ret;
	int ret_size;
	struct message_t message;
	/*from user struct to kernel struct*/
	struct message_t* kernel_struct;
	struct my_mq_t* mq;
	char* my_buf;
	struct list_struct* new_list_struct;

	mq = file->private_data;

	switch(op)
	{
		case MQ_SEND_MESSAGE:
			kernel_struct = (struct message_t*) arg;
			/*for the struct <pointer to message, size>*/
			ret = copy_from_user(&message, kernel_struct,sizeof(message));
			if(ret)
			{
				pr_err("%s: error in copy from user\n",THIS_MODULE->name);
				return ret;
			}
			my_buf =kmalloc(message.size,GFP_KERNEL);
			if(IS_ERR(my_buf))
			{
				pr_err("%s: error in kmalloc\n", THIS_MODULE->name);
				return ret;
			}
			/*for the message*/
			ret = copy_from_user(my_buf, message.buff,message.size);
			if(ret)
			{
				pr_err("%s: error in copy from user\n",THIS_MODULE->name);
				return ret;
			}
			new_list_struct = kmalloc(sizeof(struct list_struct), GFP_KERNEL);
			if(IS_ERR(new_list_struct))
			{
				pr_err("%s: error in kmalloc\n", THIS_MODULE->name);
				return PTR_ERR(new_list_struct);
			}
			new_list_struct->buff= my_buf;
			new_list_struct->size = message.size;

			ret=wait_event_interruptible(mq->write_queue, queue_has_space(mq));
			if(ret==-ERESTARTSYS) {
				/* we don't release the mutex in this branch */
				return ret;
			}
			list_add_tail(&(new_list_struct->node),&(mq->list));
			mq->size++;
			mutex_unlock(&mq->mq_mutex);
			wake_up_interruptible(&mq->read_queue);
			return new_list_struct->size;/*we need to return size written byts*/
		case MQ_GET_MESSAGE:
			/*we need to unlock if sleeping*/
			ret=wait_event_interruptible(mq->read_queue,queue_not_empty(mq));
			if(ret==-ERESTARTSYS) {
				/* we don't release the mutex in this branch */
				return ret;
			}
			new_list_struct = list_entry((&mq->list)->prev, struct list_struct, node);			
			list_del_init((&mq->list)->prev);
			mutex_unlock(&mq->mq_mutex);
			wake_up_interruptible(&mq->write_queue);

			ret_size = new_list_struct->size;
			ret = copy_to_user((char*) arg, new_list_struct->buff, ret_size);
			if(ret)
			{
				pr_err("%s: error in copy to user\n",THIS_MODULE->name);
				return ret;
			}
			kfree(new_list_struct->buff);
			kfree(new_list_struct);
			mq->size--;
			return ret_size;
		default:
			return -ENOTTY;
	}

	return -ENOTTY;
}


/* this is the operations table */
static const struct file_operations queue_fops = {
	.owner = THIS_MODULE,
	.open = mq_open,
	.unlocked_ioctl = mq_ioctl,
};

static inline void m_queues_ctor(struct my_mq_t* m_queues)
{
	m_queues->size =0;
	m_queues->capacity=100;
	INIT_LIST_HEAD(&m_queues->list);
	m_queues->mq_device=NULL;
	init_waitqueue_head(&m_queues->read_queue);
	init_waitqueue_head(&m_queues->write_queue);
	mutex_init(&m_queues->mq_mutex);
}

static inline void m_queues_dtor(struct my_mq_t *m_queue)
{
	struct list_struct* new_element;
	list_for_each_entry(new_element, &m_queue->list, node)
	{
		kfree(new_element->buff);
		kfree(new_element);
	}
	mutex_destroy(&m_queue->mq_mutex);
}

static int __init mq_init(void)
{
	int ret;
	int i;
	/* allocate all queues */
	m_queues = kmalloc(sizeof(struct my_mq_t)*mq_count, GFP_KERNEL);
	if (IS_ERR(m_queues)) 
	{
		pr_err("kmalloc\n");
		ret = PTR_ERR(m_queues);
		goto err_return;
	}
	/* initialize all m_queues */
	for (i = 0; i < mq_count; i++)
		m_queues_ctor(m_queues+i);
	/* allocate our own range of devices */
	ret = alloc_chrdev_region(&first_dev, first_minor, mq_count,THIS_MODULE->name);
	if (ret) 
	{
		pr_err("cannot alloc_chrdev_region\n");
		goto err_final;
	}
	pr_debug("allocated the region\n");
	/* add the cdev structure */
	cdev_init(&cdev, &queue_fops);
	ret = cdev_add(&cdev, first_dev, mq_count);
	if (ret) 
	{
		pr_err("cannot cdev_add\n");
		goto err_dealloc;
	}
	pr_debug("added the cdev\n");
	/* this is creating a new class (/proc/devices) */
	my_class = class_create(THIS_MODULE, THIS_MODULE->name);
	if (IS_ERR(my_class)) 
	{
		pr_err("class_create\n");
		ret = PTR_ERR(my_class);
		goto err_cdev_del;
	}
	pr_debug("created the class\n");
	for (i = 0; i < mq_count; i++) 
	{
		/* and now lets auto-create a /dev/ node */
		m_queues[i].mq_device = device_create(my_class, NULL,
			MKDEV(MAJOR(first_dev), MINOR(first_dev)+i),
			NULL, "%s%d", THIS_MODULE->name, i);
		if (IS_ERR(m_queues[i].mq_device)) 
		{
			pr_err("device_create\n");
			ret = PTR_ERR(m_queues[i].mq_device);
			goto err_class;
		}
	}
	pr_info(KBUILD_MODNAME " loaded successfully\n");
	return 0;

err_class:
	class_destroy(my_class);
err_cdev_del:
	cdev_del(&cdev);
err_dealloc:
	unregister_chrdev_region(first_dev, mq_count);
err_final:
	for (i = 0; i < mq_count; i++)
		m_queues_dtor(m_queues+i);
	kfree(m_queues);
err_return:
	return ret;
}

static void __exit mq_exit(void)
{
	int i;
	for (i = 0; i < mq_count; i++)
	{
		device_destroy(my_class, MKDEV(MAJOR(first_dev), MINOR(first_dev)+i));
	}
	class_destroy(my_class);
	cdev_del(&cdev);
	unregister_chrdev_region(first_dev, mq_count);
	for (i = 0; i < mq_count; i++)
	{
		m_queues_dtor(m_queues+i);
	}
	kfree(m_queues);
	pr_info(KBUILD_MODNAME " unloaded successfully\n");
}

module_init(mq_init);
module_exit(mq_exit);

/*
case:
	wait_event_interruptible(mq->read_queue,my_list_not_empy(mutex, list));
	//do work tith list

int my_list_not_empy(mutex, list)
{
	mutex_lock(mutex)
	int ret = !list_empty(list);
	if(!ret)
	{
		mutex_unlock(m);
	}
	//mutex lock!!!
	//int ret= list_empty();
	//if(ret)
	//if not empty-> mutex unlock
	//	mutex_unlock;
}*/
