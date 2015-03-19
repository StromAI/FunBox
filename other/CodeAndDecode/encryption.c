/**
 *	encryption.c
 *	code text
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
find(char c,char *a)
{
	int i = 0;
	while (*(a+i) != '\0')
	{
		if (c == *(a+i))
			return i;
		++i;
	}
	return -1;
}

int
main(int argc, char const *argv[])
{
	char plain[59];
	char cipher[117];
	char temp;
	int i = 0;
	FILE *fin = fopen("cipher.txt","r");
	if (fin)
	{
		while ((temp = fgetc(fin)) != '\n')
		{
			plain[i++] = temp;
		}
		i = 0;
		while ((temp = fgetc(fin)) != EOF)
		{
			cipher[i++] = temp;
		}
		fclose(fin);
	}
	char readline[1000];
	
	FILE *f = fopen("code.txt","w");
	fclose(f);

	FILE *fout = fopen("code.txt","w+");
	if (fout)
	{
		while (gets(readline))	
		{	
			fseek(fout, 0L,SEEK_END);
			i = 0;
			int j = 0;
			int n = strlen(readline);
			while (n--)
			{
				if (!(readline[i]>='0' && readline[i]<='9' 
					|| readline[i]>='a' && readline[i]<='z'
					|| readline[i]>='A' && readline[i]<='Z'))
				{
					fprintf(fout, "%c", readline[i]);
					++i;
				}
				else
				{
					j = find(readline[i], plain);
					fprintf(fout, "%c", cipher[j*2]);
					fprintf(fout, "%c", cipher[j*2+1]);
					++i;
				}
			}
			fprintf(fout, "\n");
		}
	}		
	fclose(fout);
	exit(0);
}