/* exercise7.c -- Chapter 6 */
#include <stdio.h>
#include <string.h>

#define SIZE 100		// (just in case)

int main(void)
{
	char str[SIZE];		// array initialization
	int index, len_str_i;

	printf("Please enter an word: ");
	while (scanf("%s", str) == 1)
	{
		len_str_i = strlen(str) - 1;

		for (index = len_str_i; index >= 0; index--)
			printf("%c", str[index]);
		printf("\n");

		printf("Please enter an word (or EOF to exit program): ");
		printf("\n");	// EOF don't generate '\n' after its input
	}
	printf("Good bye!\n");

	return 0;
}
