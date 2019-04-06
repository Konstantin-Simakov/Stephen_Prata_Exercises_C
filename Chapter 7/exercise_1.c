// exercise_1.c
#include <stdio.h>

#define SPACE ' '

int main (void)
{
	char ch;
	unsigned int nl, nsp, other;

	nl = nsp = other = 0;

	while ((ch = getchar()) != '#')
	{
		if (ch == '\n')
			nl++;
		else if (ch == SPACE)
			nsp++;
		else
			other++;
	}

	printf("Total: %u end-lines amount, %u spaces amount, %u other characters"
		" (without last # character).\n", nl, nsp, other);
	
	return 0;
}