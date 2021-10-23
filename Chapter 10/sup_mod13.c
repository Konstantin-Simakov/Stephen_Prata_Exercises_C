/* sup_mod13.c -- 	module support for exercise13.c; 
					processing arrays in the traditional way in the C language;
					all function definitions;
*/
#include <stdio.h>
#include "head13.h"

void input(double ar[][COLS], int rows)
{
	int i, j;

	printf("Enter any values for two-dimension array:\n");
	for (i = 0; i < rows; i++)
		for (j = 0; j < COLS; j++)
			scanf("%lf", &ar[i][j]);

	printf("OK. You have filled the entire array.\n");
}

double average(const double ar[], int n)
{
	int i;
	double sum = 0.0;

	for (i = 0; i < n; i++)
		sum += ar[i];

	return sum / n;
}

double average_all(const double ar[][COLS], int rows)
{
	int i, j;
	double sum = 0.0;

	for (i = 0; i < rows; i++)
		for (j = 0; j < COLS; j++)
			sum += ar[i][j];

	return sum / ((double) COLS * rows);
}

// one test is known to be false for array element ar[0][0]
double biggest(const double ar[][COLS], int rows)
{
	int i, j;
	double max = ar[0][0];

	for (i = 0; i < rows; i++)
		for (j = 0; j < COLS; j++)
			if (max < ar[i][j])
				max = ar[i][j];

	return max;
}

void show_results(const double ar[][COLS], int rows)
{
	int i, j;

	printf("Array consists %dx%d values of double:\n", rows, COLS);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
			printf("%.2f ", ar[i][j]);
		putchar('\n');
	}

	printf("Averages:\n");
	for (i = 0; i < rows; i++)
		printf("array[%d] (line %d) = %.2f\n", i, i, average(ar[i], COLS));
	
	printf("Average value for all elements is %.2f\n", average_all(ar, rows));
	printf("The biggest value from all elements is %.2f\n", biggest(ar, rows));
}
