/* exercise1.c -- Chapter 6 */
#include <stdio.h>

#define SIZE 26			// number of characters in the English alphabet

int main (void)
{
	char alph_eng[SIZE];
	int index;

	for (index = 0; index < SIZE; index++)
		alph_eng[index] = 'a' + index;

	for (index = 0; index < SIZE; index++)
		printf(" %c", alph_eng[index]);
	printf("\n");

	return 0;
}
