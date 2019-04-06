// exercise_7.c -- processes the number of hours worked per week;
#include <stdio.h>
#include <stdlib.h>

#define  REM_DAYS_MONTH		  1.6 / 5.0
#define  NORM_HOURS_WEEK	  40
#define  PROC_HOUR			  1.5
#define  TAX_RATE_FIRST_300   0.15
#define  TAX_RATE_NEXT_150    0.20
#define  TAX_RATE_REST		  0.05

int main (void)
{
	double num_hour, salary, sum_taxes, salary_tax, base_hour_rate;
	signed char action;

	printf("Enter the |HOURS AMOUNT| worked: (or q to exit program)\n");

	while (scanf("%lf", &num_hour) == 1)
	{
		printf("Enter the number corresponding to your preferred salary rate\n"
				"or action: (or \'5\' to exit program)\n");
		printf("1) $8.75/hour\t\t\t2) $9.33/hour\n"
				"3) $10.00/hour\t\t\t4) $11.20/hour\n"
				"5) quit\n");
		while (scanf("%hhd", &action))
		{
			switch (action)
			{
				case 1: base_hour_rate = 8.75;
					goto rpm;
					break;
				case 2: base_hour_rate = 9.33;
					goto rpm;
					break;
				case 3: base_hour_rate = 10.00;
					goto rpm;
					break;
				case 4: base_hour_rate = 11.20;
					goto rpm;
					break;
				case 5: printf("Program is finished.\n");
						_Exit(EXIT_SUCCESS);
				default: 
						printf("You entered incorrect number."
							" Please, enter the number again:\n");
						break;
			}
		}
		rpm:;
		if (num_hour > NORM_HOURS_WEEK)
			salary = NORM_HOURS_WEEK * base_hour_rate + (num_hour - NORM_HOURS_WEEK) * base_hour_rate;
		
		else if (num_hour > 0 && num_hour <= NORM_HOURS_WEEK)
			salary = num_hour * base_hour_rate;
		else 
			continue;
		
		if (salary > 0 && salary <= 300)
		{
			salary_tax = salary - salary * TAX_RATE_FIRST_300;
			sum_taxes = salary * TAX_RATE_FIRST_300;
		}
		else if (salary > 300 && salary <= 300 + 150)
		{
			salary_tax = (300 - 300 * TAX_RATE_FIRST_300) + ((salary - 300) - (salary - 300) * TAX_RATE_NEXT_150);
			sum_taxes = 300 * TAX_RATE_FIRST_300 + (salary - 300) * TAX_RATE_NEXT_150;
		}
		else if (salary > 300 + 150)
		{
			salary_tax = (300 - 300 * TAX_RATE_FIRST_300) + (150 - (150 * TAX_RATE_NEXT_150) + 
				(salary - (300 + 150)) - (salary - (300 + 150)) * TAX_RATE_REST);
			// You can easily transfer to other lines thanks to the free formatting of text in the C language.
			sum_taxes = 300 * TAX_RATE_FIRST_300 + (salary - 300) * TAX_RATE_NEXT_150 + 
				(salary - (300 + 150)) * TAX_RATE_REST;
		}
		printf("Employee salary to week: $%.2lf, and to mounth: $%.2lf\n"
			"Salary with tax deductions: $%.2lf, and to mounth: $%.2lf\n"
			"Tax amount: $%.2lf\n", 
				salary, salary * 4 + REM_DAYS_MONTH * salary ,salary_tax, 
				salary_tax * 4 + REM_DAYS_MONTH * salary_tax, sum_taxes);

		printf("\nEnter the |HOURS AMOUNT| worked: (or q to exit program)\n");
	}
	
	return 0;
}