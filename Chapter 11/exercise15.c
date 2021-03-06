// exercise15.c -- Chapter 11 
#include <stdio.h>
#include <ctype.h>		// for isdigit() -- for my_atoi()
#include <stdbool.h>	// 

#define SIZE 20

int my_atoi (const char * str);
char * s_gets (char *, int);

int main (void)
{
	char str[SIZE];
	int num;

	puts("Enter any alpha-numeric characters "
		"(or an empty string to finish the program):");
	while (s_gets(str, SIZE) && str[0])		// re-write source array in the loop
	{
		num = my_atoi(str);
		printf("num = %d\n", num);

		puts("Enter the next any alpha-numeric characters "
			"(or an empty string to finish the program):");
	}
	puts("The program has been completed.");

	return 0;
}

// for decimal number system only
int my_atoi (const char * str)
{
	int num;
	bool negative;

	for (num = 0, negative = false; *str; str++)
	{
		// additional processing
		if (str[0] == '-')
		{
			negative = true;
			str++;
		}

		// core function:
		////////////////////////////////////////////////////////////////
		if (isdigit(*str))
			num = num * 10 + (*str - '0');		// for ASCII code only
		else
		{
			num = 0;
			break;
		}
		////////////////////////////////////////////////////////////////
	}
	if (negative)
		num = -num;

	return num;
}

char * s_gets (char * str, int n)
{
	char * ret_val;

	ret_val = fgets(str, n, stdin);

	if (ret_val)
	{
		while (*str != '\n' && *str)
			str++;

		if ('\n' == *str)
			*str = '\0';
		else	// else if ('\0' == *str)
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
