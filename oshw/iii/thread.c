#include "apue.h"
#include <pthread.h>

pthread_t ntid1,ntid2;

int a = 0;

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;
	a++;
	pid = getpid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid,
		(unsigned long)tid, (unsigned long)tid);
	printf("%d\n",a);
}

void *thr_fn1(void *arg)
{
	printids("New thred: ");
	return((void *) 0);
}


void *thr_fn2(void *arg)
{
	a++;
	printids("New thred: ");
	return((void *) 0);
}

int main(void)
{
	int err1,err2;

	err1 = pthread_create(&ntid1, NULL, thr_fn1,NULL);
	if (err1 != 0)
		err_exit(err1, "can't create thred");
	err2 = pthread_create(&ntid2, NULL, thr_fn2,NULL);
	if (err2 != 0)
		err_exit(err2, "can't create thred");
	printids("main thred:");
	sleep(1);
	exit(0);
}