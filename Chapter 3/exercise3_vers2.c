/* exercise3_vers2.c -- Chapter 3 */
#include <stdio.h>

void warning (void);

int main (void)
{
	warning();

	return 0;
}

void warning (void)
{
	printf("\a");
	printf("Frightened by the sudden sound Vika screamed:\n");
	printf("\"In the name of all stars, what was that!\"\n");
	// All these print statements can be placed directly into the main() function
}
