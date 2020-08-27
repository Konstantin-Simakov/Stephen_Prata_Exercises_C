#include <stdio.h>

float inch_to_cm (float);

int main (void)
{
	float inches;
	float cm;

	printf("This program translate inches into cm. "
		"Please, enter inches amount:\n");
	while (scanf("%f", &inches) == 1)
	{
		cm = inch_to_cm(inches);
		printf("%.2f inches is equal %.2f cantimetres.\n", inches, cm);
		printf("Enter \"q\" for quit from this program or "
			"enter inches amount:\n");
	}
	puts("Program is finished.");

	return 0;
}

float inch_to_cm (float inches)
{
	return inches * 2.54;
}