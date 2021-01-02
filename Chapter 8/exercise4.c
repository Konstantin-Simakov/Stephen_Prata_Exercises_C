/* exercise4.c -- Chapter 8 */
#include <stdio.h>
#include <ctype.h>			// for isspace()
#include <stdbool.h>		// for bool, true, false

int main (void)
{
	int ch;						// input character
	int letters = 0;			// number of letters
	int words = 0;				// number of words
	bool word_in = false;		// for word definition

	printf("Enter the text (or <Ctrl+D> to finish the program):\n");
	while ((ch = getchar()) != EOF)
	{
		if (!isspace(ch) && !word_in)
		{
			words++;
			word_in = true;
		}
		else if (isspace(ch) && word_in)
			word_in = false;

		if (!isspace(ch) && !ispunct(ch))
			letters++;
	}
	printf("The average of letters in a word is %.0f\n", (float) letters / words);

	return 0;
}
