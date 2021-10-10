/* exercise6.c -- Chapter 6 */
#include <stdio.h>

int main(void)
{
	int n;			// counter, number
	int a, b;		// limits

	printf("Please enter the limits (2 numbers) of the numbers table: ");
	while (scanf("%d %d", &a, &b) == 2)
	{		
		for (n = a; n <= b; n++)
			printf("%5d %7d %10d\n", n, n * n, n * n * n);

		printf("Please enter the limits (2 numbers) of the numbers table "
			"(or q to exit the program): ");
	}
	printf("Good bye!\n");

	return 0;
}
