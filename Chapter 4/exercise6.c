/* exercise6.c -- Chapter 4 */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char name[30], family[30];
	int length_name, length_family;

	printf("Please, enter your name and surname:\n");
	scanf("%s %s", name, family);

	length_name = strlen(name);
	length_family = strlen(family);

	printf("Your name and family name (1-st line) and character amount for ones:\n");
	printf("%s %s\n", name, family);
	printf("%-*d %-*d\n", length_name, length_name, 		/* remove the signs '-' from the %d specifiers */
		length_family, length_family);						/* and run this program and you'll get the answer to the 1-st task */

	return 0;
}
