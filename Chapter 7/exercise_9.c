// divisors.c
#include <stdio.h>
#include <stdbool.h>

int main (void)
{
	unsigned long limit, prime, num;
	bool isPrime;

	printf("Enter the digital number for analyze; ");
	printf("For ending enter q\n");

	while (scanf("%lu", &limit) == 1)
	{
		printf("This is primary number:\n");

		for (num = 2; num <= limit; num++)
		{
			isPrime = true;
			// while we haven't in the cycle to default: isPrime == true;
			for (prime = 2; prime * prime <= num; prime++)
				if (num % prime == 0)
					isPrime = false;

			if (isPrime)
				printf("%lu ", num);
		}
		printf("\nEnter the next digital number for analyze; ");
		printf("For ending enter q\n");
	}
	
	return 0;
}