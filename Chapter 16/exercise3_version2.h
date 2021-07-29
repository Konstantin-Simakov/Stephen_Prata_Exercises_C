/* exercise3.h -- header file for exercise3.c */
#ifndef EXERCISE3_VERSION2_H_
#define EXERCISE3_VERSION2_H_

#define DEG_TO_RAD (4 * atan(1) / 180)		/* == (PI / 180) */

typedef struct rect_v {
	double x;
	double y;
} RECT_V;

typedef struct polar_v {
	double magnitude;
	double angle;
} POLAR_V;

void polar_to_rect (RECT_V *, const POLAR_V *);

#endif
