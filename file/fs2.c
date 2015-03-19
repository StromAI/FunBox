#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main()
{
	int fd;
	pid_t pid;
	struct flock rdlock, wrlock;
	rdlock.l_type = F_RDLCK;
	rdlock.l_start = 0;
	rdlock.l_whence = SEEK_SET;
	rdlock.l_len = 0;
	
	wrlock.l_type = F_WRLCK;
	wrlock.l_start = 0;
	wrlock.l_whence = SEEK_SET;
	wrlock.l_len = 0;

	if((fd = open("myfile", O_RDWR)) < 0){
		printf("Cannot open the file\n");
		exit(EXIT_FAILURE);
	}
	if((write(fd, "abcdefgh", 8)) != 8){
		printf("Cannot write to the file\n");
		exit(EXIT_FAILURE);
	}
	
	pid =fork();
	
	if(pid < 0){
		printf("Cannot fork\n");
		exit(EXIT_FAILURE);
	}
	if(pid == 0){
		if(fcntl(fd, F_GETLK, &rdlock) == -1){
			printf("Child cannot lock\n");
			exit(EXIT_FAILURE);
		}
		if(rdlock.l_type == F_UNLCK)
			printf("lock off\n");
		else
			printf("lock on\n");
	}else{
		if(fcntl(fd, F_SETLK, &wrlock) == -1){
			printf("Parent cannot lock\n");
			exit(EXIT_FAILURE);
		}else{
			if(write(fd, "aaaa", 4) != 4){
				printf("Cannot write to the file\n");
				exit(EXIT_FAILURE);
			}
			wait(NULL);
		}
	}
	close(fd);
	return 0;
}
