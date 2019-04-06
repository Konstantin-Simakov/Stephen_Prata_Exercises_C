// ex13.c -- Chapter 6
// We are realizing 1-st way;
// There will be the second way at the bottom;
#include <stdio.h>

#define SIZE 8

int main (void)
{
	double mas1[SIZE], mas2[SIZE];
	double a;
	int i, j;

	i = 0;		// Checking, if you won't redefenition "i"; NO!!! Here is need nothing to make!!! OK.
				// Check instead for-cycle; (for a short time);

	printf("Please, enter 8 numbers in the double type"
			" (enter through the space):\n");
	
	do {
		scanf("%lf", &a);
		mas1[i++] = a;

	} while (i < SIZE);
	
	mas2[0] = 0.0;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j <= i; j++)
			mas2[i] += mas1[j];
	}
	
	printf("\nThe value arrays (for beginner the first, then the second):\n\n");

	for (i = 0; i < SIZE; ++i)		
		printf("%.3lf ", mas1[i]);
	putchar('\n'); 
	putchar('\n');
	
	for (i = 0; i < SIZE; i++)
		printf("%.3lf ", mas2[i]);
	putchar('\n');
	putchar('\n');

	return 0;
}
		// The second way:
/* Or!!! May be another variant (how to realize 2-nd array):
	for (i = 0; i < SIZE; ++i) {
		mas2[i] = mas2[i-1] + mas1[i];
	}

	And yet! There is NO diferent, if you use "i++" or "++i;" in this context.
*/