/* sup_mod14.c -- 	module support for exercise14.c; 
					processing arrays by using arrays of variable length;
					all function definitions;
*/
#include <stdio.h>

void input(int rows, int cols,  double ar[rows][cols])
{
	int i, j;

	printf("Enter any values for two-dimension array:\n");
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			scanf("%lf", &ar[i][j]);

	printf("OK. You have filled the entire array.\n");
}

double average(int n, const double ar[n])
{
	int i;
	double sum = 0.0;

	for (i = 0; i < n; i++)
		sum += ar[i];

	return sum / n;
}

double average_all(int rows, int cols, const double ar[rows][cols])
{
	int i, j;
	double sum = 0.0;

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			sum += ar[i][j];

	return sum / ((double) cols * rows);
}

// one test is known to be false for array element ar[0][0]
double biggest(int rows, int cols, const double ar[rows][cols])
{
	int i, j;
	double max = ar[0][0];

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			if (max < ar[i][j])
				max = ar[i][j];

	return max;
}

void show_results(int rows, int cols, const double ar[rows][cols])
{
	int i, j;

	printf("Array consists %dx%d values of double:\n", rows, cols);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			printf("%.2f ", ar[i][j]);
		putchar('\n');
	}

	printf("Averages:\n");
	for (i = 0; i < rows; i++)
		printf("array[%d] (line %d) = %.2f\n", i, i, average(cols, ar[i]));
	
	printf("Average value for all elements is %.2f\n", average_all(rows, cols, ar));
	printf("The biggest value from all elements is %.2f\n", biggest(rows, cols, ar));
}
