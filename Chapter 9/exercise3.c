/* exercise3.c -- Chapter 9 */
#include <stdio.h>

#define ROWS 5
#define COLS 3

void ch_col_row(char, int, int);

int main(void)
{
	char ch;

	printf("Enter a character:\n");
	ch = getchar();
	putchar('\n');

	ch_col_row(ch, ROWS, COLS);
	
	return 0;
}

void ch_col_row(char ch, int rows, int cols)
{
	int i, j;

	for (i = 1; i <= rows; i++)
	{
		for (j = 1; j <= cols; j++)
			putchar(ch);
		putchar('\n');
	}
}
