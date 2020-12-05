/* exercise4_version2.c -- Chapter 6 */
/* using char array */
#include <stdio.h>
// #include <string.h>		// line 4

#define R_AND_C 6
#define SIZE 26 + 1 	 	// 26 english alphabet characters + 1 character '\0' for string ending 

int main (void)
{
	char lets[SIZE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, j;
	int index = 0;

	// printf("The string length is %zd\n", strlen(lets));		// line 13
	// you can uncomment line 13, but before that you should uncomment line 4

	
	// in this case, you can start with 1, but 
	// only in this case, in most cases, it 
	// is better to start at 0
	for (i = 1; i <= R_AND_C; i++)				// <-- here, NONE of the counter variables are used in the array index
	{
		for (j = 1; j <= i; j++)				// <-- here, NONE of the counter variables are used in the array index
		{
			printf("%c", lets[index]);			// <-- here the array index doesn't use any of the counter variables 
			index++;							// 		of any of the loops above
		}
		printf("\n");
	}

	return 0;
}
