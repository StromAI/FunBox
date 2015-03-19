#include <unistd.h>
#include <stdio.h>

int a;

int main()
{
	pid_t fpid;
    
	fpid = fork();
	if(fpid < 0)
		printf("error in fork\n");
	else if(fpid == 0)
	{
		printf("Child process id is %d\n",getpid());
		a++;
		printf("%d\n",a);
	}
	else
	{
			printf("Root process id is %d\n",getpid());
			printf("%d\n",a);
	}
	return 0;
} 