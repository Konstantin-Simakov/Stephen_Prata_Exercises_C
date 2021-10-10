/* exercise2.c -- Chapter 5 */
#include <stdio.h>

#define TEN 10

int main(void)
{
	int num, num_s;			/* num_s is the result of adding the original 
							 variable (num) and the symbolic constant TEN */
	printf("Please enter some digital number.\n");
	scanf("%d", &num);

	num_s = num + TEN;

	while (num <= num_s)
		printf("%d ", num++);
	
	printf("\n");
	
	printf("Good bye!\n");
	printf("(Or restart this program to calculate "
		"some another number.)\n");

	return 0;
}

/* This program does not assume the use of re-entering an integer. */