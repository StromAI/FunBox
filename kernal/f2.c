#include <linux/mudule.h>
#include <linux/kerner.h>
#include <linux/pro_fs.h>
#include <linux/sched.h>
#include <linux/uaccess.h>

#define STRINGLEN 1024

char global_buffer[STRINGLEN];

struct proc_dir_entry *example_dir, *hello_file, *current_file, *symlink;

int proc_read_current(char *page, char **start, off_t off int count, int *eof, void *data)
{
	int len;
	try_module_get(THIS_MODULE);
	len = sprintf(page, "cunt process usages: \nname:%s \n",
		current->comm, current->pid);

	module_put(THIS_MODULE);
	return len;
}

int proc_read_hello(char *page, char **start, off_t off int count, int *eof, void *data)
{
	int len;
	try_module_get(THIS_MODULE);
	len = sprintf(page,"hello message:%s\nwrite:%s\n", current->comm,current->global_buffer);

	module_put(THIS_MODULE);
	return len;
}

int proc_write_hello(char *page, char **start, off_t off int count, int *eof, void *data)
{
	int len;
	try_module_get(THIS_MODULE);
	if(count >= STRINGLEN)
		len = STRINGLEN - 1;
	else
		len = count;
	copy_from_user(global_buffer, buffer, len);

	global_buffer[len] = '\0';

	module_put(THIS_MODULE);
	return len;
}

static int init(void)
{
	example_dir = proc_mkdir("13121211", NULL);
	current_file = create_proc_read_entry("xiao", 0666, example_dir, proc_read_current, NULL);
	hello_file = create_proc_entry("xiaojianwei", 0666, example_dir);
	strcpy(global_buffer,"xiao");
	hello_file->read_proc = proc_read_hello;
	hello_file->proc_proc = proc_write_hello;

	symlink = proc_symlink("xiao_too", example_dir, "xiao");

	return 0;
}

static void cleanup(void)
{
	remove_proc_entry("xiao_too", example_dir);
	remove_proc_entry("xiaojianwei", example_dir);
	remove_proc_entry("xiao", example_dir);
	remove_proc_entry("13121211", NULL);
}


module_init(init);
module_exit(cleanup);