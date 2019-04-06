// ex11.c -- (Chapter 6);
#include <stdio.h>
#include <stdlib.h>

long double sum_seq (int kiss, long double pr);
long double subtract_seq (int k, long double p);

int main (void)
{
	int sign_sum;
/*	float prisv = 1.0;	// Try int
*/
	printf("Please enter one of the digital number: 20, 100, 500 (or \"q\" for exit program):\n"
			"(Please, DON'T input number < or = 1)\n");
	
	while (scanf("%d", &sign_sum) == 1) {
		if (sign_sum < 2) {
			printf("The work is interrupted.\n");
			_Exit(EXIT_FAILURE);
		}
						// "prisv" will change; NO!!! NO CHANGE!!! I'm sorry.
				// or it could be "a = sum_seq(sign_sum, prisv);"
		printf("This infinite sequence converges to %Lf for sum and %Lf for subtract.\n", sum_seq(sign_sum, 1.0), subtract_seq(sign_sum, 1.0));
		printf("Please enter one of the number: 20, 100 or 500.\n");
	}
	
	return 0;
}

long double sum_seq (int k, long double p)
{
	// Please, watch if it need use float instead int for "n"-variable!!!
	double n;

	for (n = 2.0; n <= k; n++)
		p = p + (1.0 / n);	// !!!;

	return p;
}

long double subtract_seq (int k, long double p)
{
	// Please, watch if it need use float instead int for "n"-variable!!!
	double n;

	for (n = 2.0; n <= k; n++)
		p = p - (1.0 / n);	// !!!;

	return p;
}