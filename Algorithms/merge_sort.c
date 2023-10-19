/* bubble_sort.c */
/* The program implements bubble sort of the integer array. */
#include <stdio.h>

void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int l, int r);
void output(const int arr[], int n);

int main(void)
{
	int arr[] = {0, 1, 5, -1, -3, 2, 6, 4};
	const int SIZE = sizeof arr / sizeof arr[0];

	printf("Source array:\n");
	output(arr, SIZE);
	merge_sort(arr, 0, SIZE - 1);
	printf("Sorted array:\n");
	output(arr, SIZE);

	return 0;
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (r + l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int size_l = m - l + 1;
    int size_r = r - m;
    int temp_l[size_l], temp_r[size_r];

    for (i = 0; i < size_l; ++i)
    {
        temp_l[i] = arr[l + i];
    }
    for (j = 0; j < size_r; ++j)
    {
        temp_r[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < size_l && j < size_r)
    {
        if (temp_l[i] <= temp_r[j])
        {
            arr[k] = temp_l[i];
            ++i;
        }
        else
        {
            arr[k] = temp_r[j];
            ++j;
        }
        ++k;
    }

    while (i < size_l)
    {
        arr[k] = temp_l[i];
        ++i;
        ++k;
    }
    while (j < size_r)
    {
        arr[k] = temp_r[j];
        ++j;
        ++k;
    }
}

void output(const int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}
