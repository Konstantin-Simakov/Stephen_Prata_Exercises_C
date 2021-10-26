/* exercise3.c -- Chapter 15 */
#include <stdio.h>
#include <limits.h>		/* for CHAR_BIT */

int included_bits(int num);

int main(void)
{
	int num = 077;		/* you can change this value */

	printf("Number: %d\n", num);
	printf("The number of included bits in this number is %d\n", included_bits(num));
	
	return 0;
}

int included_bits(int num)
{
	const static int SIZE = CHAR_BIT * sizeof(int);
	int i, count;

	for (i = 0, count = 0; i < SIZE; i++, num >>= 1)
		if ((num & 0x1) == 0x1)
			count++;

	return count;
}
