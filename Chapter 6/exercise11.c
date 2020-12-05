/* exercise11.c -- Chapter 6 */
#include <stdio.h>

#define SIZE 8

int main (void)
{
	int integer[SIZE];
	int i;

	printf("Please enter 8 values of integers: ");
	for (i = 0; i < SIZE; i++)
		scanf("%d", &integer[i]);

	printf("In reverse order: ");
	for (i = SIZE - 1; i >= 0; i--)
		printf("%d ", integer[i]);
	printf("\n");

	return 0;
}
