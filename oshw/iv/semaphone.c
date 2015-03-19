#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>

int CS = 0;
sem_t s;

void *t1()
{
	sem_wait(&s);
	CS++;
	printf("t1\n");
	sleep(1);	//make sure when t2 ask for CS t1 is in it
	sem_post(&s);
	sleep(1);
}

void *t2()
{
	sem_wait(&s);
	CS++;
	printf("t2\n");
	sem_post(&s);
	sleep(1);
}

int main(void)
{
	pthread_t tid1,tid2;

	sem_init(&s, 0, 1);
	pthread_create(&tid1, NULL, t1,NULL);
	pthread_create(&tid2, NULL, t2,NULL);
	
	sem_destroy(&s);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);//make sure pthread are end
	return 0;
}