// ex7.c -- chapter 6;
#include <stdio.h>

int main (void)
{
	float a, b, xrom;

	printf("Enter two number:\n");

	while (scanf("%f %f", &a, &b) != 0)
	{
		xrom = (a - b) / (a * b);
		printf("%.2f\n\n", xrom);
	}
	
	return 0;
}