// exercise_10.c
#include <stdio.h>
#include <stdlib.h>

#define TAX1 0.15
#define TAX2 0.28
#define INC1 17850
#define INC2 23900
#define INC3 29750
#define INC4 14875

int main (void)
{
	int income;
	signed char category;
	double tax_sum = 0.0l;

	printf("Choose your category: (1-4 or \"q\" to exit)\n");
	printf("1) Alone\t\t\t\t2) Head of the family\n"
			"3) Married, joint housekeeping\t\t"
			"4) Married, separate housekeeping\n");

	while (scanf("%hhd", &category) == 1)
	{
		if (category <= 0 || category >= 5)
		{
			printf("You have entered incorrect category. Please enter again: (or \"q\" to exit)\n");
			continue;
		}

		printf("Enter your income: (in dollars) or \"q\" to exit.\n");
		if (scanf("%d", &income) == 1)
		{
			switch (category)
			{
				case 1 : 
					if (income > 0 && income <= INC1)
						tax_sum = TAX1 * income;
					else if (income > INC1)
						tax_sum = TAX1 * INC1 + TAX2 * (income - INC1);
					break;
				case 2 :
					if (income > 0 && income <= INC2)
						tax_sum = TAX1 * income;
					else if (income > INC2)
						tax_sum = TAX1 * INC2 + TAX2 * (income - INC2);
					break;
				case 3 :
					if (income > 0 && income <= INC3)
						tax_sum = TAX1 * income;
					else if (income > INC3)
						tax_sum = TAX1 * INC3 + TAX2 * (income - INC3);
					break;
				case 4 :
					if (income > 0 && income <= INC4)
						tax_sum = TAX1 * income;
					else if (income > INC4)
						tax_sum = TAX1 * INC4 + TAX2 * (income - INC4);
					break;
			}
		}
		printf("Your taxes = $%.2lf dollars.\n", tax_sum);
		printf("Great!\n\n");

		printf("Choose your category: (1-4 or\"q\" to exit)\n");
		printf("1) Alone\t\t\t\t2) Head of the family\n"
			"3) Married, joint housekeeping\t\t"
			"4) Married, separate housekeeping\n");
	}
	
	return 0;
}