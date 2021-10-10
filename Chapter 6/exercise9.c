/* exercise9.c -- Chapter 6 */
#include <stdio.h>

double calc(double f1, double f2);

int main(void)
{
	double xf, yf;

	printf("Enter 2 floating numbers (f1 and f2; "
		"or q to exit the program): ");
	while (scanf("%lf%lf", &xf, &yf) == 2)
	{
		printf("(f1 - f2) / (f1 * f2) = %.3f\n", calc(xf, yf));

		printf("Enter the next 2 floating numbers (f1 and f2; "
			"or q to exit the program): ");
	}
	printf("Good bye!\n");

	return 0;
}

double calc(double f1, double f2)
{
	return (f1 - f2) / (f1 * f2);
}
