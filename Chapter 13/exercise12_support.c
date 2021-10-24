/* exercise12_support.c -- Chapter 13 */
/* This program creates file that consists of numbers from ROWS rows and COLS coloumns. */
/* This file is launched before launching of the "exercise12.c" program. */
#include <stdio.h>
#include <stdlib.h>		// for exit(), srand(), rand()
#include <time.h>		// for time()

#define ROWS 20
#define COLS 30
#define MAX  41

void f_init_rand_int(int ar[][COLS], int rows, FILE * fp);
char * s_gets(char *, int);

int main(void)
{
	int nums[ROWS][COLS];
	char fname[MAX];
	FILE * fp;

	puts("Enter the file name:");
	s_gets(fname, MAX);
	if ((fp = fopen(fname, "w")) == NULL)
	{
		fprintf(stderr, "Cannot open file %s for writing.\n", fname);
		exit(EXIT_FAILURE);
	}
	f_init_rand_int(nums, ROWS, fp);

	return 0;
}

void f_init_rand_int(int ar[][COLS], int rows, FILE * fp)
{
	int i, j;

	srand((unsigned) time(0));
	for (i = 0; i < rows; i++)
		for (j = 0; j < COLS; j++)
			ar[i][j] = rand() % 10;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
			fprintf(fp, "%d ", ar[i][j]);
		putc('\n', fp);
	}
}

// This function is needed for the file name creating.
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
