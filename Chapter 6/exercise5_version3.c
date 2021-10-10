/* exercise5_version3.c -- Chapter 6 */
#include <stdio.h>

#define SIZE 26 + 1				// 26 english alphabet letters + 1 character '\0' (null-terminated sign (NUL)) 
#define SPACE ' '

int main(void)
{
	int i, j;
	int rows;					// == the number of a letter in an ordered sequence of letters in the English alphabet!
	char alph_eng[SIZE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	printf("Please enter any number from 1 to 26 (number of the alphabet letter; "
		"or q to exit the program): ");
	while (scanf("%d", &rows) == 1)
	{
		for (i = 0; i < rows; i++)				// this is the correct way to process an array [from 0 to SIZE - 1] indexes!!!
		{
			for (j = rows - 1; j >= i + 1; j--)
				printf("%c", SPACE);

			for (j = 0; j <= i; j++)
				printf("%c", alph_eng[j]);

			for (j = 0; j <= i - 1; j++)
				printf("%c", alph_eng[i - 1 - j]);

			printf("\n");		// don't forget to output this character!!!
		}
		printf("Please enter the next any number from 1 to 26 "
			"(number of the alphabet letter; "
			"or q to exit the program): ");
	}
	printf("Good bye!\n");

	return 0;
}
