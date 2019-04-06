// ex16.c -- Chapter 6;
#include <stdio.h>

int main (void)
{
	const float PER_YEARS = 0.05;

	float win = 1e6;
	signed char years = 0;

	while (win > 0)
	{
		win += win * PER_YEARS;
		win -= 1e5;
		years++;
	}

	printf("Chucky will have no money left in %hd years.\n", years);
	
	return 0;
}