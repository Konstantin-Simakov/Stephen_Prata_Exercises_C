// ex10.c -- chapter 6
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int main (void)
{
	int integer[SIZE];
	int i;

	printf("Please, enter the value of integer array:\n");

	for (i = 0; i < SIZE; i++)
		scanf("%d", &integer[i]);
			// == pritnf("\n");
	putchar('\n');		

	for (i = SIZE-1; i >= 0; i--)
		printf("%d ", integer[i]);

	putchar('\n');
	
	return 0;
}