// exercise12.c -- Chapter 11
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define LIM 20							// saficiently number of input characters
#define SIZE 40							// saficiently number of input characters

char * s_gets(char * st, int n);
// ct == lim
int words_strs(const char (*strs)[SIZE], int lim);
int upper_strs(const char (*strs)[SIZE], int lim);
int lower_strs(const char (*strs)[SIZE], int lim);
int punct_strs(const char (*strs)[SIZE], int lim);
int digit_strs(const char (*strs)[SIZE], int lim);

int main(void)
{
	char strs[LIM][SIZE];
	int ct_strs = 0;

	printf("Enter up to %d strings "
		"(or an empty line to finish the program):\n", LIM);
	while (ct_strs < LIM && s_gets(strs[ct_strs], SIZE))		// while EOF won't be input
	{
		ct_strs++;
	}

	// answers:
	putchar('\n');
	printf("The words number in this text is %d.\n", words_strs(strs, ct_strs));
	printf("The upper case characters number in this text is %d.\n", upper_strs(strs, ct_strs));
	printf("The lower case chapteracters number in this text is %d.\n", lower_strs(strs, ct_strs));
	printf("The punctuation marks number in this text is %d.\n", punct_strs(strs, ct_strs));
	printf("The alpha-numeric number in this text is %d.\n", digit_strs(strs, ct_strs));
	putchar('\n');

	puts("The program has been completed.");

	return 0;
}

// processing functions
int words_strs(const char (*strs)[SIZE], int lim)
{
	int ct_wds = 0;
	bool in_word;
	int i, j;
 
	for (i = 0, in_word = false; i < lim; i++)
	{
		for (j = 0; strs[i][j]; j++)
		{
			if (!isspace(strs[i][j]) && !in_word)
			{
				in_word = true;
				ct_wds++;
			}
			else if (isspace(strs[i][j]) && in_word)
				in_word = false;			
		}
		in_word = false;	// i.e. '\0' == str[i][j] (<==> isspace(str[i][j]) -> '\n')
	}

	return ct_wds;
}

int upper_strs(const char (*strs)[SIZE], int lim)
{
	int uc = 0;
	int i, j;

	for (i = 0; i < lim; i++)
		for (j = 0; strs[i][j]; j++)
			if (isupper(strs[i][j]))
				uc++;

	return uc;
}

int lower_strs(const char (*strs)[SIZE], int lim)
{
	int lc = 0;
	int i, j;

	for (i = 0; i < lim; i++)
		for (j = 0; strs[i][j]; j++)
			if (islower(strs[i][j]))
				lc++;

	return lc;
}

int punct_strs(const char (*strs)[SIZE], int lim)
{
	int pc = 0;
	int i, j;

	for (i = 0; i < lim; i++)
		for (j = 0; strs[i][j]; j++)
			if (ispunct(strs[i][j]))
				pc++;

	return pc;
}

int digit_strs(const char (*strs)[SIZE], int lim)
{
	int dc = 0;
	int i, j;

	for (i = 0; i < lim; i++)
		for (j = 0; strs[i][j]; j++)
			if (isdigit(strs[i][j]))
				dc++;

	return dc;
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
