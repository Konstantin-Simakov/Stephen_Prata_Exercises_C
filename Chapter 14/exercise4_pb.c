// exercise4_pb.c -- Chapter 14 
#include <stdio.h>
#include "exercise4_pb_head.h"

int main (void)
{
	struct ssc dates[MEMBERS];
	int stop;
	int i;

	stop = init_struct_arr(dates, MEMBERS);

	for (i = 0; i < stop; i++)
		output_struct(dates[i]);
	
	return 0;
}
