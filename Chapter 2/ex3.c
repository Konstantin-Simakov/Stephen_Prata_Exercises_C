// ex3.c -- without leap day;
#include <stdio.h>

int main(void)
{
	// instead age = 23 may be written any other number;
	int age, num_day;

	age = 23;

	num_day = age * 365;

	printf("Your age (in days) = %d", num_day);
	
	return 0;
}
