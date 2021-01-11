/* exercise10.c -- Chapter 9 */
#include <stdio.h>

#define ZERO 48			/* zero in the ASCII table; for alpha-numeric character output */

void to_base_n (int num, int base);

int main (void)
{
	int num, base;

	printf("Enter the number and the radix to which "
		"you want to convert the given number:\n");
	while (scanf("%d %d", &num, &base) == 2)
	{
		printf("%d in 10-ary number system is equal to ", num);
		to_base_n(num, base);
		printf(" in %d-ary number system.\n", base);

		printf("\nEnter the number and the radix to which "
		"you want to convert the given number "
		"(or q to finish the program):\n");
	}
	printf("The program has been completed.\n");

	return 0;
}

void to_base_n (int number, int base)
{
	int res;

	res = number % base;

	if (number >= base)
		to_base_n(number / base, base);
	
	putchar(res + ZERO);
}
