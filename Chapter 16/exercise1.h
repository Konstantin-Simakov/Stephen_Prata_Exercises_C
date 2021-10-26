/* exercise1.h -- Chapter 16 */
#ifndef EXERCISE1_H_
#define EXERCISE1_H_
#include <stdio.h>

inline static void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

#endif
