/* exercise1.c -- Chapter 11 */
#include <stdio.h>

#define SIZE 10

char * str_input (char * str, int n);

int main (void)
{
	char str[SIZE];

	str_input(str, SIZE);
	puts(str);
	
	return 0;
}

/* reads n - 1 characters, n-th character is '\0' */
char * str_input (char * str, int n)
{
	int i = 0;

	while (i < n - 1 && (str[i] = getchar()) != EOF)
	{
		i++;
	}

	if (EOF == str[i])
		str = NULL;
	else	// if (str[n - 1] == str[i])
		str[i] = '\0';

	return str;
}
