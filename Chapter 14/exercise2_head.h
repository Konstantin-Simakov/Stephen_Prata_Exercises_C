/* exercise2_head.h */
#include <stdbool.h>	/* for bool */

#define MONTHS 12
#define LEN (20 + 1)	/* +1 -- for '\0' in the end of a string */
#define LNAME 20
#define ABBREV 5
#define MIN 3			/* min number of characters in the strings in the structure array */
#define MAX 9			/* max number of characters in the strings in the structure array */

struct months_info {
	char name[LNAME];
	char abbrev[ABBREV];
	int days;
	int number;
};

int month_sum(const struct months_info * year, int n);
int calc_month_num(const struct months_info * year_info, int n, const char * str_month);
