/* exercise8.c -- Chapter 11 */
#include <stdio.h>
#include <string.h>		// for strlen()

#define SIZE1 20
#define SIZE2 (SIZE1 / 2)

char * string_in(const char *, const char *);
char * s_gets(char *, int);

int main(void)
{
	char str1[SIZE1];
	char str2[SIZE2];
	char * ptr;

	/*ptr = string_in(str1, str2);
	if (!ptr)
		puts("NULL");
	else
		puts(ptr);*/

	puts("Enter the first string (or empty string to finish the program):");
	while (s_gets(str1, SIZE1) && str1[0])
	{
		puts("Enter the second string:");
		while (!s_gets(str2, SIZE2) || !str2[0])
			puts("Incorrect input of the second string. "
				"Try again:");

		ptr = string_in(str1, str2);
		if (!ptr)
			puts("NULL");
		else
			puts(ptr);

		puts("Enter the first string (or empty string to finish the program):");
	}
	puts("The program has been completed.");
	
	return 0;
}

/* Does s1 consist string s2? */
char * string_in(const char * s1, const char * s2)
{
	const int LEN_S2 = strlen(s2);

	int i;
	char * ret_val = NULL;
	char * tmp;

	while (*s1)
	{
		if (*s1 == s2[0])
		{
			tmp = (char *) s1;
			for (i = 1, tmp++; i < LEN_S2 && *tmp && *tmp == s2[i]; i++, tmp++)
				continue;
			if (LEN_S2 == i)
			{
				ret_val = tmp - LEN_S2;
				break;
			}
		}
		s1++;
	}

	return ret_val;
}

char * s_gets(char * st, int n)
{
	char * ret_val;

	ret_val = fgets(st, n, stdin);

	if (ret_val)
	{
		while (*st != '\n' && *st)
			st++;

		if ('\n' == *st)
			*st = '\0';
		else	// if ('\0' == *st)
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
