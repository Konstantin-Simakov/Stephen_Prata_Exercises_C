/* support5.c -- Chapter 12 */
/* compile with exercise5.c */
/* compilation in any based on Debian Linux system:
gcc exercise5.c support5.c -o exercise5 -Wall */
/* then launch:
./exercise5 */

#include <stdio.h>		// for printf(), putchar()
#include <stdlib.h>		// for rand()

void init_ar_rand (int ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		ar[i] = rand() % 10 + 1;		// random number from 1 to 10
}

void sort_decsend_nums (int ar[], int num)
{
	int top, seed;
	int temp;

	for (top = 0; top < num - 1; top++)
		for (seed = top + 1; seed < num; seed++)
			if (ar[top] < ar[seed])
			{
				temp = ar[top];
				ar[top] = ar[seed];
				ar[seed] = temp;
			}
}

// prints each number in the array on a separate corresponding line
void output_ar_line (int ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
		if (ar[i] != ar[i + 1])
			putchar('\n');
	}
}
