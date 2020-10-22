/* exercise1.c -- Chapter 4 */
#include <stdio.h>

int main (void)
{
	char name[25];
	char family[30];

	printf("Please, enter your name and surname:\n");
	scanf("%s %s", name, family);

	printf("Good. You called %s %s.\n", family, name);

	return 0;
}
