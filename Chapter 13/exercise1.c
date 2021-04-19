/* exercise1.c -- Chapter 13 */
#include <stdio.h>
#include <stdlib.h>						// for exit()

#define SIZE 40

char * s_gets (char *, int);

int main (void)
{
	FILE * fp;
	int ch;
	unsigned long count = 0;
	char filename[SIZE];

	puts("Enter the filename:");
	if (s_gets(filename, SIZE) == NULL)
	{
		fputs("Cannot input filename.\n", stderr);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putchar(ch);
		count++;
	}
	fclose(fp);

	printf("The file %s consists of %ld characters.\n", filename, count);

	return 0;
}

// It is needed to delete '\n' character.
char * s_gets (char * st, int n)
{
	char * ret_val;

	ret_val = fgets(st, n, stdin);
	if (ret_val)						// == if fgets() doesn't meet EOF
	{
		while (*st != '\n' && *st)		// search
			st++;

		if ('\n' == *st)				// processing
			*st = '\0';
		else							// == else if ('\0' == *st)
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
