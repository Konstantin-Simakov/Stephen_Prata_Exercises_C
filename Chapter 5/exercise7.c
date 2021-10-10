/* exercise7.c -- Chapter 7 */
#include <stdio.h>

double cube(double fl);			// prototype for my own function

int main(void)
{
	double num, res;

	printf("This program calculates a cube of some number.\n");

	printf("Please enter some number:\n");
	scanf("%lf", &num);			// %lf -- for double type for scanf() function!!!

	res = cube(num);

	printf("%.2f cubed is %.3f\n", num, res);

	return 0;
}

double cube(double fl)
{
	double res;

	res = fl * fl * fl;

	return res;
}
