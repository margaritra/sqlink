#include <linux/module.h> /* for MODULE_*, module_* */
#include <linux/printk.h> /* for printk and pr_* APIs */
#include <linux/init.h> /* for __init, __exit */
#include <linux/device.h>         // Header to support the kernel Driver Model
#include <linux/kernel.h>         // Contains types, macros, functions for the kernel
#include <linux/fs.h>             // Header for the Linux file system support
#include <linux/uaccess.h>          // Required for the copy to user function
#define  DEVICE_NAME "myNull"    ///< The device will appear at /dev/myNull using this value
#define  CLASS_NAME  "myNullClass"        ///< The device class -- this is a character device driver


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Margarita Borodin");
MODULE_DESCRIPTION("A simple Linux char driver for the dev/null");
MODULE_VERSION("4.15.0");


static int    majorNumber;                  ///< Stores the device number -- determined automatically
static char   message[256] = {0};           ///< Memory for the string that is passed from userspace
static short  size_of_message;              ///< Used to remember the size of the string stored
static int    numberOpens = 0;              ///< Counts the number of times the device is opened
static struct class*  myNullClass  = NULL; ///< The device-driver class struct pointer
static struct device* myNullDriver = NULL; ///< The device-driver device struct pointer

// The prototype functions for the character driver -- must come before the struct definition
static int     dev_open(struct inode *, struct file *);
static int     dev_release(struct inode *, struct file *);
//static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);

/** Devices are represented as file structure in the kernel. The file_operations structure from
 *  /linux/fs.h lists the callback functions that you wish to associated with your file operations
 *  using a C99 syntax structure. char devices usually implement open, read, write and release calls
 */
static struct file_operations fops =
{
   .open = dev_open,
   //.read = dev_read,
   .write = dev_write,
   .release = dev_release,
};

/** @brief This function is called whenever the device is being written to from user space i.e.
 *  data is sent to the device from the user. The data is copied to the message[] array in this
 *  LKM using the sprintf() function along with the length of the string.
 *  @param filep A pointer to a file object
 *  @param buffer The buffer to that contains the string to write to the device
 *  @param len The length of the array of data that is being passed in the const char buffer
 *  @param offset The offset if required
 */
static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset)
{
   sprintf(message, "%s(%zu letters)", buffer, len);   // appending received string with its length
   size_of_message = strlen(message);                 // store the length of the stored message
   printk(KERN_INFO "EBBChar: Received %zu characters from the user\n", len);
   return len;
}

static int __init myNull_init(void)
{
   printk(KERN_INFO "myNull: Initializing the myNull LKM\n");

   // Try to dynamically allocate a major number for the device -- more difficult but worth it
   majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
   if (majorNumber<0){
      printk(KERN_ALERT "myNull failed to register a major number\n");
      return majorNumber;
   }
   printk(KERN_INFO "myNull: registered correctly with major number %d\n", majorNumber);

   // Register the device class
   myNullClass = class_create(THIS_MODULE, CLASS_NAME);
   if (IS_ERR(myNullClass)){                // Check for error and clean up if there is
      unregister_chrdev(majorNumber, DEVICE_NAME);
      printk(KERN_ALERT "Failed to register device class\n");
      return PTR_ERR(myNullClass);          // Correct way to return an error on a pointer
   }
   printk(KERN_INFO "myNull: device class registered correctly\n");

   // Register the device driver
   myNullDriver = device_create(myNullClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);

   if (IS_ERR(myNullDriver))
	{               // Clean up if there is an error
      		class_destroy(myNullClass);           // Repeated code but the alternative is goto statements
      		unregister_chrdev(majorNumber, DEVICE_NAME);
      		printk(KERN_ALERT "Failed to create the device\n");
      		return PTR_ERR(myNullDriver);
	}
   printk(KERN_INFO "myNull: device class created correctly\n"); // Made it! device was initialized
   return 0;
}

/** The LKM cleanup function
 *  Similar to the initialization function, it is static. The __exit macro notifies that if this
 *  code is used for a built-in driver (not a LKM) that this function is not required.
 */


static void __exit myNull_exit(void)
{
   device_destroy(myNullClass, MKDEV(majorNumber, 0));     // remove the device
   class_unregister(myNullClass);                          // unregister the device class
   class_destroy(myNullClass);                             // remove the device class
   unregister_chrdev(majorNumber, DEVICE_NAME);             // unregister the major number
   printk(KERN_INFO "myNull: Goodbye from the LKM!\n");
}

/** The device open function that is called each time the device is opened
 *  This will only increment the numberOpens counter in this case.
 *  @param inodep A pointer to an inode object (defined in linux/fs.h)
 *  @param filep A pointer to a file object (defined in linux/fs.h)
 */


static int dev_open(struct inode *inodep, struct file *filep)
{
   numberOpens++;
   printk(KERN_INFO "myNull: Device has been opened %d time(s)\n", numberOpens);
   return 0;
}

/** The device release function that is called whenever the device is closed/released by
 *  the userspace program
 *  @param inodep A pointer to an inode object (defined in linux/fs.h)
 *  @param filep A pointer to a file object (defined in linux/fs.h)
 */
static int dev_release(struct inode *inodep, struct file *filep)
{
   printk(KERN_INFO "myNull: Device successfully closed\n");
   return 0;
}

module_init(myNull_init);
module_exit(myNull_exit);
