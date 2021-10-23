/* support module for exercise10.c */
#include <stdio.h>

void sum_arrs(int * target, int * s1, int * s2, int size_all)
{
	int i;

	for (i = 0; i < size_all; i++)
		target[i] = s1[i] + s2[i];
}

void show_arr(int * ar, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%4d ", ar[i]);
	printf("\n");
}
