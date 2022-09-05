/* exercise4.c -- Chapter 5 */
#include <stdio.h>

const float FOOT_CM = 30.48f; 	// cm number per one foot
const int FOOT_INCH = 12;		// ineches number per one foot

int main(void)
{
	float cm, inch_left;
	int foot;

	printf("This program converts cm number into feet and inches number.\n");

	printf("Please enter a height in cm "
		"(or <= 0 for exit the program):\n");
	scanf("%f", &cm);
	while (cm > 0)
	{
		foot = (int) (cm / FOOT_CM);
		inch_left = (cm / FOOT_CM - foot) * FOOT_INCH;			// == cm % FOOT_CM * FOOT_INCH; if cm has been int type

		printf("%.2f cm = %d feet, %.1f inches.\n", cm, foot, inch_left);

		printf("Please enter a height in cm "
			"(or <= 0 for exit the program)\n");
		scanf("%f", &cm);
	}
	printf("That's all. Good bye!\n");

	return 0;
}
