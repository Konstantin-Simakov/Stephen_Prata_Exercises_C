/* exercise8.c -- Chapter 5 */
#include <stdio.h>

int main (void)
{
	int first, second, modulo;

	printf("This program calculates the results of modulo division.\n");

	printf("Please enter an integer that will serve as the second operand "
		"(constant value): ");
	scanf("%i", &second);
	
	printf("Now enter the first operand: ");
	scanf("%i", &first);

	while (first > 0)
	{
		modulo = first % second;
		printf("%i %% %i equals %d\n", first, second, modulo);

		printf("Please enter the next number for the first operand "
			"(<= 0 to exit program): ");
		scanf("%i", &first);
	}
	printf("Done\n");

	return 0;
}
