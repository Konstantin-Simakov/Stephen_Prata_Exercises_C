/* exercise10.c -- Chapter 13 */
#include <stdio.h>
#include <stdlib.h>

#define NAME 41
#define MAXL 81

char * s_gets(char *, int);

int main(void)
{
	FILE * fp;
	char fname_str[NAME];
	char temp_str[MAXL];
	long pos;

	puts("Enter the file name:");
	if (s_gets(fname_str, NAME) == NULL)
	{
		fputs("Cannot enter the file name.\n", stderr);
		exit(EXIT_FAILURE);
	}
	/*	Reading the file will be done in binary mode to 
			sequentially read each byte separately contained in the file. 
	   This is necessary for greater portability of the program.	*/
	if ((fp = fopen(fname_str, "rb")) == NULL)
	{
		fprintf(stderr, "Cannot open file %s\n", fname_str);
		exit(EXIT_FAILURE);
	}

	/* It is code realization. */
	puts("Enter the file position:");
	while (scanf("%ld", &pos) == 1 && pos >= 0)
	{
		fseek(fp, pos, SEEK_SET);		/* (The indicator of position is saved after fseek() using.) */
		fgets(temp_str, MAXL, fp);		/* This function contains internal loop. */
		fputs(temp_str, stdout);

		puts("Enter the file position (\'q\' or num < 0 to finish):");
	}
	puts("The program has been completed.");
	
	return 0;
}

/* This is necessary for input of file name. */
char * s_gets(char * str, int n)
{
	char * ret_val;

	ret_val = fgets(str, n, stdin);

	if (ret_val != NULL)
	{
		while (*str != '\n' && *str)
			str++;

		if ('\n' == *str)
			*str = '\0';
		else	// if ('\0' == *str) -- 
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
