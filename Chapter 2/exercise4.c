/* exercise4.c -- Chapter 2 */
#include <stdio.h>

void jolly(void);
void deny(void);

int main(void)
{
	jolly();
	jolly();
	jolly();
	
	deny();

	return 0;
}

void jolly(void)
{
	printf("He is a jolly fellow!\n");

	return;
}

void deny(void)
{
	printf("Nobody can deny it!\n");

	return;
}
