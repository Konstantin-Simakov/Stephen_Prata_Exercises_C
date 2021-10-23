/* exercise8.c -- Chapter 10 */
#include <stdio.h>

#define SIZE1 7
#define SIZE2 3

void copy_arr(double *, const double *, int);

int main(void)
{
	const double source[SIZE1] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
	double target[SIZE2];
	int i;

	copy_arr(target, source + 3, SIZE2);

	printf("Source array:\n");
	for (i = 0; i < SIZE1; i++)
		printf("%.2f ", source[i]);
	printf("\n");

	printf("Target array:\n");
	for (i = 0; i < SIZE2; i++)
		printf("%.2f ", target[i]);
	printf("\n");
	
	return 0;
}

void copy_arr(double * target, const double * source, int size)
{
	int i;

	for (i = 0; i < size; i++)
		target[i] = source[i];
}
