// exercise4.c -- Chapter 14 
#include <stdio.h>
#include "exercise4_head.h"

int main(void)
{
	struct ssc dates[MEMBERS];
	int stop;

	stop = init_struct_arr(dates, MEMBERS);
	output_struct_arr(dates, stop);
	
	return 0;
}
