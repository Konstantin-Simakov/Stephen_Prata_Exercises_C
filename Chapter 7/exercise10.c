// exercise10.c -- Chapter 7 
// calculation of the tax amount
#include <stdio.h>

#define STARS 	"******************************************************************************"
// tax rates, in persentages / 100.0
// i.e.  in factions
#define TAX_RATE_1		0.15		// up to a given amount
#define TAX_RATE_2		0.28		// after a given amount
// categories, in dollars
#define SINGLE 			17850
#define FAMILY_HEAD		23900
#define JOINT			29750		// married, joint housekeeping	
#define SEPARATE		14875		// married, separate housekeeping

int main(void)
{
	int status;						// for scanf() status saving
	int category;
	int tarrif;
	double income;					// taxable income
	double tax_amount;

	// invite
	printf("%s\n", STARS);
	printf("Enter the category (from 1 to 4) or press 5 to finish the program:\n");
	printf("1) Single  \t\t\t\t 2) Head of the family\n");
	printf("2) Married, joint housekeeping\t\t 3) Married, separate housekeeping\n");
	printf("5) Exit\n");
	printf("%s\n", STARS);
	// data input
	status = scanf("%d", &category);
	while (category != 5 && status == 1)
	{
		if (category >= 1 && category <= 4)
		{
			switch (category)
			{
				case 1: tarrif = SINGLE;
					break;
				case 2: tarrif = FAMILY_HEAD;
					break;
				case 3: tarrif = JOINT;
					break;
				case 4: tarrif = SEPARATE;
					break;
			}
			printf("Enter taxable income:\n");
			printf("$%s%s", "________", "\b\b\b\b\b\b\b\b");
			scanf("%lf", &income);
			if (income > 0)
			{
				// tax rates sum calculating
				if (income <= tarrif)
					tax_amount = TAX_RATE_1 * income;
				else
					tax_amount = TAX_RATE_1 * tarrif + (income - tarrif) * TAX_RATE_2;
				printf("The tax amount will be $%.2f.\n", tax_amount);
			}
			else
				printf("Incorrect input data. Try again:\n");
		}
		else
			printf("Incorrect input data. Try again:\n");

		// re-invite
		printf("%s\n", STARS);
		printf("Enter the next category (from 1 to 4) or press 5 to finish the program:\n");
		printf("1) Single  \t\t\t\t 2) Head of the family\n");
		printf("2) Married, joint housekeeping\t\t 3) Married, separate housekeeping\n");
		printf("5) Exit\n");
		printf("%s\n", STARS);
		// the next data input
		status = scanf("%d", &category);
	}
	printf("Good bye!\n");

	return 0;
}
