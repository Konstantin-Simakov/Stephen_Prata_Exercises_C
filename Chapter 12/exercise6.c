/* exercise6.c -- Chapter 12 */
/* compile with support6.c */
/* compilation in any based on Debian Linux system:
gcc exercise6.c support6.c -o exercise6 -Wall */
/* then launch:
./exercise6 */
#include <stdio.h>
#include <stdlib.h>					// for rand(), srand()
#include "head6.h"					// for prototypes of according functions which are used in this file

int main(void)
{
	int ar[SIZE] = { 0 };			// seed initialization of all elements of the array to zeros
	int i;
	int r;
	int s;							// for seed of the srand()
	int random;
	unsigned value;					// for srand()

	printf("Enter up to %d different positive seed (or q to finish).\n", SIZE);
	for (s = 0; s < NUMS; s++)
	{
		printf("\nIteration %d\n", s + 1);
		
		if (scanf("%u", &value) != 1)
		{
			puts("Entered incorrect value!");
			break;
		}

		srand(value);							// for SIZE different values -- alghorithm below will work
		for (r = 0; r < GENERATE; r++)
		{
			random = rand() % SIZE + 1;	// SIZE == n (random = rand() % n + m;)
			for (i = 0; i < SIZE; i++)
				if (i + 1 == random)
				{
					ar[i]++;
					break;
				}
		}
		output_results(ar, SIZE);
		zeroing_arr(ar, SIZE);					// for the next loop iteration
	}
	printf("\nEntered %d correct values.\n", s);
	puts("The program has been completed.");
	
	return 0;
}
