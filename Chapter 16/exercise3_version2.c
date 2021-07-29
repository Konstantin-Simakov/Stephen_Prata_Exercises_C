/* exercise3_version2.c -- Chapter 16 */
#include <stdio.h>
#include <math.h>		/* for atan(), sin(), cos() */
#include "exercise3_version2.h"	

int main (void)
{
	POLAR_V input;
	RECT_V result;

	printf("Enter polar coordinates: r (magnitude), A (angle).\n"
		"(or \'q\' to quit the program)\n");
	while (scanf("%lf %lf", &input.magnitude, &input.angle) == 2)
	{
		polar_to_rect(&result, &input);
		printf("x = %.2f, y = %.2f\n", result.x, result.y);

		puts("Enter the next polar coordinates: magnitude and angle.");
	}
	puts("The program has been completed.");
	
	return 0;
}

void polar_to_rect (RECT_V * rv, const POLAR_V * pv)
{
	const double radians = pv->angle * DEG_TO_RAD;

	rv->x = pv->magnitude * cos(radians);
	rv->y = pv->magnitude * sin(radians);
}
