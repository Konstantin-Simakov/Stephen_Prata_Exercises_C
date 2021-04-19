/* exercise12.c -- Chapter 13 */
/* This file is launched ONLY after launching of the 
   "exercise12_support.c" program in this catalog. */
#include <stdio.h>
#include <stdlib.h>		// for exit()

#define ROWS 20
#define COLS 30
#define MAX  41

void init_array_int_from_file (int ar[][COLS], int rows, FILE * fp);
void char_convert (char image[][COLS + 1], int nums[][COLS], int rows);
void arrays_char_to_strings (char ** image_ptr, char ar[][COLS + 1], int rows);
void output_results_in_file (char ** image_ptr, int rows, FILE * fp);
void output_results (char ** image_ptr, int rows);
char * s_gets (char *, int);

int main (void)
{
	int nums[ROWS][COLS];
	char image[ROWS][COLS + 1];
	char * image_ptr[ROWS];
	char fname_src[MAX], fname_trg[MAX];
	FILE * fp_src, * fp_trg;

	puts("Enter the source file name:");
	s_gets(fname_src, MAX);
	if ((fp_src = fopen(fname_src, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open file %s for reading.\n", fname_src);
		exit(EXIT_FAILURE);
	}

	puts("Enter the target file name:");
	s_gets(fname_trg, MAX);
	if ((fp_trg = fopen(fname_trg, "w")) == NULL)
	{
		fprintf(stderr, "Cannot open file %s for writing.\n", fname_trg);
		exit(EXIT_FAILURE);
	}

	init_array_int_from_file(nums, ROWS, fp_src);
	char_convert(image, nums, ROWS);
	arrays_char_to_strings(image_ptr, image, ROWS);
	output_results_in_file(image_ptr, ROWS, fp_trg);
	output_results(image_ptr, ROWS);

	return 0;
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
		else	// if ('\0' == *str)
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

void init_array_int_from_file (int ar[][COLS], int rows, FILE * fp)
{
	int i, j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < COLS; j++)
			fscanf(fp, "%d", &ar[i][j]);
}

void char_convert (char image[][COLS + 1], int nums[][COLS], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			switch(nums[i][j])
			{
				case 0: image[i][j] = ' ';
					break;
				case 1: image[i][j] = '.';
					break;
				case 2: image[i][j] = '\'';
					break;
				case 3: image[i][j] = ':';
					break;
				case 4: image[i][j] = '~';
					break;
				case 5: image[i][j] = '*';
					break;
				case 6: image[i][j] = '=';
					break;
				case 7: image[i][j] = '$';
					break;
				case 8: image[i][j] = '%';
					break;
				case 9: image[i][j] = '#';
					break;
				default: puts("Invalid number is met.");	// For error detect if it exists.
					break;
			}
		}
		image[i][COLS] = '\0';		// The last element for any row of image array is '\0' for strings array generation.
	}
}

void arrays_char_to_strings (char ** image_ptr, char image[][COLS + 1], int rows)
{
	int i;

	for (i = 0; i < rows; i++)
		image_ptr[i] = image[i];
}

void output_results_in_file (char ** image_ptr, int rows, FILE * fp)
{
	int i;

	for (i = 0; i < rows; i++)
	{
		fputs(image_ptr[i], fp);
		putc('\n', fp);
	}
}

void output_results (char ** image_ptr, int rows)
{
	int i;

	for (i = 0; i < rows; i++)
		puts(image_ptr[i]);
}

