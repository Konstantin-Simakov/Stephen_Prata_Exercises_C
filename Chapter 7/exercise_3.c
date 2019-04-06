// exercise_3.c
#include <stdio.h>

int main (void)
{
	int value;
	int even_ct, odd_ct, aver_val_even, aver_val_odd, sum_even, sum_odd;

	even_ct = odd_ct = sum_even = sum_odd = 0;

	printf("Enter any number.\n");
	while (scanf("%d", &value) == 1)
	{
		if (value != 0)
			if (value % 2 == 0)
			{
				even_ct++;
				sum_even += value;
			}
			else
			{
				odd_ct++;
				sum_odd += value;
			}
		else
			break;
	}
	aver_val_even = sum_even / even_ct;
	aver_val_odd = sum_odd / odd_ct;
	
	printf("(EVEN)!!! You have entered %d even numbers, their average value is %d\n", even_ct, aver_val_even);
	printf("(ODD)!!! You have entered %d odd numbers, their average value is %d\n", odd_ct, aver_val_odd);
	
	return 0;
}