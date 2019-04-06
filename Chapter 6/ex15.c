// ex15.c
#include <stdio.h>

int main (void)
{
	const float EASY_PER_DAFNA = 0.1;
	const float DiF_PER_DEiRA = 0.05;

	float sum_deidra;
	float sum_dafna = sum_deidra = 100.0;	

	float k;
	k = sum_dafna * EASY_PER_DAFNA;

	unsigned short years;	// The number of years cannot be negative  =>  unsigned;
	years = 0;				// We use unsigned short data type because the number of years won't surpass MAX 
							// value of this type;
	do { 
		sum_dafna += k;
		sum_deidra += sum_deidra * DiF_PER_DEiRA;
		years++;
	} 
	while (sum_dafna >= sum_deidra);

	printf("Deposit amount of Dafna: $%.2lf dollars. And deposit amount of Deidra: $%.2lf dollars.\n"
		"And years amount = %hu\n", sum_dafna, sum_deidra, years);

	return 0;
}