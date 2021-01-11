/* exercise1.c -- Chapter 9 */
#include <stdio.h>

double min (double a, double b);

int main (void)
{
	double n1, n2;

	printf("Enter two any numbers:\n");
	while (scanf("%lf %lf", &n1, &n2) == 2)
	{
		printf("The smallest of %.2f and %.2f is %.2f\n", 
			n1, n2, min(n1, n2));
		printf("\nEnter two any numbers (q to finish the program):\n");
	}
	printf("The program has been completed.\n");
	
	return 0;
}

double min (double a, double b)
{
	double res = a;

	if (b < res)
		res = b;

	return res;
}
