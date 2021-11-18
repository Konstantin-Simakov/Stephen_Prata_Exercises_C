/* exercise6.c -- Chapter 17 */
#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

/* note: the first argument must be a sorted array! */
bool binary_search(int arr_sorted[], int num, int seek);

int main(void)
{
	/* sequential natural series from 1 to 10 */
	int array[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int guess;

	puts("Enter the hidden number (or q to quit):");
	while (scanf("%d", &guess) == 1)
	{
		if (binary_search(array, SIZE, guess))
			printf("Number %d is in the array.\n", guess);
		else
			printf("Number %d is not in the array.\n", guess);

		puts("Enter the next hidden number (or q to quit):");
	}
	puts("Bye!");
	
	return 0;
}

bool binary_search(int arr[], int n, int seek)
{
	bool is_here = false;
	int left = 0;
	int right = n - 1;
	int index;

	while (left != right)
	{
		index = (left + right) / 2;
		if (seek > arr[index])
			left = index + 1;
		else if (seek < arr[index])
			right = index - 1;
		else	/* seek == arr[index] */
		{
			is_here = true;
			break;
		}
	}
	if (!is_here && arr[left] == seek)		/* here left must be equal to right */
		is_here = true;

	return is_here;
}
