/* exercise10.c -- Chapter 14 */
#include <stdio.h>
#include <string.h>			/* for strchr() */
#include <ctype.h>			/* for tolower() */

#define SIZE 4

void hello (void) {	puts("Hello!"); }
void how (void) { puts("How are you?"); }
void fine (void) { puts("I'm fine!"); }
void bye (void) { puts("Bye!"); }

void message (void (* pfunc) (void))
{ 
	(*pfunc)();
}

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}

int showmenu (void)
{
	int ret_val;
	char ans;

	puts("\nTo select a function, enter its letter label\n(or p. e to quit from the program):");
	puts("a) hello()     b) how()    c) fine()    d) bye()    e) exit the program");
	ans = tolower(getchar());
	eatline();					/* to discard '\n' character in input queue */
	while (strchr("abcde", ans) == NULL)
	{
		puts("Incorrect argument entered. Try again:");

		ans = tolower(getchar());
		eatline();
	}

	switch (ans)
	{
		case 'a': ret_val = 0;
			break;
		case 'b': ret_val = 1;
			break;
		case 'c': ret_val = 2;
			break;
		case 'd': ret_val = 3;
			break;
		case 'e': ret_val = 4;		/* quit from the valid range of the array */
			break;
		default : ret_val = -1;
			puts("Error 1");
	}

	return ret_val;
}

int main (void)
{
	void (* pfuncs[SIZE]) (void) = { hello, how, fine, bye };
	int index;

	index = showmenu();
	while (index >= 0 && index <= SIZE - 1)
	{
		message(pfuncs[index]);
		index = showmenu();
	}

	puts("The program has been completed.");
	
	return 0;
}
