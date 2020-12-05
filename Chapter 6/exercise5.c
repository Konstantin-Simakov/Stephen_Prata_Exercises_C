/* exercise5.c -- Chapter 6 */
/* for ASCII characters encoding support */
#include <stdio.h>

#define SPACE ' '	// space character. Yes! Without any semicolons (;)

int main (void)
{
	char cap_let;
	int i, j;
	int rows;		// rows number in the output of the program

	printf("Please enter any capital letter (from A to Z; no lowercase letters; "
		"or # to exit): ");							// only for ASCII characters encoding support!!!
	scanf("%c", &cap_let);

	rows = (cap_let - 'A') + 1;

	for (i = 1; i <= rows; i++)
	{
		for (j = rows - 1; j >= i; j--)
			printf("%c", SPACE);

		for (j = 1; j <= i; j++)
			printf("%c", ('A' + j) - 1);

		for (j = 1; j <= i - 1; j++)
			printf("%c", 'A' + ((i - 1) - j));		// the essence of the algorithm (the most complex cycle)

		printf("\n");
	}

	return 0;
}
