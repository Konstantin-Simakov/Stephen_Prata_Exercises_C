/* exercise1.c -- Chapter 8 */
#include <stdio.h>

int main (void)
{
	int count = 0;

	printf("Enter the text or <Ctrl+D> to finish the program:\n");
	while (getchar() != EOF)
		count++;
	printf("The number of all characters is %d.\n", count);

	return 0;
}
