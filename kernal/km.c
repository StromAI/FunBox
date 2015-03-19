#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>

static char *who = "sliencer";
static int times = 2;
module_param(times, int, S_IRUSR);
module_param(who, charp, S_IRUSR);

static int sliencer_init(void)
{
	int i;
	for (i = 0; i < times; ++i)
		printk("(%d)hello %s\n", i, who);	
	return 0;
}


static void sliencer_exit(void)
{
	printk("Good bye %s\n", who);
}

module_init(sliencer_init);
module_exit(sliencer_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sliencer");
MODULE_DESCRIPTION("hello");