// exercise_4.c
#include <stdio.h>

int main (void)
{
	char ch;
	unsigned short int period_count, exclam_count;

	period_count = exclam_count = 0;

	while ((ch = getchar()) != '#')
	{
		if (ch == '.')
		{
			putchar('!');
			++period_count;
		}

		
		else if (ch == '!')
		{
			exclam_count++;
			putchar('!');
			putchar('!');
		}
		else
			putchar(ch);
	}
	printf("%hu exclamation marks' change and %hu period marks' change.\n", exclam_count, period_count);
	
	return 0;
}