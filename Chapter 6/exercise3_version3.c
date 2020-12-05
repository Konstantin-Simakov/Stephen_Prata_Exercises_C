/* exercise3_version3.c -- Chapter 6 */
#include <stdio.h>
// #include <string.h>		// for checking corrected input of lets string

#define SIZE 26 + 1		// 26 alphabet characters and 1 '\0' character on the end of a string

int main (void)
{
	const char lets[SIZE] = "ABCDEFGHIJKLMNOPQRSTYVWXYZ";		// index: from 0 to 26
	int i, j;
	int num_let;

	// printf("The string length of lets is %zd\n", strlen(lets));
	// you can uncomment line 13, but before that you should uncomment line 3

	printf("Enter the number of letter from 1 to 26: ");
	while (scanf("%d", &num_let) == 1)
	{
		for (i = num_let - 1; i >= 0; i--)			// index begin with 0 => (i >= 0) ()
		{
			for (j = num_let - 1; j >= i; j--)		// algorithm
				printf("%c", lets[j]);				// 
			printf("\n");							// new operator...
		}
		printf("Enter the next number of leter from 1 to 26 "
			"(or q to exit the program): ");
	}
	printf("Exit --> OK\n");

	return 0;
}
