/* exercise5.c -- Chapter 11 */
#include <stdio.h>

char * my_strchr (const char * str, int ch);

int main (void)
{
	char str[] = "Hello, my friends!\nHow are you?\n";
	char * find;

	find = my_strchr(str, '\n');
	puts(find + 1);

	return 0;
}

char * my_strchr (const char * str, int ch)
{
	char * ret_val;

	while (*str != ch && *str)
		str++;

	if (!*str)		// if (*str == '\0')
		ret_val = NULL;
	else
		ret_val = (char *) str;		// discards from const!!!

	return ret_val;
}
