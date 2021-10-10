/* exercise4.c -- Chapter 3 */
#include <stdio.h>

// this program is not large!!!
int main(void)
{
	float num = 0.0f;		// <<< max fast calculates

	printf("Please enter a floating point value: ");
	scanf("%f", &num);
	
	printf("Fixed point entry: %f\n", num);

	printf("Exponential notation: %E ", num);
	printf("or %e\n", num);							/* you can uncomment this instead upper line */

	printf("Binary exponential notation: %A ", num);
	printf("or %a\n", num);							/* you can uncomment this instead upper line */

	return 0;
}
