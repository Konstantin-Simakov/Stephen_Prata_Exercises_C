/* exercise6.c -- Chapter 8 */
#include <stdio.h>
#include <ctype.h>		/* for isspace() */

#define HYPHEN "--------------------------------------------------"

int get_first (void);

int main (void)
{
	int ch;

	printf("This program outputs the first unspace character.\n");
	printf("%s\n", HYPHEN);
	printf("Enter the text (or <Ctrl+D> to finish the program):\n");
	
	while ((ch = get_first()) != EOF)
	{
		putchar(ch);
		putchar('\n');
	}
	printf("The program has been completed.\n");

	return 0;
}

int get_first (void)
{
	int ch;
	
	ch = getchar();
	while (isspace(ch))
		ch = getchar();

	while (getchar() != '\n')
		continue;

	return ch;
}
