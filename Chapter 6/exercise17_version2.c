/* exercise17_version2.c -- Chapter 6
the second version of this program,
with compound interest;
How many years will it be before Chucky has no money left in his account?
*/
#include <stdio.h>

#define DEPOSIT 1000000.0
#define RATE	0.08

int main (void)
{
	const double WITHDRAW = 100000.0;

	int years = 0;
	double sum = DEPOSIT;

	while (sum > 0)
	{
		sum -= WITHDRAW;			// the first action!
		sum += sum * RATE;			// the second action!
		
		years++;
	}
	printf("It will take %d years for Chucky "
		"to have no money left on his account.\n", 
			years);
	printf("---------------------------------------\n");
	printf("The amount on Chucky's account "
		"by this time will be $%.2f.\n", sum);
	printf("This means that in the last year "
		"Chucky will withdraw $%.2f from the account.\n"
		"Until that moment, he will withdraw $%.2f.\n", sum + WITHDRAW, WITHDRAW);

	return 0;
}
