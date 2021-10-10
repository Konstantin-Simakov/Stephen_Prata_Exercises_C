/* exerise8.c -- Chapter 3 */
#include <stdio.h>

int main(void)
{
	float cups = 0.0f;

	printf("Please, enter volume in cups: ");
	scanf("%f", &cups);
	printf("This volume in:\n"
			"pints %.2f;\n"
			"ounces %.2f;\n"
			"tablespoon %.2f;\n"
			"teaspoon %.2f\n", 	// the space charater is here!!!
			cups / 2.0f, cups * 8.0f, cups * 8.0f * 2.0f, cups * 8.0f * 2.0f * 3.0f);

	return 0;
}
