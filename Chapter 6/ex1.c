// ex1.c
#include <stdio.h>

#define SIZE 26

int main (void)
{
	char alphabet[SIZE];
	int index;

	for (index = 0; index < SIZE; index++)
	{
		alphabet[index] = 'a' + index;
		printf("%c ", alphabet[index]);
	}
	putchar('\n');
	
	return 0;
}