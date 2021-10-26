/* exercise6.c -- Chapter 16 */
#include <stdio.h>
#include <stdlib.h>			/* for qsort() */
#include <string.h>			/* for strcmp() */

#define SIZE 	3
#define STLEN 	40

struct names {
	char first[STLEN];
	char last[STLEN];
};

void show_names(const struct names ar[], int n);
int comp(const void *, const void *);

int main(void)
{
	struct names staff[SIZE] = { 
		{ "Ted", "Luzkov" },
		{ "Berd", "Zedd" },
		{ "Tatarstan", "Luzkov" }
	};

	puts("Source list of names:");
	show_names(staff, SIZE);

	puts("\nSorted list of names:");
	qsort(staff, SIZE, sizeof(struct names), comp);
	show_names(staff, SIZE);

	puts("\nBye!");
	
	return 0;
}

int comp(const void * p1, const void * p2)
{
	const struct names * ps1 = (const struct names *) p1;
	const struct names * ps2 = (const struct names *) p2;
	int res;

	res = strcmp(ps1->last, ps2->last);		/* comparing of last names */
	if (res != 0)
		return res;
	else							/* last names are equal cause compare first names */
		return strcmp(ps1->first, ps2->first);
}

void show_names(const struct names ar[], int n)
{
	int i;

	printf("%-20s %-20s\n", "Last name", "First name");
	for (i = 0; i < n; i++)
		printf("%-20s %-20s\n", ar[i].last, ar[i].first);
}
