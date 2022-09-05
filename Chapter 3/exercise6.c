/* exercise6.c -- Chapter 3 */
#include <stdio.h>

int main(void)
{
	long double weight_m0 = 3.0e-23L;	// gram
	short int weight_water = 950;		// gram; short int type is allowed
	float quatre_volume = 0.0f;			// (N) - quatre amount

	printf("Please, enter water volume in quatres: ");
	scanf("%f", &quatre_volume);

	/* but here BELOW a long double type is required, since this guarantees the highest accuracy of calculations */
	printf("Number of molecules: %.2Lf\n", quatre_volume * weight_water / weight_m0);		// instead of %LE can be %Le
																							// it is ^^^^^ allowed!!!
	return 0;
}
