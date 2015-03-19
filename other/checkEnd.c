#include <stdio.h>
#include <stdlib.h>

int
checkEnd()
{
	int i = 0x12345678;
	char * c = (char*)&i;
	return (*c == 0x12);
} 

int 
main(int argc, char const *argv[])
{
	int a = checkEnd();
	printf("%d\n",a);
	exit(0);
}
