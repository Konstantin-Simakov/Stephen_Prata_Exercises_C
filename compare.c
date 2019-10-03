/* compare.c -- this program will work. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ANSWER "GRANT"
#define MAX 40

void toUpper (char *);

int main (void)
{
	char try[MAX];

	puts("Who is burried in Grant's grave?");
	gets(try);
	toUpper(try);

	while (strcmp(try, ANSWER))				/* == (strcmp(try, ANSWER) != 0) ... */
	{
		puts("No, it's not. Try once.");
		gets(try);
		toUpper(try);
	}
	puts("That is truth!");

	return 0;
}

void toUpper (char * string)		/* translate all characters to uppercase for more easy comparison */
{
	while (*string)
	{
		*string = toupper(*string);		/* function toupper RETURNS the character in uppercase and no changes inside function */
		string++;						/*	else this function will return source argument. */
	}
}