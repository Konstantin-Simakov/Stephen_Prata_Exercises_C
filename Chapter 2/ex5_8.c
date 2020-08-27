/* ex5.c -- (Chapter 2) */
#include <stdio.h>

void br (void);
void ic (void);

int main (void)
{
	br();				/* line 1 */
	printf(", ");
	ic();
	printf("\n");

	ic();				/* line 2 */
	printf("\n");

	br();				/* line 3 */
	printf("\n");

	return 0;
}

void br (void)
{
	printf("Brazilia, Russia");
}

void ic (void)
{
	printf("India, China");
}