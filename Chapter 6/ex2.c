// ex2.c
#include <stdio.h>

int main (void)
{	
	// const COLUMNS = 5;
	const unsigned char ROWS = 5;

	char ch = '$';
	unsigned char i, k;

	for (i = 0; i < ROWS; i++)
	{
		for (k = 0; k <= i; k++)
			printf("%c", ch);
		putchar('\n');
	}
	
	return 0;
}