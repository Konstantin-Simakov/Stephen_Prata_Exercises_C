/* exercise1.c -- Chapter 7 */
#include <stdio.h>

#define NEWLINE '\n'
#define SPACE 	' '

int main (void)
{
	char ch;
	int nc = 0;		/* newline characters counter */
	int sc = 0;		/* space characters counter */
	int oc = 0;		/* other characters counter */

	while ((ch = getchar()) != '#')		/* without '#' character */
	{
		if (NEWLINE == ch)
			nc++;
		else if (SPACE == ch)
			sc++;
		else
			oc++;
	}
	if (ch == '#')						/* with '#' character */
		oc++;
	printf("newline characters %d, space characters %d, "
		"other characters %d\n", nc, sc, oc);

	return 0;
}
