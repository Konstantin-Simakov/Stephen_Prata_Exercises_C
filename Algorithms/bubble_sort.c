/* bubble_sort.c */
/* The program implements bubble sort of the integer array. */
#include <stdio.h>

void bubble_sort(int arr[], int size);
void swap(int * a, int * b);
void output(const int arr[], int n);

int main(void)
{
	int arr[] = {0, 1, 5, -1, -3, 2, 6, 4};
	const int SIZE = sizeof arr / sizeof arr[0];

	printf("Source array:\n");
	output(arr, SIZE);
	bubble_sort(arr, SIZE);
	printf("Sorted array:\n");
	output(arr, SIZE);

	return 0;
}

void output(const int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void bubble_sort(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
