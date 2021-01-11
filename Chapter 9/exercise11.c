/* exercise11.c -- Chapter 9 */
#include <stdio.h>

unsigned long long fibonacci (unsigned short n);

int main (void)
{
	unsigned long long res;
	unsigned short num;		// argument of fibonacci()

	printf("Enter the argument of the Fibonacci function:\n");
	while (scanf("%hu", &num) == 1)
	{
		res = fibonacci(num);
		printf("The Fibonacci function value for argument %hu is %llu.\n", 
			num, res);

		printf("Enter the argument of the Fibonacci function "
			"(or q to finish the program):\n");
	}
	printf("The program has been completed.\n");
	
	return 0;
}

unsigned long long fibonacci (unsigned short number)
{
	unsigned long long res;
	unsigned long long prev1, prev2;
	unsigned short count;

	res = prev1 = prev2 = 1;

	for (count = 3; count <= number; count++)
	{
		res = prev2 + prev1;
		prev2 = prev1;
		prev1 = res;
	}

	return res;
}
