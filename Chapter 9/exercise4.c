/* exercise4.c -- Chapter 9 */
#include <stdio.h>

double harmonic_mean(double, double);		// for two numbers

int main(void)
{
	double n1, n2;

	n1 = 1.0;
	n2 = 2.0;

	printf("Harmonic mean of two numbers %.2f and %.2f is %.2f\n", 
		n1, n2, harmonic_mean(n1, n2));
	
	return 0;
}

double harmonic_mean(double x, double y)
{
	return 2.0 / (1.0 / x + 1.0 / y);
}