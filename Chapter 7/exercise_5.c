// exercise_5.c
#include <stdio.h>

int main (void)
{
	char ch;
	unsigned short int period_change, exclam_change;

	period_change = exclam_change = 0;

	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
			case '.':
				putchar('!');
				period_change++;
				break;
			case '!':
				putchar('!');
				putchar('!');
				exclam_change++;
				break;
			default:			// equalent 'else'-operator;!!!
				putchar(ch);
		}
	}
	printf("\nExclamation change amount: %hu, peirod change amount: %hu\n", 
			exclam_change, period_change);
	
	return 0;
}