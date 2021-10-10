/* exercise13.c -- Chapter 6 */
#include <stdio.h>

#define SIZE 8

int main(void)
{
	int pow_two[SIZE];
	int i;
	int res = 1;

	for (i = 0; i < SIZE; i++)
		pow_two[i] = res *= 2;

	// == for cycle
	i = 0;
	do	
	{
		printf("%d ", pow_two[i]);
		i++;
	}
	while (i < SIZE);
	printf("\n");

	return 0;
}
