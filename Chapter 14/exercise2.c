/* exercise2.c -- Chapter 14 */
#include <stdio.h>
#include <stdlib.h>				/* for exit() */
#include "exercise2_head.h"		/* for template of structure, MONTHS, etc. */

int main(void)
{
	int day;
	char str_month[LEN];
	int num_month, index;		/* the number of a month, initial value == error code for month number */
	int year;
	int sum;
	struct months_info year_info[MONTHS] = {
		{"January",		"Jan", 		31, 	1}, 
		{"February",	"Feb", 		28, 	2}, 
		{"March", 		"Mar", 		31, 	3}, 
		{"April", 		"Apr", 		30, 	4}, 
		{"May", 		"May", 		31, 	5}, 
		{"June", 		"Jun", 		30, 	6}, 
		{"July", 		"Jul", 		31, 	7}, 
		{"Augest", 		"Aug", 		31, 	8}, 
		{"September",	"Sep", 		30, 	9}, 
		{"October", 	"Oct", 		31, 	10}, 
		{"November",	"Nov", 		30, 	11}, 
		{"December",	"Dec", 		31, 	12} 
	};

	printf("Enter the date: day month Year\n");
	if (scanf("%d %20s %d", &day, str_month, &year) != 3)
	{
		printf("\nIncorrect arguments entered.\n");							/* notification about wrong input */
		printf("Correctly: day month year\n");								/* message: how enter correct input */
		printf("Day is an integer number.\n");								/* message: day */
		printf("Month is a string => it can be written as a fullname,\n"	/* message: month */
			"an abbreviation consists of 3 letters or a number.\n");
		printf("Year is some integer number.\n"								/* message: year */
			"(If you want to enter a year BC, enter a negative number for the year.)\n");
		exit(EXIT_FAILURE);													/* exit from the program */
	}

	/* month string processing */
	num_month = calc_month_num(year_info, MONTHS, str_month);

	if (num_month < 1 || num_month > MONTHS)
	{
		printf("Incorrect month entered.\n");
		printf("Month should be from %d to %d as integer\n"
			"(or from Jan to Dec as string).\n", 1, MONTHS);
		exit(EXIT_FAILURE);
	}

	index = num_month - 1;				/* explicit calculation of the current index of the structure array */

	/* takes into account leap years */
	if (year % 4 == 0)
		year_info[1].days++;

	/* the value of the i variable has been saved at the moment from the previous for cycle */
	if (day < 1 || day > year_info[index].days)
	{
		printf("Incorrect days number entered.\n");
		printf("Day number should be from %d to %d for %s for %d %s.\n", 
			1, year_info[index].days, year_info[index].name, 
			year < 0 ? -year : year, 
			year < 0 ? "BC" : "AD");
		exit(EXIT_FAILURE);
	}

	/* calculating part of the program -- core of the program */
	sum = month_sum(year_info, index) + day;

	printf("The total days from the beginning of "
		"this year is %d.\n", sum);

	return 0;
}
