// matrix_support.c -- function realizations for matrix.h
// Here is supposed 2-dimension array is called matrix. 

#include <stdio.h>
#include <stdlib.h>				// For rand(), malloc(), free(), exit(), EXIT_FAILURE
#include <string.h>				// For memcpy()
#include "matrix.h"				// For prototypes and constants

static const int WIDTH = 5;		// Output width in printf() for element of any matrix		
static const int LOW = -50;		// Low side of a random range 						
static const int HIGH = 50;		// High side of a random range

// Local function prototypes:
static void swap_int(int * a, int * b);
static void swap_ptr(int ** a, int ** b);
static void swap(void * a, void * b, size_t size);

// ----------------------------------------------------------------------------
// Simple functions (function realizations) for a regular matrix:
// ----------------------------------------------------------------------------

void init_regular(int matrix[][COLS], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < COLS; j++)
			matrix[i][j] = rand() % (HIGH - LOW + 1) + LOW;
}

void print_regular(int matrix[][COLS], int rows)
{
	int i, j;

	puts("Regular:");
	for (i = 0; i < rows; i++)
	{
		for (j = 0;j < COLS; j++)
			printf("%*d", WIDTH, matrix[i][j]);
		putchar('\n');
	}
}

// ----------------------------------------------------------------------------
// Mathematic operaions (function realizations) for a regular matrix:
// ----------------------------------------------------------------------------

void swap_rows_regular(int matrix[][COLS], int rows, int row_1, int row_2)
{
	if (row_1 < 1 || row_1 > rows || 
		row_2 < 1 || row_2 > rows)
	{
		fputs("Error: incorrect input rows value for swap_rows_regular().\n", 
			stderr);
		exit(EXIT_FAILURE);
	}

	swap(matrix + (row_1 - 1), matrix + (row_2 - 1), COLS * sizeof(int));
}

void swap_cols_regular(int matrix[][COLS], int rows, int col_1, int col_2)
{
	int i;

	if (col_1 < 1 || col_1 > COLS ||
		col_2 < 1 || col_2 > COLS)
	{
		fputs("Error: incorrect input columns value for swap_cols_regular().\n", 
			stderr);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < rows; i++)
		swap_int(&matrix[i][col_1 - 1], &matrix[i][col_2 - 1]);
}

// ----------------------------------------------------------------------------
// Simple functions (function realizations) for a dynamic matrix: 
// ----------------------------------------------------------------------------

int ** create_dynamic(int rows, int cols)
{
	int i;
	int ** matrix;

	matrix = (int **) malloc(sizeof(int *) * rows);
	for (i = 0; i < rows; i++)
		matrix[i] = (int *) malloc(sizeof(int) * cols);

	return matrix;
}

void init_dynamic(int ** matrix, int rows, int cols)
{
	int i, j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			matrix[i][j] = rand() % (HIGH - LOW + 1) + LOW;
}

void print_dynamic(int ** matrix, int rows, int cols)
{
	int i, j;

	puts("Dynamic:");
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			printf("%*d", WIDTH, matrix[i][j]);
		putchar('\n');
	}
}

void delete_dynamic(int ** arr, int rows, int cols)
{
	int i;

	for (i = 0; i < rows; i++)
		free(arr[i]);
	free(arr);
}

// ----------------------------------------------------------------------------
// Mathematic operaions (function realizations) for a regular matrix:
// ----------------------------------------------------------------------------

void transpose_dynamic(int *** matrix, int * rows, int * cols)
{
	int i, j;

	if (*rows != *cols)
	{
		// Swap row and column values
		swap_int(rows, cols);	

		int ** new_matrix = create_dynamic(*rows, *cols);
		for (i = 0; i < *rows; i++)
			for (j = 0; j < *cols; j++)
				new_matrix[i][j] = (*matrix)[j][i];
		free(*matrix);

		*matrix = new_matrix;
	}
	else
	{
		for (i = 0; i < *rows; i++)
			for (j = i + 1; j < *cols; j++)
				swap_int(&(*matrix)[i][j], &(*matrix)[j][i]);
	}
}

void swap_rows_dynamic(int ** matrix, int rows, int row_1, int row_2)
{
	if (row_1 < 1 || row_1 > rows || 
		row_2 < 1 || row_2 > rows)
	{
		fputs("Error: incorrect input rows value for swap_rows_dynamic().\n", stderr);
		exit(EXIT_FAILURE);
	}

	swap_ptr(matrix + (row_1 - 1), matrix + (row_2 - 1));
}

void swap_cols_dynamic(int ** matrix, int rows, int cols, int col_1, int col_2)
{
	int i;

	if (col_1 < 1 || col_1 > cols ||
		col_2 < 1 || col_2 > cols)
	{
		fputs("Error: incorrect input columns value for swap_cols_dynamic().\n", 
			stderr);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < rows; i++)
		swap_int(&matrix[i][col_1 - 1], &matrix[i][col_2 - 1]);
}

// ----------------------------------------------------------------------------
// Simple functions (function realizations) for a linear matrix: 
// ----------------------------------------------------------------------------

int * create_linear(int rows, int cols)
{	
	return (int *) malloc(sizeof(int) * rows * cols);
}

void init_linear(int * matrix, int rows, int cols)
{
	int i, j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			matrix[i * cols + j] = rand() % (HIGH - LOW + 1) + LOW;
}

void print_linear(int * matrix, int rows, int cols)
{
	int i, j;

	puts("Linear:");
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			printf("%*d", WIDTH, matrix[i * cols + j]);
		putchar('\n');
	}

}

void delete_linear(int * arr, int rows, int cols)
{
	free(arr);
}

// ----------------------------------------------------------------------------
// Helper functions for only this source code file:
// ----------------------------------------------------------------------------

static void swap_int(int * a, int * b)
{
	swap(a, b, sizeof *a);

/*	int temp; 

	temp = *a;
	*a = *b;
	*b = temp;  
*/}

static void swap_ptr(int ** a, int ** b)
{
	swap(a, b, sizeof *a);
	
/*	int * temp;

	temp = *a;
	*a = *b;
	*b = temp;  
*/}

static void swap(void * a, void * b, size_t size)
{
	void * temp = malloc(size);

	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);

	free(temp);
}
