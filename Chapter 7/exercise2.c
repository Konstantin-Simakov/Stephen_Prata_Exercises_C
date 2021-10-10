/* exercise2.c -- Chaptrer 7 */
#include <stdio.h>

int main(void)
{
	int count = 1;		// for modulo 8
	char ch;
	int nc = 0;

	while ((ch = getchar()) != '#')
	{
		if (ch != '\n')
		{
			printf("%c %d\t", ch, ch);
			if (count % 8 == 0)
				putchar('\n');
			count++;
		}
		else
			nc++;
	}
	printf("Also it was met %d newline character.\n", nc);

	return 0;
}
