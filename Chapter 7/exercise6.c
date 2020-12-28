/* exercise6.c -- Chapter 7  */
#include <stdio.h>

int main (void)
{
	char ch;				// current input character
	char prev;				// previous input character
	int ei_count = 0;		// counter

	prev = '\0';			// any character initialization for prev variable
							// so that the condition is certainly not met
	printf("Enter the text or # to finish the program.\n");
	while ((ch = getchar()) != '#')
	{
		if ('e' == prev && 'i' == ch)
			ei_count++;

		prev = ch;
	}
	printf("The number of occurrences of the \"ei\" sequence is %d.\n", ei_count);

	return 0;
}
