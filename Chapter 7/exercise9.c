/* exercise9.c -- Chapter 7 */
#include <stdio.h>
#include <stdbool.h>				// for bool variable

void prime_nums (unsigned upper);	// outputs all prime numbers less than or equal to the given one

int main (void)
{
	int upper;						// input data

	printf("Enter a positive integer number "
		"(or q to finish the program):\n");
	while (scanf("%d", &upper) == 1)
	{
		printf("All primes up to this number:\n");
		prime_nums(upper);

		printf("Enter the next positive integer number "
			"(or q to finish the program):\n");
	}
	printf("Good bye!\n");

	return 0;
}

void prime_nums (unsigned upper)
{
	unsigned num = 2;
	unsigned div;
	bool is_prime;

	while (num <= upper)
	{
		is_prime = true;			// initially the flag is set to true...
	
		for (div = 2; (div * div) <= num; div++)
			if (num % div == 0)		// if at least 1 divisor was found for the number num,
				is_prime = false;	// then such a number is not prime
		
		if (is_prime)				// if the number is prime
			printf("%d\t", num);	// output this number

		num++;
	}
	putchar('\n');
}
