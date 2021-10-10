/* exercise1.c -- Chapter 5 */
#include <stdio.h>

const int M_PER_H = 60;		// minutes number in one hour

int main(void)
{
	int min, hour, left_m;

	printf("This program converts minutes number into "
		"hours and minutes number.\n");

	printf("Please enter a minutes number "
		"(or <= 0 for exit program).\n");
	scanf("%d", &min);
	while (min > 0)
	{
		hour = min / M_PER_H;
		left_m = min % M_PER_H;

		printf("%d minutes is %d hours and %d minutes.\n", min, hour, left_m);

		printf("Please enter a minutes number "
			"(or <= 0 for exit program).\n");
		scanf("%d", &min);
	}
	printf("That's all. Good bye!\n");

	return 0;
}
