/* exercise5.c -- Chapter 12 */
/* compile with support5.c */
/* compilation in any based on Debian Linux system:
gcc exercise5.c support5.c -o exercise5 -Wall */
/* then launch:
./exercise5 */
/* stdio.h header file here isn't required */
#include <stdlib.h>		// for srand()
#include <time.h>		// for time()
#include "head5.h"

int main(void)
{
	int nums[SIZE];

	srand((unsigned) time(0));		// initialize seed for rand() every second
	init_ar_rand(nums, SIZE);

	sort_decsend_nums(nums, SIZE);
	output_ar_line(nums, SIZE);
	
	return 0;
}
