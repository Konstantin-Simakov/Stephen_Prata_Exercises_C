/* exercise2.c -- Chapter 10 */
#include <stdio.h>

#define SIZE 5

void copy_arr(double *, double *, int);
void copy_ptr(double *, double *, int);
void copy_ptrs(double *, double *, double *);
void show_ar(double *, int n);

int main(void)
{
	double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[SIZE];
	double target2[SIZE];
	double target3[SIZE];

	copy_arr(target1, source, SIZE);
	copy_ptr(target2, source, SIZE);
	copy_ptrs(target3, source, source + SIZE);

	printf("The source array:\n");
	show_ar(source, SIZE);

	printf("The first array copy:\n");
	show_ar(target1, SIZE);

	printf("The second array copy:\n");
	show_ar(target2, SIZE);

	printf("The third array copy:\n");
	show_ar(target3, SIZE);

	return 0;
}

void copy_arr(double * target, double * source, int n)
{
	int i;

	for (i = 0; i < n; i++)
		target[i] = source[i];
}

void copy_ptr(double * target, double * source, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		*target++ = *source++;
		// source++;
		// target++;
	}
}

void copy_ptrs(double * tar, double * s_begin, double * s_end)
{
	while (s_begin < s_end)
	{
		*tar++ = *s_begin++;
		// s_begin++;
		// tar++;
	}
}

void show_ar(double * ar, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%.1f ", ar[i]);
	printf("\n\n");
}
