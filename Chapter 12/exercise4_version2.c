/* exercise4_version2.c -- Chapter 12 */
#include <stdio.h>

int native_count(void);

int main(void)
{
	int i;
	int num;

	for (i = 0; i < 10; i++)
	{
		num = native_count();
		printf("num = %d\n", num);
	}

	printf("The function was called %d times.\n", num);
	
	return 0;
}

int native_count(void)
{
	static int ct = 0;

	return ++ct;
}
