/* exercise3.c -- Chapter 8 */
#include <stdio.h>
#include <ctype.h>		/* for islower(), isupper() */

int main(void)
{
	int ch;
	int lc;				/* lower case characters amount */
	int uc;				/* upper case characters amount */
	int oc;				/* other characters amount */

	lc = uc = oc = 0;

	printf("Enter the text (of <Ctrl+D> to finish the program):\n");
	// character-by-character input
	while ((ch = getchar()) != EOF)		/* '\n' character is counted too */
	{
		if (islower(ch))
			lc++;
		else if (isupper(ch))
			uc++;
		else
			oc++;
	}
	printf("Lower case: %d, upper case: %d, others: %d\n", lc, uc, oc);

	return 0;
}
