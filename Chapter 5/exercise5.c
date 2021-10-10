/* exercise5.c -- Chapter 5 */
#include <stdio.h>

int main(void)
{
	int sum, count, val;

	count = 0;
	sum = 0;

	printf("This program calculates the sum of the first \"x\" (>= 0) numbers "
		"where \"x\" is given by user.\n");

	printf("Enter the \"x\" (>= 0): ");
	scanf("%d", &val);
	
	// here can be see interest properties of the increment operation (below)
	while (count++ < val)
	{
		// count++;
		sum = sum + count;
	}

	printf("The sum of the first %d numbers is %d.\n", val, sum);
	// printf("Counter is %d\n", count);
	printf("(Done.)\n");

	return 0;
}
/* If you uncomment the comments, 
then you need to remove the increment 
in the condition for checking the while cycle. 
You can also check the output of the incremental counter 
inside the loop check condition.
*/
