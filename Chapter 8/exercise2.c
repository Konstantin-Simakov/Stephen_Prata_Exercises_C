/* exercise2.c -- Chapter 8 */
#include <stdio.h>

#define SPACE 	' '
#define HT 		'\t'
#define NL		'\n'
#define DEL 	127		// tha last character of the standard ASCII endoding
#define NUL		 0		// the first character of the standard ASCII endoding

int main(void)
{
	int ch;
	int count = 0;

	printf("Enter the text (or <Ctrl+D> to finish the program):\n");
	while ((ch = getchar()) != EOF)
	{
		// all is good
		if (ch >= NUL && ch <= DEL)
		{
			switch (ch)
			{
				case NUL: printf("%s %d  ", "^@", ch);
					break;
				case HT: printf("%s %d  ", "\\t", ch);
					break;
				case NL: printf("%s %d\n", "\\n", ch);
						count = -1;									// due to ++count below
					break;
				case SPACE: printf("%s %d  ", "SP", ch);
					break;
				case DEL: printf("%s %d  ", "DEL", ch);
					break;
				default: 
					if (ch < SPACE)
						printf("^%c %d  ", ('A' - 1 + ch), ch);		// ch starts from 1 => 'A' - 1; ^ch == <Ctrl+(ch)>
					else
						printf("%c %d  ", ch, ch);
					break;
			}
			if (++count % 10 == 0 && ch != '\n')
					putchar('\n');
		}
		// error processing
		else
		{
			printf("%c (%d)  ", ch, ch);							// output incorrect character
			while (getchar() != '\n')
				continue;											// (discard the rest of the input string)
			printf(" is incorrect input character. Try again:\n");	// and imform the user
		}															// that this character is invalid
	}
	printf("The program has been completed.\n");

	return 0;
}
