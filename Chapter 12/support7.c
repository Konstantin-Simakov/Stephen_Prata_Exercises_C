/* support7.c -- Chapter 12 */
/* compile with exercise7.c */
/* compilation in any based on Debian Linux system:
gcc exercise7.c support7.c -o exercise7 -Wall */
/* then launch:
./exercise7 */
#include <stdio.h>		/* for puts(), printf() */
#include <stdlib.h>		/* for rand() */

/* rollem() is required to roll_n_dice() */
static int rollem (int sides)
{
	return rand() % sides + 1;
}

static int roll_n_dice (int dice, int sides)
{
	int d;
	int tot;

	if (dice < 1)
	{
		puts("At least one dice is required.");
		tot = -1;
	}
	else if (sides < 2)
	{
		puts("At least two sides are required.");
		tot = -2;
	}
	else
		for (tot = 0, d = 1; d <= dice; d++)
			tot += rollem(sides);

	return tot;
}

void output_tosses (int tosses, int dice, int sides)
{
	int t;
	int ret_val;

	printf("We have %d tosses of %d dices with %d sides.\n", 
		tosses, dice, sides);

	for (t = 1; t <= tosses; t++)
	{
		printf("%d\t", ret_val = roll_n_dice(dice, sides));

		/* to incorrect dices and sides number processing  */
		if (ret_val < 0)
			break;
	}
	putchar('\n');
}
