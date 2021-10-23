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

void ch_col_row(char ch, int row, int col)
{
	int i, j;

	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
			putchar(ch);
		putchar('\n');
	}
}
