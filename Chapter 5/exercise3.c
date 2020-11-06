/* exercise3.c -- Chapter 5 */
#include <stdio.h>

const int WEEK = 7;			// days number in a week

int main (void)
{
	int day, week, left_d;

	printf("The program converts days number "
		"into weeks number and days number.\n");

	printf("Please enter days number (or <= 0 to exit program.)\n");
	scanf("%d", &day);

	while (day > 0)
	{
		week = day / WEEK;
		left_d = day % WEEK;

		printf("%d days are %d weeks and %d days.\n", day, week, left_d);

		printf("Please enter the next days number "
			"(or <= 0 to exit program.)\n");
		scanf("%d", &day);
	}
	printf("That's all. Good bye!\n");

	return 0;
}
