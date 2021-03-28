/* exercise8.c -- Chpater 12 */
#include <stdio.h>
#include <stdlib.h>		// for malloc(), free()

int * make_array (int elem, int val);
void show_array (const int ar[], int n);

int main (void)
{
	int * pa;
	int size;
	int value;

	printf("Enter elements number: ");
	while (scanf("%d", &size) == 1 && size > 0)
	{
		printf("Enter the value for initialization: ");
		scanf("%d", &value);

		pa = make_array(size, value);
		if (pa)		// == if (pa != NULL)
		{
			show_array(pa, size);
			free(pa);
		}

		printf("Enter elements number (< 1 to finish): ");
	}
	puts("The program has been completed.");
	
	return 0;
}

int * make_array (int size, int value)
{
	int * ptr;
	int i;

	ptr = (int *) malloc(size * sizeof(int));		// memory allocate

	for (i = 0; i < size; i++)
		ptr[i] = value;								// assign to every element of the array with the same value

	return ptr;
}

void show_array (const int ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
		if (i % 8 == 8 - 1)		// i -- is a variable by index (m by count == m - 1 by index) 
			putchar('\n');
	}
	if (!(i % 8 == 0))			// here i -- is a variable by count
		putchar('\n');
}
