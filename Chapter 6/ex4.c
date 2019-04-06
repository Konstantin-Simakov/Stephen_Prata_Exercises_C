// ex4.c 
#include <stdio.h>

#define SIZE 5

int main (void)
{
	char space = ' ';
	int i, j;
	char begin = 'A';

	for (i = 0; i < SIZE; i++)
	{
		for (j = SIZE - 1; j > i; j--)
			printf("%c", space);


		for (j = 0; j <= i; j++)
			printf("%c", begin++);

		begin--;

		for (j = 0; j < i; j++)
			printf("%c", --begin);

		begin = 'A';

		for (j = SIZE - 1; j > i; j--)
			printf("%c", space);

		printf("\n");
	}
	
	return 0;
}