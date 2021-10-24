/* exercise6.c -- Chapter 13 */
#include <stdio.h>		// for FILE struct
#include <stdlib.h>		// for exit()
#include <string.h>

// Here you can choose any value for LEN consstant.
#define LEN (11 + 1)	// + 1 -- for the last '\0' character.

void copying_data_3rd(FILE *, FILE *);
void get_target_file_name(char *, const char *, int);
char * s_gets(char *, int);

int main(void)
{
	FILE * in, * out;
	char fname_src[LEN], fname_trg[LEN];

	// It is creating of source filename.
	puts("Enter filename of a source existing file:");
	s_gets(fname_src, LEN);
	// It is opening of source file.
	if ((in = fopen(fname_src, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open file \"%s\"\n", fname_src);
		exit(EXIT_FAILURE);
	}

	// It is creating of target filename.
	get_target_file_name(fname_trg, fname_src, LEN);
	// It is new file name notification.
	printf("The target filename is \"%s\" because the tartget "
		"array size is (%d + %d) including \'\\0\'.\n", 
		fname_trg, LEN - 1, 1);

	// It is opening target file.
	if ((out = fopen(fname_trg, "w")) == NULL)
	{
		fprintf(stderr, "Cannot open file \"%s\"\n", fname_trg);
		exit(EXIT_FAILURE);
	}

	// It is copying data (associativity is the same as for an assignment operation).
	copying_data_3rd(out, in);

	// It is cleaning.
	if (fclose(in) || fclose(out))
		fputs("An error occurred while closing the file.\n", stderr);
	
	return 0;
}

// It is copying data.
void copying_data_3rd(FILE * out, FILE * in)
{
	int count = 0;
	int ch;

	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);			// output every 3rd character
}

// It is creating of target filename.
void get_target_file_name(char * str_trg, const char * str_src, int stlen)
{
	char * find;

	if (strlen(str_src) < stlen - (3 + 1) 
		&& (find = strchr(str_src, '.')) != NULL)
	{
		// The first case.
		// Two subcases for the first case.
		strncpy(str_trg, str_src, find - str_src + 1);
		strncat(str_trg, "red", stlen - strlen(str_trg) - 1);		// Good.
	}
	else
	{
		// The second case.
		strncpy(str_trg, str_src, stlen - (4 + 1));
		str_trg[stlen - (4 + 1)] = '\0';
		strncat(str_trg, ".red", stlen - strlen(str_trg) - 1);		// Good.
	}
}

// It is more better function than fgets() or gets() all the more.
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
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
