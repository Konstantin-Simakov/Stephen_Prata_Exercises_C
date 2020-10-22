/* exercise2.c -- Chapter 4 */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char name[20];
	int length_string = 0;

	printf("Please, enter your name:\n");
	scanf("%s", name);						/* Then goes <Enter> */

	length_string = strlen(name);

	printf("\n\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("%*s\n", length_string + 3, name);

	return 0;
}
