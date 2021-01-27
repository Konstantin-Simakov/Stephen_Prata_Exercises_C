/* exercise2.c -- Chapter 10 */
#include <stdio.h>

#define SIZE 5

void copy_arr (double *, double *, int);
void copy_ptr (double *, double *, int);
void copy_ptrs (double *, double *, double *);

int main (void)
{
	double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[SIZE];
	double target2[SIZE];
	double target3[SIZE];
	int i;

	copy_arr(target1, source, SIZE);
	copy_ptr(target2, source, SIZE);
	copy_ptrs(target3, source, source + SIZE);

	printf("The source array:\n");
	for (i = 0; i < SIZE; i++)
		printf("%.1f ", source[i]);
	printf("\n\n");

	printf("The first array copy:\n");
	for (i = 0; i < SIZE; i++)
		printf("%.1f ", target1[i]);
	printf("\n\n");

	printf("The second array copy:\n");
	for (i = 0; i < SIZE; i++)
		printf("%.1f ", target2[i]);
	printf("\n\n");

	printf("The third array copy:\n");
	for (i = 0; i < SIZE; i++)
		printf("%.1f ", target3[i]);
	printf("\n\n");

	return 0;
}

void copy_arr (double * target, double * source, int n)
{
	int i;

	for (i = 0; i < n; i++)
		target[i] = source[i];
}

void copy_ptr (double * target, double * source, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		*target = *source;
		source++;
		target++;
	}
}

void copy_ptrs (double * tar, double * s_begin, double * s_end)
{
	while (s_begin < s_end)
	{
		*tar = *s_begin;
		s_begin++;
		tar++;
	}
}
