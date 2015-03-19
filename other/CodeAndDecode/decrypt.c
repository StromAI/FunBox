 
/**
 *	decrypt.c
 *	decode text
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
find(char c1, char c2, char *a)
{
	int i = 0;
	while (*(a+i) != '\0')
	{
		if (c1 == *(a+i) && c2 == *(a+i+1))
			return i/2;
		i += 2;
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
	char readline[2000];

	FILE *fout = fopen("code.txt","r");
	
	if (fout)
	{
		while(fgets(readline,sizeof(char)*2000,fout))
		{
			i = 0;
			int j = 0;
			int n = strlen(readline);
			while (n--)
			{
				if (!(readline[i]>='0' && readline[i]<='9' 
					|| readline[i]>='a' && readline[i]<='z'
					|| readline[i]>='A' && readline[i]<='Z'))
				{
					printf("%c", readline[i]);
					++i;
				}
				else
				{
					j = find(readline[i],readline[i+1], cipher);
					printf("%c", plain[j]);
					i += 2;
					--n;
				}
			}
		}
		fclose(fout);
	}	
		
	exit(0);
}