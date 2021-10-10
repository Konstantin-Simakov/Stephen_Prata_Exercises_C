/* exercise5.c -- Chapter 3 */
#include <stdio.h>

int main(void)
{
	double sec_year = 3.156e+7;
	short int years = 0;

	printf("Please, enter your old in years: ");
	scanf("%hd", &years);		// assign value to years variable

	sec_year = sec_year * years;

	printf("OK. Your years old is %.3e in second.\n", sec_year);

	return 0;
}
