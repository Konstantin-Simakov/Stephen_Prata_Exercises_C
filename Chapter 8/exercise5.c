// exercise5.c -- Chapter 8 
#include <stdio.h>

#define HYPHEN 	"-----------------------------------------------"
#define MIN 	(-1)
#define MAX 	101

int main (void)
{
	int min = MIN;
	int max = MAX; 
	int number = (min + max) / 2;							// sought-for number
	char response;

	// program description
	printf("This program guesses the user-guessed number "
		"in the range from %d to %d "
		"using a binary search algorithm.\n", (min + 1), (max - 1));
	printf("%s\n", HYPHEN);
	
	// algorithm
	printf("Is your number %d (y/n)?\n", number);
	while ((response = getchar()) != 'y')						// yes
	{
		if ('n' == response)							// no
		{
			while (getchar() != '\n')
				continue;

			printf("Your number more or less than %d (m/l)?\n", number);

			if ((response = getchar()) == 'm')				// here is if and no while with getchar() using
			{
				min = number;
				number = (min + max) / 2;
			}
			else if (response == 'l')
			{
				max = number;
				number = (min + max) / 2;
			}
			else
				printf("Incorrect letter input. Try again:\n");
		}
		else
			printf("Incorrect letter input. Choose y/n (yes or no):\n");
		
		// discard the rest of the line a second time
		if (response != '\n')
			while (getchar() != '\n')
				continue;

		// validation
		if (max - min == 2)
		{
			printf("Your number is %d.\n", (max + min) / 2);
			break;
		}
		else if (max - min == 1)
		{
			printf("There is nothing less than %d, "
				"so your number is %d.\n", max, max);
			break;
		}

		// guessing again
		printf("Is your number %d (y/n)? \n", number);
	}
	// guessed
	printf("I knew I could do it!\n");
	printf("The program has been completed.\n");					// finish the program

	return 0;
}
