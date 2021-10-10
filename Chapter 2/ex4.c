// ex4.c -- (Chapter 2);
#include <stdio.h>

void goodBoy(void);
void bestBoy(void);

int main(void)
{
	goodBoy();
	goodBoy();
	goodBoy();
	bestBoy();

	return 0;
}

void goodBoy(void)
{
	printf("Our Billy is a good boy.\n");
}

void bestBoy(void)
{
	printf("Our Billy is the best!\n");
}
