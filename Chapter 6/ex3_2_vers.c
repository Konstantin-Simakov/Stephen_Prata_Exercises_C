// ex3_2_vers.c -- 2 version of ex3.c; through arrays,
// that's very beutiful.
#include <stdio.h>

#define SIZE 6

int main (void)
{
	char ch;
	int i, j;
	char lets[SIZE];

	for (i = 0; i < SIZE; i++)	/* initialization of array */
		lets[i] = 'A' + i;
	///////////////////////////
	for (i = 0; i < SIZE; i++)	/* main calculations */
	{
		for (j = 0; j <= i && lets[SIZE-1] >= lets[SIZE-1-j]; j++) //<-4)
		{
			ch = lets[SIZE-1-j]; //<-3), there also may use while-cycle;
			printf("%c", ch);
		}
		printf("\n");
	}
	
	return 0;
}