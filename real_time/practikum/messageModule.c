/*create a kernel module that allows for inter-process communication in Linux.*/

#include <linux/module.h> /* for MODULE_*, module_* */
#include <linux/moduleparam.h> /* for module_param, MODULE_PARM_DESC */
#include <linux/fs.h> /* for fops */
#include <linux/device.h> /* for class_create */
#include <linux/slab.h> /* for kmalloc, kfree */
#include <linux/cdev.h> /* for cdev_* */
#include <linux/sched.h> /* for TASK_INTERRUPTIBLE and more constants */
#include <linux/spinlock.h> /* for spinlock_t and ops on it */
#include <linux/wait.h> /* for wait_queue_head_t and ops on it */
#include <linux/uaccess.h> /* for copy_to_user, access_ok */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rachel and Margarita");
MODULE_DESCRIPTION("message queue module");
MODULE_VERSION("4.15.0");


/* this is the operations table */
static const struct file_operations queue_fops = {
	.owner = THIS_MODULE,
	//.open = 
	//.release = write_null,
};

/* this variable will store the class */
static struct class *my_class;
/* this variable will hold our cdev struct */
static struct cdev cdev;
/* this variable will store the device */
static struct device *my_device;
/* this is the first dev_t allocated to us... */
static dev_t first_dev;
/* number of minors we need... */
static int mq_count = 8;
/* this is our first minor (0 by default)*/
static int first_minor;


/*struct my_mq_t {
	size_t size;
	size_t capacity;
	struct list_head list;
	struct device *mq_device; 
};*/

static int __init mq_init(void)
{
	int err;
	pr_info("init start\n");
	/* allocate our own range of devices */
	err = alloc_chrdev_region(&first_dev, first_minor, mq_count,THIS_MODULE->name);
	if (err) 
	{
		pr_err("cannot alloc_chrdev_region\n");
		goto err_nothing;
	}
	pr_info("allocated the region\n");
	/* add the cdev structure */
	cdev_init(&cdev, &queue_fops);
	err = cdev_add(&cdev, first_dev, mq_count);
	if (err) 
	{
		pr_err("cannot cdev_add\n");
		goto err_cdev_del;
	}
	pr_info("added the cdev\n");
	/* this is creating a new class (/sys/class) */
	my_class = class_create(THIS_MODULE, THIS_MODULE->name);
	if (IS_ERR(my_class)) 
	{
		pr_err("failed to create class\n");
		err = PTR_ERR(my_class);
		goto err_cdev_del;
	}
	pr_info("created class\n");
	/* and now lets auto-create a /dev/ node */
	my_device = device_create(my_class, NULL, first_dev,"%s", THIS_MODULE->name);
	if (IS_ERR(my_device)) 
	{
		pr_err("failed to create device\n");
		err = PTR_ERR(my_device);
		goto err_class;
	}
	pr_info("emitted message to udev to create /dev file in user space\n");
	pr_info("device loaded successfuly\n");
	return 0;
/* err_device:
	device_destroy(my_class, first_dev);
*/
err_class:
	class_destroy(my_class);
err_cdev_del:
	cdev_del(&cdev);
	unregister_chrdev_region(first_dev, mq_count);
err_nothing:
	return err;
}

static void __exit mq_exit(void)
{
	pr_info("exit start\n");
	device_destroy(my_class, first_dev);
	class_destroy(my_class);
	cdev_del(&cdev);
	unregister_chrdev_region(first_dev, mq_count);
	pr_info("device unloaded successfuly\n");
}

module_init(mq_init);
module_exit(mq_exit);