/* exercise1.c -- Chapter 15 */
#include <stdio.h>
#include <string.h>			/* for strlen() */
#include <math.h>			/* for pow() */

int bin_to_decimal (char *);

int main (void)
{
	char * pbin = "1000010";

	printf("bin = %s, decimal number = %d\n", pbin, bin_to_decimal(pbin));
	
	return 0;
}

int bin_to_decimal (char * str)
{
	const int MAX_POWER = strlen(str) - 1;
	int i;
	int res;

	for (res = 0, i = 0; i <= MAX_POWER; i++)
	{
		if ('1' == str[i])
			res += pow(2, MAX_POWER - i);
	}

	return res;
}
