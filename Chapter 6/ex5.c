// ex5.c
#include <stdio.h>

#define SIZE 7

int main (void)
{
	int lower_lim, upper_lim, num;

	printf("Enter lower and upper limit of table:\n");
	scanf("%d %d", &lower_lim, &upper_lim);

	printf("Number 	  Square  	Cube:\n");

	for (num = lower_lim; num <= upper_lim; num++)
		printf("%5d %8d %11d\n", num, num * num, num * num * num);
	
	return 0;
}