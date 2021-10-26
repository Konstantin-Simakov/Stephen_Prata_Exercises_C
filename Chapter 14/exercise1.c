/* exercise1.c -- Chapter 14 */
/* compile with "exercise1_support.c" source file */
#include <stdio.h>				/* for puts(), scanf() */
#include "exercise1_head.h"		/* for template of the structure */

const struct month year[MONTHS] = {
	{.name = "January", .days = 31},
	{.name = "February", .days = 28},
	{.name = "March", .days = 31},
	{.name = "April", .days = 30},
	{.name = "May", .days = 31},
	{.name = "June", .days = 30},
	{.name = "July", .days = 31},
	{.name = "Augest", .days = 31},
	{.name = "September", .days = 30},
	{.name = "October", .days = 31},
	{.name = "November", .days = 30},
	{.name = "December", .days = 31},
};

int main(void)
{
	char mon_name[LNAME];
	int days;

	puts("Enter full name of a month:");
	scanf("%s", mon_name);
	while ((days = total_days(mon_name)) == 0)
	{
		puts("Incorrect month entered. Try again:");
		scanf("%s", mon_name);
	}

	printf("The total days from the beginning of the year\n"
		"to the end of this month is %d.\n", 
			days);				/* use the global structure */
	
	return 0;
}
