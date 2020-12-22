#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/types.h>

MODULE_AUTHOR("Ivan Fedorusov <i.fedorusov-2024@kpi.ua>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint counter = 1;
module_param(counter,uint,S_IRUGO);
MODULE_PARM_DESC(counter, "This parameter is for number of hello world");

static int __init hello_init(void)
{
	uint i = 0;
  	printk(KERN_INFO "Input %d\n", counter);

	if(counter == 0) 
	{
		printk(KERN_WARNING "You cannot enter 0");
	}
	else if(counter >=5 && counter <= 10) 
	{
		printk(KERN_WARNING "You should enter number less than 5");
	} 
	else if(counter > 10) 
	{
		printk(KERN_ERR "The parameter is greater than 10");
		return -EINVAL;
	}

	for(i = 0; i < counter; i++){
		printk(KERN_INFO "Hello, world!\n");
	}
	
	return 0;
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
