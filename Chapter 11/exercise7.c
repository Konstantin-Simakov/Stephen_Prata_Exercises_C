/* exercise7.c -- Chapter 11 */
#include <stdio.h>
#include <string.h>		/* for strlen() */

#define SIZE_SRC 8
#define SIZE_TRG 7

char * s_gets(char *, int);
char * my_strncpy(char *, const char *, int);

int main(void)
{
	char str_src[SIZE_SRC];
	char str_trg[SIZE_TRG];
	char * ptr;

	puts("Enter source string:");
	while (s_gets(str_src, SIZE_SRC) && str_src[0])
	{
		puts("Source string:");
		puts(str_src);
		printf("The length of the source string: %lu\n", 
			strlen(str_src));

		/* Attention to the programmer! 
		   This is standard processing of strncpy() */
		ptr = my_strncpy(str_trg, str_src, SIZE_TRG - 1);
		str_trg[SIZE_TRG - 1] = '\0';
		/* //////////////////////////////////////// */

		puts("Target string:");
		puts(str_trg);
		printf("The length of the target string: %lu\n", 
			strlen(str_trg));

		puts("Pointer to the target string after my_strncpy() using:");
		puts(ptr);
		printf("The length of the target string with pointer: %lu\n", 
			strlen(ptr));
	}
	puts("The program has been completed.");
	
	return 0;
}

char * my_strncpy(char * s1, const char * s2, int n)
{
	int i = 0;

	while (i < n && *s2)
	{
		s1[i] = s2[i];
		i++;
	}

	return s1;
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
		else	// if ('\0' == *str)
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
