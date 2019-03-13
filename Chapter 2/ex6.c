// ex6.c -- (Chapter 2), (Smiling), working with one function in the other function;
#include <stdio.h>

void smiling (void);

int main (void)
{
	smiling();
	smiling();
	smiling();

	printf("\n");

	smiling();
	smiling();

	printf("\n");

	smiling();

	printf("\n");

	return 0;
}

void smiling (void)
{
	printf("Smiling! ");
}