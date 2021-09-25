/* exercise3.h -- header file for exercise3.c */
#ifndef EXERCISE3_H_
#define EXERCISE3_H_

#define DEG_TO_RAD (4 * atan(1) / 180)		/* == (PI / 180) */

typedef struct rect_v {
	double x;
	double y;
} Rect_V;

typedef struct polar_v {
	double magnitude;
	double angle;
} Polar_V;

Rect_V polar_to_rect (Polar_V);

#endif
