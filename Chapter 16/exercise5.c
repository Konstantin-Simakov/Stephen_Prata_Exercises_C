/* exercise5.c -- Chapter 16 */
#include <stdio.h>
#include <stdlib.h>			/* for rand(), srand() */
#include <time.h>			/* for time() */
#include <stdbool.h>		/* for bool, true, false */

#define SIZE 10
#define ELEMENTS_PER_LINE 8

void random_samples(int ar[], size_t size, int samples);
void init_vda(bool ar[], size_t n);

int main(void)
{
	int array[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	srand((unsigned) time(0));
	random_samples(array, SIZE, 2);
	
	return 0;
}

void random_samples(int ar[], size_t size, int samples)
{
	int s, i, index;
	bool test[size];		/* VDA -- to store the state about whether a given element  */
							/*		  of the array has been used or not 				*/

	for (s = 1; s <= samples; s++)
	{
		printf("Sample %d:\n\n", s);
		init_vda(test, size);

		i = 1;
		while (i <= size)
		{
			index = rand() % size;
			if (test[index])
				continue;
			else
				test[index] = true;

			printf("%3d", ar[index]);
			if (i % ELEMENTS_PER_LINE == 0)
				putchar('\n');
			i++;
		}
		if (i % ELEMENTS_PER_LINE != 1)
			printf("\n\n");
	}
}

void init_vda(bool ar[], size_t n)
{
	int i;

	for (i = 0; i < n; i++)
		ar[i] = false;
}
