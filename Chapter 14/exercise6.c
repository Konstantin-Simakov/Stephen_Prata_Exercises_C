/* exercise6.c -- Chapter 14 */
#include <stdio.h>
#include <stdlib.h>					/* for exit, EXIT_FAILURE */
#include "exercise6_head.h"

int main (void)
{
	struct player command[PLAYERS] = { 0 };
	struct player sum;
	FILE * fp;
	int stop;

	if ((fp = fopen("softball", "r")) == NULL)
	{
		fputs("Couldn't read file \"softball\".\n", stderr);
		exit(EXIT_FAILURE);
	}

	stop = init_struct_arr(command, PLAYERS, fp);
	init_average(command, stop);
	sort_ascend(command, stop);
	output_struct_arr(command, stop);
	sum = sum_struct_arr(command, stop);
	output_struct_sum(&sum);
	
	fclose(fp);
	
	return 0;
}
