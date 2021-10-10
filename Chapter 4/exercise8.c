/* exercise8.c -- Chapter 4 */
#include <stdio.h>

#define GAL_LITR 	3.785		/* litres amount in 1 gallon */
#define MIL_KM		1.609		/* kilometres amount in 1 mile */

int main(void)
{
	float mile = 0.0f, gallon = 0.0f;
/*	float km = 0.0f, litr = 0.0f;
*/	float miles_per_1gal = 0.0f;
	float litr_per_100km = 0.0f;


	printf("Please, enter miles amount and gallon amount:\n");
	scanf("%f %f", &mile, &gallon);

	miles_per_1gal = mile / gallon;

	printf("Miles per gallon amount is %.1f\n", miles_per_1gal);

/*	km = MIL_KM * mile;
	litr = GAL_LITR * gallon;

	printf("kilometres equals %.1f, litres equals %.1f\n", km, litr);
*/
	litr_per_100km = 100 * GAL_LITR / (miles_per_1gal * MIL_KM);

	printf("Litres per 100 kilometres is %.1f\n", litr_per_100km);

	return 0;
}

/* If you will want to uncomment commented out the code upper you are showed 
   kilometres and litres amount. 
*/
