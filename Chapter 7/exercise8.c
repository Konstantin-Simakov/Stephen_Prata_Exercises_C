/* exercise8.c -- Chapter 7 */
#include <stdio.h>

#define STARS 		"********************************************************************"

#define WAGE_RATE_1	8.75f			// dollars per hour
#define WAGE_RATE_2	9.33f			// dollars per hour
#define WAGE_RATE_3	10.00f			// dollars per hour
#define WAGE_RATE_4	11.20f			// dollars per hour
#define OVERTIME 	1.5f			// over 40 hours per week
// tax rates
#define TAX_RATE_1 	0.15			// tax rate from the first $300
#define TAX_RATE_2 	0.2				// tax rate from the following $150
#define TAX_RATE_3 	0.25			// tar rate from the ramainder (over $450)
// money (dollars) for a week
#define FIRST_SUM	300.0			// (dollars) per week ->
#define SECOND_SUM	450.0			// -> for a both TAX_RATE_2 and TAX_RATE_3

int main(void)
{
	int status;						// for scanf() return value saving
	int choice;
	float wage_rate;				// chosen tax rate
	float hours;					// number of hours worked per week
	double salary = 0.0;			// dirty salary
	double sum_clean = 0.0;			// clean salary
	double tax_rates = 0.0;			// tax rates sum

	// invite
	printf("%s\n", STARS);
	printf("Enter the number corresponding to your desired rate or action:\n");
	printf("1) $%.2f/h  \t\t 2) $%.2f/h\n", WAGE_RATE_1, WAGE_RATE_2);
	printf("3) $%.2f/h  \t\t 4) $%.2f/h\n", WAGE_RATE_3, WAGE_RATE_4);
	printf("5) Exit\n");
	printf("%s\n", STARS);

	status = scanf("%d", &choice);
	while (choice != 5 && status == 1)
	{
		if (choice >= 1 && choice <= 4)
		{
			switch (choice)
			{
				case 1: wage_rate = WAGE_RATE_1;
					break;
				case 2: wage_rate = WAGE_RATE_2;
					break;
				case 3: wage_rate = WAGE_RATE_3;
					break;
				case 4: wage_rate = WAGE_RATE_4;
					break;		// the last break; is optional but it is useful for correct coding
			}
			printf("Enter the number of hours worked per week:\n");
			scanf("%f", &hours);
			if (hours > 0)
			{
				// gross_salary
				salary = wage_rate * hours;
				// tax rates calculating
				if (salary <= FIRST_SUM)
					tax_rates = salary * TAX_RATE_1;
				else if (salary <= SECOND_SUM)
					tax_rates = FIRST_SUM * TAX_RATE_1 
								+ (salary - FIRST_SUM) * TAX_RATE_2;
				else 
					tax_rates = FIRST_SUM * TAX_RATE_1 
								+ (SECOND_SUM - FIRST_SUM) * TAX_RATE_2 
								+ (salary - SECOND_SUM) * TAX_RATE_3;
				// net salary
				sum_clean = salary - tax_rates;
				printf("Gross salary: $%.2f, Tax rates: $%.2f, Net salary: $%.2f\n", 
					salary, tax_rates, sum_clean);				
			}
			else
				printf("Incorrect data input. Try again:\n");
		}
		else
			printf("Incorrect data input. Try again:\n");

		// re-invite
		printf("%s\n", STARS);
		printf("Enter the next number corresponding to your desired rate or action:\n");
		printf("1) $%.2f/h  \t\t 2) $%.2f/h\n", WAGE_RATE_1, WAGE_RATE_2);
		printf("3) $%.2f/h  \t\t 4) $%.2f/h\n", WAGE_RATE_3, WAGE_RATE_4);
		printf("5) Exit\n");
		printf("%s\n", STARS);

		status = scanf("%d", &choice);
	}
	printf("Good bye!\n");

	return 0;
}
