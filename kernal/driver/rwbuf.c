//rwbuf.c driver for virtual char-device

#include "rwbuf.h"
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>

static struct  file_operations rwbuf_fops=
{
	open:		rwbuf_open,
	release:	rwbuf_close,
	read:		rwbuf_read,
	write:		rwbuf_write,
	ioctl:		rwbuf_ioctl,
};

/*.unlock_ioctl=rwbuf_ioctl*/

int init_module()
{
	printk("Hello world 211\n");
	if (register_chardev(60, DEVICE_NAME, &rwbuf_fops))
	{
		printk("register error\n");
		return -1;
	}
	printk("register ok\n");
	return 0;
}


void cleanup_module()
{
	if (unregister_chardev(60, DEVICE_NAME) != 0)
	{
		printk("unreg err\n");
	}
	else
		printk("unreg err\n");
	printk("bye\n");
}

static int inuse=0;	//only one process permited at the same time
static int rwbuf_open(struct inode *inode, struct file * filep)
{
	if(inuse == 1)
		return -1;
	inuse = 1;

	MOD_INC_USE_COUNT;
	return 0;
}

static int rwbuf_close(struct inode *inode, struct file * filep)
{
	inuse = 0;
	MOD_INC_DEC_COUNT;
	return 0;
}

#define rwbuf_size 200	//MAX size of buffer
static char rwbuf[rwbuf_size] = "13121211";
static int rwlen = 0;

static ssize_t rwbuf_write(struct file * filep, const char *buf, size_t count, loff_t * ppos)
{
	if (count > rwbuf_size)
	{
		return -1;
	}
	copy_from_user(rwbuf, buf, count);
	rwlen = count;

	printk("buf write ok\n");
	return count;
}

static ssize_t rwbuf_read(struct file *filep, char * buf, size_t count loff_t * ppos)
{
	if (count > rwlen)
	{
		return -1;
	}
	copy_to_user(buf, rwbuf, count);

	printk("read ok\n");
	return count;
}

static int rwbuf_ioctl(struct inode * inode, struct file * filep, unsigned int cmd, unsigned long arg)
{
	if(cmd == RW_CLEAR)
	{
		rwlen = 0;
		printk("rwbuf in kernel zero-ed\n");
		//break;
	}
	return 0;
}