/**
 *	creatCipter.c
 *	will create the cipher
 */
#include <stdio.h>
#include <stdlib.h>


int 
main(int argc, char const *argv[])
{
 	FILE *fp = fopen("cipher.txt","w");
	int i;
 	for (i = '0'; i <= '9'; ++i)
 	{
 		fprintf(fp, "%c", i);
 	}
 	for (i = 'a'; i <= 'z'; ++i)
 	{
 		fprintf(fp, "%c", i);
 	}
 	for (i = 'A'; i <= 'Z'; ++i)
 	{
 		fprintf(fp, "%c", i);
 	}
 	fprintf(fp, "\n");
 	for (i = '0'; i <= '9'; ++i)
 	{
 		fprintf(fp, "%c%c", i, i);
 	}
 	for (i = 'a'; i <= 'z'; ++i)
 	{
 		fprintf(fp, "%c%c", i, i);
 	}
 	for (i = 'A'; i <= 'Z'; ++i)
 	{
 		fprintf(fp, "%c%c", i, i);
 	}
 	fclose(fp);
	exit(0);
} 
