/* exercise3.c -- Chapter 16 */
#include <stdio.h>
#include <math.h>		/* for atan(), sin(), cos() */
#include "exercise3.h"	

int main(void)
{
	Polar_V input;
	Rect_V result;

	printf("Enter polar coordinates: r (magnitude), A (angle).\n"
		"(or \'q\' to quit the program)\n");
	while (scanf("%lf %lf", &input.magnitude, &input.angle) == 2)
	{
		result = polar_to_rect(input);
		printf("x = %.2f, y = %.2f\n", result.x, result.y);

		puts("Enter the next polar coordinates: magnitude and angle.");
	}
	puts("The program has been completed.");
	
	return 0;
}

Rect_V polar_to_rect(Polar_V pv)
{
	const double radians = pv.angle * DEG_TO_RAD;
	Rect_V rv;

	rv.x = pv.magnitude * cos(radians);
	rv.y = pv.magnitude * sin(radians);

	return rv;
}
