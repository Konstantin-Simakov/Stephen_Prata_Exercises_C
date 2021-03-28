/* exercise3.c -- Chapter 11 */
#include <stdio.h>			// for getchar()
#include <ctype.h>			// for isspace()
#include <stdbool.h>		// for bool, true, false

#define SIZE 10

char * str_word (char * str, int n);

int main (void)
{
	char str[SIZE];
	char * ptr;

	ptr = str_word(str, SIZE);
	puts(ptr);
	
	return 0;
}

char * str_word (char * str, int n)
{
	bool inword = false;
	int i = 0;
	char temp;

	while (i < n && (temp = getchar()) != EOF)
	{
		if (!inword && !isspace(temp))
			inword = true;
		else if (inword && isspace(temp))
			break;		
		
		if (inword && !isspace(temp))
			str[i++] = temp;
	}
	if (EOF == temp)
		str = NULL;
	else	// it is important for any string in the C
		str[i] = '\0';

	return str;
}
