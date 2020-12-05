/* exercise12.c -- Chapter 6 */
#include <stdio.h>

int main (void)
{
	int i, lim;
	double sum1;
	double sum2, sum2_1, sum2_2;

	printf("Enter the limit more or equals to 0 (zero) "
		"for the series: ");
	scanf("%d", &lim);
	while (lim > 0)
	{
		sum1 = 0.0;
		sum2 = sum2_1 = sum2_2 = 0.0;		// sum2 variable consists of 2 parts: sum2_1 and sum2_2
											// positive process and negative process

		// the first series
		for (i = 1; i <= lim; i++)
			sum1 += 1.0 / i;

		// the second series
		for (i = 1; i <= lim; i += 2)
			sum2_1 += 1.0 / i;				// this expression converts to double
		for (i = 2; i <= lim; i += 2)
			sum2_2 -= 1.0 / i;				// this expression converts to double
		sum2 = sum2_1 + sum2_2;

		printf("The first series sum is %.3f\n", sum1);
		printf("The second series sum is %.3f\n", sum2);

		printf("Enter the next limit more or equals to 0 (zero) "
			"for the series: ");
		scanf("%d", &lim);
	}
	printf("The program has been completed...\n");

	return 0;
}
