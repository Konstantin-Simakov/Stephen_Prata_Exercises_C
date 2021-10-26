/* exercise1_head.h */

#define LNAME  	10
#define ABBREV 	5
#define MONTHS 	12

struct month {
	char name[LNAME];
	char abbrev[ABBREV];
	int days;
	int number;			/* number of the month */
};

extern const struct month year[];		/* the size of link array is optional */

int total_days(const char *);			/* uses the global array upper (named year) */
