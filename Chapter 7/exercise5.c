/* exercise5.c -- Chapter 7 */
#include <stdio.h>

#define PERIOD '.'
#define EXCLAM '!'

int main(void)
{
	char ch;
	int period_count = 0;
	int exclam_count = 0;

	printf("Enter the text:\n");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
			case PERIOD : 
				ch = EXCLAM;
				putchar(ch);
				period_count++;
				break;
			case EXCLAM : 
				putchar(ch);
				putchar(ch);
				exclam_count++;
				break;
			default:
				putchar(ch);
				break;				/* after default break is optional */
		}
	}
	printf("The number of substitutions made for a point is %d.\n", 
		period_count);
	printf("The number of substitutions made for one exclamation mark is %d.\n", 
		exclam_count);
	printf("The total number of replacements made is %d.\n", 
		period_count + exclam_count);

	return 0;
}
