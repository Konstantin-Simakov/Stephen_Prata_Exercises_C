// exercise_11.c -- for a company selling groceries;
#include <stdio.h>
#include <ctype.h>

void Inviting (void);

#define ARTICHOKES 	1.25			// pound cost of artichokes
#define BEET 		0.65			// pound cost of beet
#define CARROT 		0.89			// pound cost of carrot
#define DISCOUNT	5.00 / 100.0	// size of discount;
#define NUM_ITEMS	3

int main (void)
{
	const signed char artichokes = 0;
	const signed char beet = 1;
	const signed char carrot = 2;

	char option;
	float weight[NUM_ITEMS] = {0};
	float cost_sep[NUM_ITEMS] = {0};
	float cost_all, weight_all, cost_ship;
	unsigned char i;
	unsigned short count;

	cost_all = weight_all = cost_ship = 0;

	Inviting();

	/* Input of the available letter: */
	while ((option = getchar()) != EOF)	// ?.!!~!
	{
		if (option == '\n')
			continue;
		else if ((option < 'a' || option > 'c') && option != 'q')
		{
			printf("Incorrect! Choose again.\n");
			while (getchar() != '\n')
				continue;				// skips the remaining characters in the input stream (if they are);
			continue;
		}

		switch (option)
		{
			case 'a': 
				printf("Please, enter your weight of artichokes in pounds: (1 pound = $%.2f)\n", ARTICHOKES);
				scanf("%f", &weight[artichokes]);
				cost_sep[artichokes] = ARTICHOKES * weight[artichokes];
				break;
			case 'b': 
				printf("Please, enter your weight of beets in pounds: (1 pound = $%.2f)\n", BEET);
				scanf("%f", &weight[beet]);
				cost_sep[beet] = BEET * weight[beet];
				break;
			case 'c': 
				printf("Please, enter your weight of carrots in pounds: (1 pound = $%.2f)\n", CARROT);
				scanf("%f", &weight[carrot]);
				cost_sep[carrot] = CARROT * weight[carrot];
				break;
			case 'q': printf("\nOrder is completed! Please, wait...\n");
				break;
		}
		if (option >= 'a' && option <= 'c')
			printf("Great! Maybe something else? (\'q\' for exit)\n");
		else if (option == 'q')
			break;

		Inviting();
	}
	
	// Calculate total weight and cost (cost calcualte without shipping cost);
	for (i = 0; i < NUM_ITEMS; i++)
	{
		weight_all += weight[i];
		cost_all += cost_sep[i];
	}
	
	printf("The cost of your order (without another factors) = $%.2f\n", cost_all);

	// Order cost per each vegetable.
	printf("Order cost per each vegetable:\nArtichokes = $%.2f; beets = $%.2f; carrots = $%.2f.\n", 
		cost_sep[artichokes], cost_sep[beet], cost_sep[carrot]);
	
	// Calculate discount (if there is).
	if (cost_all >= 100.0)
	{
		printf("Since your order is more than 100 dollars, you get a discount of %.2f%%\n"
			"Discount: $%.2f\n", 
				DISCOUNT * 100.0, cost_all * DISCOUNT);
		cost_all *= 1 - DISCOUNT;
		printf("In this occasion, the cost of your order = $%.2f\n", cost_all);
	}
	
	// Shipping сosts;
	if (weight_all < 5 && weight_all > 0)
		cost_all += (cost_ship = 3.5);
	else if (weight_all >= 5 && weight_all < 20)
		cost_all += (cost_ship = 10.0);
	else if (weight_all >= 20)
	{
		cost_ship = 8.0;
		for (count = 21; count <= weight_all; ++count)
			cost_ship += 0.1;
		cost_all += cost_ship;
	}
	printf("Shipping cost: $%.2f\n", cost_ship);

	// Total cost:
	printf("Total: the amount of your order = $%.2f\n", cost_all);

	// Farewell.
	printf("Good bye!\nCome again.\n");
		
	return 0;
}

/* Inviting to user to enter any of the available letters; */
void Inviting (void)
{
	printf("\nChoose one of the options (letter):\n");
	printf("a) artichokes\t\t\tb) beet\n"
			"c) carrot\t\t\tq) if order is completed\n");
}