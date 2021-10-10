/* exercise7.c -- Chapter 7 */
#include <stdio.h>

#define WAGE_RATE	10.0			// per hour
#define OVERTIME 	1.5f			// over 40 hours per week ratio
#define NORM_H_W	40				// normal number of hours per week
// tax rates
#define TAX_RATE1 	0.15			// tax rate from the first $300
#define TAX_RATE2 	0.2				// tax rate from the following $150
#define TAX_RATE3 	0.25			// tar rate from the ramainder (over $450)
// money (dollars) for a week
#define FIRST_SUM	300
#define SECOND_SUM	450				// for a both TAX_RATE2 and TAX_RATE3

int main(void)
{
	float hours;					// number of hours worked per week
	double salary = 0.0;			// dirty salary
	double sum_clean = 0.0;			// clean salary
	double taxrates = 0.0;			// tax rates sum

	printf("Enter the number of hours worked per week ");
	printf("(or q to exit the program):\n");
	while (scanf("%f", &hours) == 1)
	{
		if (hours > 0)
		{
			if (hours > NORM_H_W)
				hours *= OVERTIME;		
			// gross_salary
			salary = WAGE_RATE * hours;
			// tax rates calculating
			if (salary <= FIRST_SUM)
				taxrates = salary * TAX_RATE1;
			else if (salary <= SECOND_SUM)
				taxrates = FIRST_SUM * TAX_RATE1 
							+ (salary - FIRST_SUM) * TAX_RATE2;
			else 
				taxrates = FIRST_SUM * TAX_RATE1 
							+ (SECOND_SUM - FIRST_SUM) * TAX_RATE2 
							+ (salary - SECOND_SUM) * TAX_RATE3;
			// net salary
			sum_clean = salary - taxrates;

			printf("Gross salary: $%.2f, Tax rates: $%.2f, Net salary: $%.2f\n", 
				salary, taxrates, sum_clean);
		}
		else
			printf("Incorrect data input. Try again:\n");

		printf("Enter the next number of hours worked per week ");
		printf("(or q to exit the program):\n");
	}
	printf("Good bye!\n");

	return 0;
}
