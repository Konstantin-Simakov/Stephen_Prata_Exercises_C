// ex3.c
#include <stdio.h>

#define LETTER_MAX 'A' + 5
#define ROWS 6

int main (void)
{
	char ch;
	int i;

	for (i = 0; i < ROWS; i++)
	{	// there it is done through 'F'-letter, that's wrong!
		// See ex3_2_vers.c for example how to make correct.
		for (ch = LETTER_MAX; ch >= LETTER_MAX - i; ch--)
			printf("%c", ch);
		printf("\n");
	}
	// LETTER_MAX may rechange to constant = 'A' + 5

	return 0;
}