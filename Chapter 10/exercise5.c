/* exercise5.c -- Chapter 10 */
#include <stdio.h>
#include "head5.h"		// header file for exercise5.c
						// + you need to compile add_file5.c -> compilation of two files

int main(void)
{
	double ar[SIZE] = {5.2, -9.3, 4.4, 5.5, -6.5, 7.5, 8.1, 0.0};
	double max, min;

	max = biggest(ar, SIZE);
	min = smallest(ar, SIZE);

	printf("The difference between the largest and smallest "
		"values in the array is %.2f\n", difference(max, min));
	
	return 0;
}
