/* exercise2_support.c */
#include <stdbool.h>			/* for bool, true, false */
#include <ctype.h>				/* for isdigit() */
#include <string.h>				/* for strcmp(), strlen() */
#include <stdlib.h>				/* for atoi() */
#include "exercise2_head.h"		/* for template of structure, str_digit(), MIN, MAX */

static bool str_digit(const char * str);

int month_sum(const struct months_info * year, int n)
{
	int subtot, i;

	for (subtot = 0, i = 0; i < n; i++)
		subtot += year[i].days;

	return subtot;
}

int calc_month_num(const struct months_info * year, int n, const char * str_month)
{
	int num_month = -1;			/* for error code -- initial value */
	int i;

	if (str_digit(str_month))
		num_month = atoi(str_month);
	else if (strlen(str_month) >= MIN && strlen(str_month) <= MAX)
		for (i = 0; i < n; i++)
			if (strcmp(str_month, year[i].abbrev) == 0 || 
				strcmp(str_month, year[i].name) == 0)
			{
				num_month = year[i].number;
				break;
			}

	return num_month;
}

static bool str_digit(const char * str)
{
	bool is_digit = true;

	while (*str)
		if (!isdigit(*str++))
		{
			is_digit = false;
			break;
		}

	return is_digit;
}
