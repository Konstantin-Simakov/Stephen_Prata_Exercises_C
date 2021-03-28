/* support6.c -- Chapter 12 */
/* compile with exercise6.c */
/* compilation in any based on Debian Linux system:
gcc exercise6.c support6.c -o exercise6 -Wall */
/* then launch:
./exercise6 */

#include <stdio.h>		// for printf()

// output the number of occurrences of each of the corresponding numbers
void output_results (int ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d was met %d times\n", i + 1, ar[i]);
}

// zeroing all elements of the array
void zeroing_arr (int ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		ar[i] = 0;
}
