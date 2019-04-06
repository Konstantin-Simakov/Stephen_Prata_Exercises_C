// ex12.c -- Chapter 6
#include <stdio.h>

#define SIZE 8 

unsigned short power (unsigned char n);

int main (void)
{
	unsigned short digit[SIZE];
			////!!!!!
	for (unsigned char i = 0; i < SIZE; ++i)
		digit[i] = power(i);

	printf("Values array:\n");

	unsigned char i = 0;
		// Here you can use "{}" after "do", but don't forget to put a comma here.
	do printf("%hu ", digit[i++]); 
	while (i < SIZE);

	printf("\b;");		// It is optionally.
	putchar('\n');
	
	return 0;
}

unsigned short int power (unsigned char n)
{
	unsigned short pow = 2;
		/* or you can use--> "pow = 1;", but then you must use --> "i = 0;" */
	for (unsigned char i = 1; i <= n; ++i)
		pow *= 2;

	return pow;
}