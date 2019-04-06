// exercise_7.c -- processes the number of hours worked per week;
#include <stdio.h>

#define  NORM_HOURS_WEEK	  40
#define  BAS_HOUR_RATE		  10
#define  PROC_HOUR			  1.5
#define  TAX_RATE_FIRST_300   0.15
#define  TAX_RATE_NEXT_150    0.20
#define  TAX_RATE_REST		  0.05

int main (void)
{
	double num_hour, salary, sum_taxes, salary_tax;

	// salary = 1;

	printf("Enter an employee hours worked: (or q for exit program)\n");
	while (scanf("%lf", &num_hour) == 1)
	{
		if (num_hour > NORM_HOURS_WEEK)
			salary = NORM_HOURS_WEEK * BAS_HOUR_RATE + (num_hour - NORM_HOURS_WEEK) * BAS_HOUR_RATE;
		
		else if (num_hour > 0 && num_hour <= NORM_HOURS_WEEK)
			salary = num_hour * BAS_HOUR_RATE;
		else 
			continue;
		
		if (salary > 0 && salary <= 300)
		{
			salary_tax = salary - salary * TAX_RATE_FIRST_300;
			sum_taxes = salary * TAX_RATE_FIRST_300;
		}
		if (salary > 300 && salary <= 300 + 150)
		{
			salary_tax = (300 - 300 * TAX_RATE_FIRST_300) + ((salary - 300) - (salary - 300) * TAX_RATE_NEXT_150);
			sum_taxes = 300 * TAX_RATE_FIRST_300 + (salary - 300) * TAX_RATE_NEXT_150;
		}
		if (salary > 300 + 150)
		{
			salary_tax = (300 - 300 * TAX_RATE_FIRST_300) + (150 - (150 * TAX_RATE_NEXT_150) + 
				(salary - (300 + 150)) - (salary - (300 + 150)) * TAX_RATE_REST);
			// You can easily transfer to other lines thanks to the free formatting of text in the C language.
			sum_taxes = 300 * TAX_RATE_FIRST_300 + (salary - 300) * TAX_RATE_NEXT_150 + 
				(salary - (300 + 150)) * TAX_RATE_REST;
		}
		printf("Employee salary for week: $%.2lf, and for mounth: $%.2lf\nSalary with tax deductions: $%.2lf\nTax amount: $%.2lf\n", 
			salary, salary * 4 + 1.6 / 5.0 * salary ,salary_tax, sum_taxes);
		printf("\nEnter the next employee data about week salary:\n");
	}
	
	return 0;
}