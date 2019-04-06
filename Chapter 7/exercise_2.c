// exercise_2.c
#include <stdio.h>

#define   SPACE   ' '
#define   TAB	  '\t'
#define   END	  '\n'

int main (void)
{
	char ch;
	unsigned count = 0;

	printf("Enter any characters or # for the end program.\n\n");

	while ((ch = getchar()) != '#')
	{

		if (ch != '\n')
		{
			++count;
			switch (ch)
			{
				case SPACE:
					printf("%-5s %-5d ", "space", ch);
					break;
				case TAB:
					printf("%-5s %-5d ", "\\t", ch);
					break;		
				default:
					printf("%c %-5d ", ch, ch);
					if (count % 8 == 0)
						putchar(END);
					break;				
			}
		}
		else
			printf("\n\n");

	}
	
	return 0;
}