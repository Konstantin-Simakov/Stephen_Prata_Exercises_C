// exercise_6.c -- In fact, it was an easy program.
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main (void)
{
	char ch_prev, ch;
	unsigned short int ei_count = 0;

	ch_prev = 'e';
	while ((ch = getchar()) != '#')		
	{
		if (ch == 'i' && ch_prev == 'e')
			ei_count++;

		ch_prev = ch;
	}
	printf("The \"ei\" sequences amount: %hu\n", ei_count);
	
	return 0;
}