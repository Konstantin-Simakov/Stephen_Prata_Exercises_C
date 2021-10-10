/* exercise3.c -- Chapter 4 */
#include <stdio.h>

int main(void)
{
	float number_fl = 0.0f;

	printf("Please, enter a float number:\n");
	scanf("%g", &number_fl);					/* or %g */

	printf("OK. Your float number is %+.3f or %+.3e.\n", number_fl, number_fl);

	return 0;
}
