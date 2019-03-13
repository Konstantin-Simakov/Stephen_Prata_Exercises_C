// ex5.c -- (Chapter 2) calculate and output toes, squared toes, cubed and toes;
#include <stdio.h>

int main (void)
{
	int toes = 10;
	int toes_2 = 2 * toes;
	int toes_sq = toes * toes;

	printf("Toes variable equal:  %d\n", toes);
	printf("Twice toes equal:     %d\n", toes_2);
	printf("Squared toes equal:   %d\n", toes_sq);

	return 0;
}