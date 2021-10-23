/* exercise4.c -- Chapter 10 */
#include <stdio.h>

int big_index(double * ar, int n);

int main(void)
{
	double ar[] = {2.0, 5.0, 3.5, -4.8, 5.2, 0.1, 10.9, 11.0};

	printf("The biggest index of the array is %d\n", 
		big_index(ar, sizeof ar / sizeof ar[0]));	
	
	return 0;
}

int big_index(double * ar, int n)
{
	int i;
	int max_i = 0;
	double big_val = ar[0];

	for (i = 1; i < n; i++)
		if (big_val < ar[i])
		{
			big_val = ar[i];
			max_i = i;
		}

	return max_i;
}
