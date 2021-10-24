/* exercise1.c -- Chapter 12 */
#include <stdio.h>

void critic(int *);

int main(void)
{
	int units = 0;

	printf("How many does the small keg of butter weigh?\n");
	scanf("%d", &units);

	while (units != 56)
		critic(&units);
	printf("You knew it!\n");

	return 0;
}

void critic(int * punits)
{
	printf("You were unlucky. Try again.\n");
	scanf("%d", punits);
}
