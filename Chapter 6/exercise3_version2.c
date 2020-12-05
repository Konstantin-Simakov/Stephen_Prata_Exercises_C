/* exercise3_version2.c -- Chapter 6 */
#include <stdio.h>

#define LETTER 'Z'		// to what letter to draw an output; you can change this parameter

int main (void)
{
	int i, j;

	for (i = 0; i < (LETTER - 'A') + 1; i++)
	{
		for (j = 0; j <= i; j++)			// 1 operator
			printf("%c", LETTER - j);
		printf("\n");						// 2 operator
	}

	return 0;
}
