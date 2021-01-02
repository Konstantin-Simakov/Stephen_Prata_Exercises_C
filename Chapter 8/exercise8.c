/* exercise8.c -- Chapter 8 */
#include <stdio.h>
#include <ctype.h>			/* for isspace() in get_first() */

char get_choice(void);	
char get_first(void);		/* gets the first non-whitespace character character from data input */
float get_float(void);
void addition(void);
void subtraction(void);
void multiplication(void);
void division(void);

int main (void)
{
	char choice;

	while ((choice = get_choice()) != 'q')
	{
		switch (choice)
		{
			case 'a': addition();
				break;
			case 's': subtraction();
				break;
			case 'm': multiplication();
				break;
			case 'd': division();
				break;
			default: printf("Error!\n");
		}
	}
	printf("The program has been completed.\n");
	
	return 0;
}

char get_first (void)
{
	char ch;
	
	ch = getchar();
	while (isspace(ch))
		ch = getchar();

	while (getchar() != '\n')
		continue;

	return ch;
}

char get_choice (void)
{
	char ch;

	printf("Choose the desired operation:\n");
	printf("a. addition \t\t  s. subtraction\n");
	printf("m. multiplication \t  d. division\n");
	printf("q. quit\n");

	ch = get_first();
	while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
	{
		printf("Enter a, s, m, d, or q.\n");
		ch = get_first();
	}

	return ch;
}

float get_float (void)
{
	float input;
	char ch;

	while (scanf("%f", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);			/* for any first number or with a letter input second number */
		printf(" is not a number.\nEnter ");
		printf("a number such as 2.5, -1.78.E8 or 3:\n");
	}
	while (getchar() != '\n')
		continue;					/* for the second number -> discard the rest of a line */

	return input;
}

void addition (void)
{
	float num_1, num_2;
	
	printf("Enter the first number: ");
	num_1 = get_float();

	printf("Enter the second number: ");
	num_2 = get_float();

	if (num_2 < 0)
		printf("%.2f + (%.2f) = %.2f\n", num_1, num_2, num_1 + num_2);
	else
		printf("%.2f + %.2f = %.2f\n", num_1, num_2, num_1 + num_2);
}

void subtraction (void)
{
	float num_1, num_2;
	
	printf("Enter the first number: ");
	num_1 = get_float();

	printf("Enter the second number: ");
	num_2 = get_float();

	if (num_2 < 0)
		printf("%.2f - (%.2f) = %.2f\n", num_1, num_2, num_1 - num_2);
	else
		printf("%.2f - %.2f = %.2f\n", num_1, num_2, num_1 - num_2);
}

void multiplication (void)
{
	float num_1, num_2;
	
	printf("Enter the first number: ");
	num_1 = get_float();

	printf("Enter the second number: ");
	num_2 = get_float();

	if (num_2 < 0)
		printf("%.2f * (%.2f) = %.2f\n", num_1, num_2, num_1 * num_2);
	else
		printf("%.2f * %.2f = %.2f\n", num_1, num_2, num_1 * num_2);
}

void division (void)
{
	float num_1, num_2;
	
	printf("Enter the first number: ");
	num_1 = get_float();

	printf("Enter the second number: ");
	num_2 = get_float();
	while (num_2 == 0)
	{
		printf("Enter another number (not a zero):\n");
		num_2 = get_float();
	}

	if (num_2 < 0)
		printf("%.2f / (%.2f) = %.2f\n", num_1, num_2, num_1 / num_2);
	else
		printf("%.2f / %.2f = %.2f\n", num_1, num_2, num_1 / num_2);
}
