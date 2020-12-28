/* exercise3.c -- Chapter 7 */
#include <stdio.h>

int main (void)
{
	int num;
	int evens = 0;
	int odds = 0;
	int sum_evens = 0;
	int sum_odds = 0;

	printf("Please, enter some integer numbers:\n");		
	scanf("%d", &num);
	while (num != 0)
	{
		if (num % 2 == 0)
		{
			sum_evens += num;
			evens++;
		}
		else
		{
			sum_odds += num;
			odds++;
		}

		scanf("%d", &num);
	}
	printf("Total even numbers sum is %d.\n", sum_evens);
	printf("Average value of all even numbers is %.2f.\n", 
		(float) sum_evens / evens);
	
	printf("Total odd numbers sum is %d.\n", sum_odds);
	printf("Average value of all odd numbers is %.2f.\n", 
		(float) sum_odds / odds);

	return 0;
}
