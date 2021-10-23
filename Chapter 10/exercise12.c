/* exercise12.c -- Chapter 10 */
#include <stdio.h>

#define MONTHS 12
#define YEARS 	5

// displays rainfall data for each year and returns the average rainfall for a year
float average_year(const float (*ar)[MONTHS], int years);

// displays the average rainfall for each month over five years
float average_months(const float (*ar)[MONTHS], int years);

int main(void)
{
	const float rain[YEARS][MONTHS] = {
		{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
		{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3}, 
		{9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.3, 2.3, 6.1, 8.4}, 
		{7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2}, 
		{7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
	};

	printf("The average rainfall is %.1f for year in inches.\n\n", 
		average_year(rain, YEARS));

	printf("The average rainfall is %.1f for month in inches.\n\n", 
		average_months(rain, YEARS));


	return 0;
}

float average_year(const float (*ar)[MONTHS], int years)
{
	float subtot, total;
	int year, month;

	printf("YEAR 	  RAINFALL (in inches)\n");
	for (year = 0, total = 0.0f; year < years; year++)
	{
		for (month = 0, subtot = 0.0f; month < MONTHS; month++)
			subtot += ar[year][month];

		printf("%d %15.1f\n", 2010 + year, subtot);

		total += subtot;
	}
	printf("\n");

	return total / years;	
}

float average_months(const float (*ar)[MONTHS], int years)
{
	float subtot, total;
	int month, year;

	printf("AVERAGE MONTHLY PRECIPITATION:\n\n");
	printf("Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  ");
	printf("Nov  Dec\n");

	for (month = 0, total = 0.0f; month < MONTHS; month++)
	{
		for (year = 0, subtot = 0.0f; year < years; year++)
			subtot += ar[year][month];

		printf("%-4.1f ", subtot / years);
		
		total += subtot;
	}
	printf("\n\n");

	return total / ((float) years * MONTHS);
}
