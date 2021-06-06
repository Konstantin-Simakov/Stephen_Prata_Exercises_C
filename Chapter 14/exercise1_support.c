/* exercise1_support.c */
/* compile with "exercise1_support.c" source file */

#include "exercise1_head.h"		/* here is the global array named year */
#include <string.h>				/* for strcmp(), strchr() */

int total_days (const char * str)
{
	int sum, i, j;

	for (sum = 0, i = 0; i < MONTHS; i++)
		if (strcmp(str, year[i].name) == 0)
		{
			for (j = 0; j <= i; j++)
				sum += year[j].days;
			break;
		}

	return sum;
}
