/* exercise9.c -- Chapter 11 */
#include <stdio.h>
#include <string.h>		// for strlen()

#define SIZE 50

void str_change (char *);
char * s_gets (char *, int);

int main (void)
{
	char str[SIZE];

	puts("Enter a string (or an empty string to finish the program):");
	while (s_gets(str, SIZE) != NULL && str[0] != '\0')
	{
		str_change(str);
		puts(str);

		puts("Enter a string (or an empty string to finish the program):");
	}
	puts("The program has been completed.");
	
	return 0;
}

void str_change (char * str)
{
	const int STLEN = strlen(str);		// without '\0'!!!

	int i;
	char temp;

	for (i = 0; i < STLEN / 2; i++)
	{
		temp = str[i];
		str[i] = str[STLEN - 1 - i];
		str[STLEN - 1 - i] = temp;
	}
}

char * s_gets(char * str, int n)
{
	char * ret_val;

	ret_val = fgets(str, n, stdin);

	if (ret_val)
	{
		while (*str != '\n' && *str)
			str++;

		if ('\n' == *str)
			*str = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
