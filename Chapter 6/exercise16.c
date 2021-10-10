/* exercise16.c -- Chapter 6
This is the purpose of the program (below).
How long will it take for the amount in Deirdre's account to exceed
the amount in Daphne's?
*/
#include <stdio.h>

#define DEPOSIT 			100.0f		// dollars (without any semicolons)
#define RATE_DAPHNE			0.1			// Daphne's percentage rate
#define RATE_DEIRDRE		0.05		// Deirdra's percentage rate

int main(void)
{
	int years = 0;
	float sum_daphne = DEPOSIT;
	float sum_deirdre = DEPOSIT;

	while (sum_deirdre <= sum_daphne)
	{
		sum_daphne += DEPOSIT * RATE_DAPHNE;
		sum_deirdre += sum_deirdre * RATE_DEIRDRE;
		
		years++;
	}
	printf("The amount of time it will take for "
		"the amount in Deirdre's account to exceed the amount on Daphne's "
		"is %d years.\n", years);
	
	printf("At this point, the amount on Deirdre's account will be $%3.2f, "
		"the amount on Daphne's account will be $%3.2f.\n", 
		sum_deirdre, sum_daphne);

	return 0;
}
