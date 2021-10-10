/* exercise4.c -- Chapter 4 */
#include <stdio.h>

int main(void)
{
	char name[30];
	float growth = 0.0F;

	printf("Please, enter your growth (in cm) and name:\n");

	scanf("%f %s", &growth, name);

	growth = growth / 100;

	printf("\n%s, your growth is %.3f metres.\n", name, growth);

	return 0;
}
