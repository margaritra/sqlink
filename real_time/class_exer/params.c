#include <linux/module.h> /* for MODULE_*, module_* */
#include <linux/printk.h> /* for printk and pr_* APIs */
#include <linux/init.h> /* for __init, __exit */
#include <linux/moduleparam.h> /* for module_param(), MODULE_PARM_DESC() */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rachel and Rita");
MODULE_DESCRIPTION("A module showing off module parameters");
MODULE_VERSION("2.4.6");

/*The parameter can be a number, a string or an array (of numbers or strings)*/
static int someParam=10;
module_param(someParam,int,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
MODULE_PARM_DESC(someParam, "myint controls bla bla bla...");

static int __init myparam_init(void)
{
	pr_info("in myparam_init\n");
	pr_info("in myparam_init: myint is %d\n", someParam);
	return 0;
}

static void __exit myparam_exit(void)
{
	pr_info("in myparam_exit: myint is %d\n", someParam);
	pr_info("in myparam_exit\n");
}

module_init(myparam_init);
module_exit(myparam_exit);
