/* exercise2_vers2.c -- Chapter 3 */
#include <stdio.h>

char dec_to_ch(signed char);

int main(void)
{
	signed char ch = 0;
	char ch1 = 0;

	printf("Please, enter the number less or equal than 127 "
			"and more or equal than 0:\n");
	ch1 = dec_to_ch(ch);

	printf("Your entered number %hhd is according to %c\n", ch/*!!!*/, ch1);	

	return 0;
}

char dec_to_ch(signed char var)
{
	scanf("%hhd", &var);

	return var;
}
