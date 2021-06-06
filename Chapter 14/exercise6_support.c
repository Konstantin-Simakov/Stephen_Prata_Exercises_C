/* exercise6_support.c */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "exercise6_head.h"

int init_struct_arr (struct player command[], int num, FILE * fp)
{
	int count;
	int i;
	bool is_same;
	/* ////////////////////////////////////// */
	/* temporary variables corresponding 
	to variables in the structure template */
	int tnumber;
	char tfname[LEN];
	char tlname[LEN];
	int taccept;
	int thit;
	int tpass;
	int trun;
	/* ////////////////////////////////////// */

	count = 0;
	while (count < num)
	{
		if (fscanf(fp, "%d %s %s %d %d %d %d", 
			&tnumber, tfname, tlname, &taccept, &thit, &tpass, &trun) != 7)
				break;

		for (is_same = false, i = 0; i < count; i++)
			if (tnumber == command[i].number)
			{
				command[i].accept += taccept;
				command[i].hit += thit;
				command[i].pass += tpass;
				command[i].run += trun;
				is_same = true;
				break;
			}
		if (is_same)
			continue;

		command[count].number = tnumber;
		strcpy(command[count].fname, tfname);
		strcpy(command[count].lname, tlname);
		command[count].accept = taccept;
		command[count].hit = thit;
		command[count].pass = tpass;
		command[count].run = trun;
		
		count++;
	}

	return count;
}

void init_average (struct player command[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		if (command[i].run != 0)
			command[i].average = (float) (command[i].hit / command[i].run);
}

struct player sum_struct_arr (struct player command[], int n)
{
	int i;
	struct player sum = { 0 };		/* initial values for the structure variable */

	for (i = 0; i < n; i++)
	{
		sum.accept += command[i].accept;
		sum.hit += command[i].hit;
		sum.pass += command[i].pass;
		sum.run += command[i].run;
	}
	if (sum.run != 0)
		sum.average = (float) sum.hit / sum.run;

	return sum;
}

void sort_ascend (struct player command[], int n)
{
	int top, seek;
	struct player temp;

	for (top = 0; top < n - 1; top++)
		for (seek = top + 1; seek < n; seek++)
			if (command[top].number > command[seek].number)
			{
				temp = command[top];
				command[top] = command[seek];
				command[seek] = temp;
			}
}

void output_struct_arr (const struct player command[], int n)
{
	int i;
	char taverage[LEN];		/* temp average -- for string convertion */

	/* table header */
	puts("N\tfname\t\tlname\taccept\thit\tpass\trun\taverage");
	/* table consist */
	for (i = 0; i < n; i++)
	{
		sprintf(taverage, "%.2f", command[i].average);
		printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n", 
			command[i].number, command[i].fname, command[i].lname, 
			command[i].accept, command[i].hit, command[i].pass, 
			command[i].run, (command[i].run != 0) ? taverage : "---");
	}
}

void output_struct_sum (const struct player * psum)
{
	char taverage[LEN];

	sprintf(taverage, "%.2f", psum->average);
	printf("sum:\t\t\t\t");
	printf("%d\t%d\t%d\t%d\t%s\n", 
		psum->accept, psum->hit, psum->pass, psum->run, 
		(psum->run != 0) ? taverage : "---");
}
