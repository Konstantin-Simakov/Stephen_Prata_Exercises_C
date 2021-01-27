/* exercise11.c -- Chapter 10 */
#include <stdio.h>

#define COLS 5
#define ROWS 3

void show_arr (const int (*ar)[COLS], int rows);
void doubling_arr (int ar[][COLS], int rows);

int main (void)
{
	int array[ROWS][COLS];
	int i, j;

	// any initialization of array above
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++)
			array[i][j] = i * i + j * j;

	show_arr(array, ROWS);
	doubling_arr(array, ROWS);
	show_arr(array, ROWS);

	printf("The program has been completed.\n");
	
	return 0;
}

void show_arr (const int ar[][COLS], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
			printf("%4d ", ar[i][j]);
		// printf("\n");
	}
	printf("\n");
}

void doubling_arr (int (*ar)[COLS], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < COLS; j++)
			ar[i][j] *= 2;
}
