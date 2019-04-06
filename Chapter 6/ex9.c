// ex9.c -- chapter 6; (very big description for this exersises;)
#include <stdio.h>
#include <stdlib.h>

long long int cycle (int low, int up);

int main (void)
{
	int low_lim, up_lim;
	signed char resault;

	printf("Please, enter the next paire of numbers (low and up): "
			"or \"q\" for exit program.\n");
	resault = scanf("%d %d", &low_lim, &up_lim);

	while (resault == 2)
	{
		if (low_lim >= up_lim)
		{
			printf("The work is complited.\n");
			_Exit(EXIT_FAILURE);
		}
		printf("The squares sum of integer numbers from %d to %d = %lld\n", 
			low_lim, up_lim, cycle(low_lim, up_lim));

		printf("Please, enter the next paire of numbers (low and up):\n");
		resault = scanf("%d %d", &low_lim, &up_lim);
	}

	return 0;
}

long long int cycle (int low, int up)
{
	long long int sum;
	int numbers, quatre;

	sum = 0;
	numbers = low;
	
	while (numbers <= up) 
	{
		quatre = numbers * numbers;
		sum += quatre;
		numbers++;
	}

	return sum;
}
