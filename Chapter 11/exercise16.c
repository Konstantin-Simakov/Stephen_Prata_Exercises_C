/* exercise16.c -- Chapter 11 */
#include <stdio.h>		// for puts(), fgets(), getchar()
#include <string.h>		// for strcmp()
#include <ctype.h>		// for toupper(), tolower()

#define LIM 5
#define SIZE 20

char * s_gets(char *, int);
// ct == lim
void to_upper(char (*pt)[SIZE], int lim);
void to_lower(char (*pt)[SIZE], int lim);
void output(const char (*pt)[SIZE], int lim);

int main(int argc, char * argv[])
{
	char strings[LIM][SIZE];
	int ct = 0;

	puts("(\"-u\" (== argv[1]) convertes source strings to upper case strings.)");
	puts("(\"-l\" (== argv[1]) convertes source strings to lower case strings.)");
	puts("(In other cases source strings remain unchangeable.)");
	
	puts("\nEnter any strings (or empty strings to finish the program):");
	while (ct < LIM && s_gets(strings[ct], SIZE) && strings[ct][0])
	{
		ct++;
	}

	if (!strcmp(argv[1], "-u"))
		to_upper(strings, ct);
	else if (!strcmp(argv[1], "-l"))
		to_lower(strings, ct);

	output(strings, ct);

	puts("\nThe program has been completed.");

	return 0;
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

void to_upper(char (*strings)[SIZE], int lim)
{
	int i, j;

	for (i = 0; i < lim; i++)
		for (j = 0; strings[i][j]; j++)
			strings[i][j] = toupper(strings[i][j]);
}

void to_lower(char (*strings)[SIZE], int lim)
{
	int i, j;

	for (i = 0; i < lim; i++)
		for (j = 0; strings[i][j]; j++)
			strings[i][j] = tolower(strings[i][j]);
}

void output(const char (*strings)[SIZE], int lim)
{
	int i;

	for (i = 0; i < lim; i++)
		puts(strings[i]);
}
