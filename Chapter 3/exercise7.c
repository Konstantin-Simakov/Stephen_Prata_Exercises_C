/* exercise7.c -- Chapter 3 */
#include <stdio.h>

int main (void)
{
	float inch_cm = 2.54f;		// constant variable
	float growth_cm = 0.0f;		// ??
	float growth_inch = 0.0f;	// ??

	printf("Please, enter your growth in cantimetres: ");
	scanf("%f", &growth_cm);

	growth_inch = growth_cm / inch_cm;

	printf("Your growth in inches is %.2f (inches).\n", growth_inch);

	return 0;
}