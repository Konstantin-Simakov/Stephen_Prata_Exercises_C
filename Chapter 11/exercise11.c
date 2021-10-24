// exercise11.c -- Chapter 11 
#include <stdio.h>		// for getchar(), fgets(), puts(), printf()
#include <string.h>		// for strcmp(), strlen()

// constants for arrays
#define LIM 10
#define SIZE 40
// constants for characters
#define SPACE ' '

// prototypes of normal functions
void menu(void);
char get_choice(void);
char get_first(void);
char * s_gets(char *, int);
void otpt_src(char **, int);			// output strings in source order
// prototypes of sort functions
void otpt_ascii(char **, int);			// output strings in ASCII order
void otpt_ln_str(char **, int);		// output strings in string length order
void otpt_ln_1word(char **, int);		// output strings in the first word length order
int len_1word(const char *);

int main(void)
{
	char input[LIM][SIZE];					// source strings array
	char * ptstr[LIM];						// for sort of strings
	int ct = 0;
	char choice;

	printf("Enter up to %d strings (or en empty string to finish the input):\n", LIM);
	while (ct < LIM && s_gets(input[ct], SIZE) && input[ct][0])
	{
		ptstr[ct] = input[ct];
		ct++;
	}

	menu();
	while ((choice = get_choice()) != '5')
	{
		switch (choice)
		{
			// otpt... == output...
			case '1': otpt_src(ptstr, ct);
				break;
			case '2': otpt_ascii(ptstr, ct);
				break;
			case '3': otpt_ln_str(ptstr, ct);
				break;
			case '4': otpt_ln_1word(ptstr, ct);
				break;
			default: puts("Error! Try again:");
				break;
		}
		menu();		// repeat menu() for the new loop iteration
	}
	puts("The program has been completed.");
	
	return 0;
}

char * s_gets(char * str, int n)
{
	char * ret_val;

	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		while (*str != '\n' && *str)
			str++;

		if ('\n' == *str)
			*str = '\0';
		else	// if ('\0' == *str)
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

void menu(void)
{
	puts("Choose from five options:");
	puts("1) output source strings list;");
	puts("2) output strings according to the ASCII collation sequence;");
	puts("3) output strings in ascending order of string length;");
	puts("4) output strings in ascending order of length of the first word of the string;");
	puts("5) quit program");
}

char get_choice(void)
{
	int ch;

	ch = get_first();
	while (ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5')
	{
		puts("Incorrect input choose. Try again.");
		ch = get_first();
	}

	return ch;
}

char get_first(void)
{
	int ch;

	ch = getchar();
	while (getchar() != '\n')
		continue;

	return ch;
}

// strings functions
void otpt_src(char ** strings, int num)
{
	int i;

	putchar('\n');
	for (i = 0; i < num; i++)
		puts(strings[i]);
	putchar('\n');
}

void otpt_ascii(char ** strings, int num)
{
	char * temp;
	int top, seek;

	// sort strings in ASCII order
	for (top = 0; top < num - 1; top++)

		for (seek = top + 1; seek < num; seek++)
			if (strcmp(strings[top], strings[seek]) > 0)
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
	// output these strings
	otpt_src(strings, num);
}

void otpt_ln_str(char ** strings, int num)
{
	int seek, top;
	char * temp;

	// sort strings in string length order
	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (strlen(strings[top]) < strlen(strings[seek]))
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
	// output these strings
	otpt_src(strings, num);
}

void otpt_ln_1word(char ** strings, int num)
{
	int seek, top;
	char * temp;

	// sort strings in 1st length word order
	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (len_1word(strings[top]) < len_1word(strings[seek]))
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
	// output these strings
	otpt_src(strings, num);
}

int len_1word(const char * str)
{
	int ct = 0;

	while (str[ct] != SPACE && str[ct])
		ct++;

	return ct;
}
