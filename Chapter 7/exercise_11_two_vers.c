// exercise_11.c
#include <stdio.h>

#define ARTICHOKES 	1.25
#define BEET 		0.65
#define CARROT 		0.89
#define DISCOUNT	0.05

int main (void)
{
	float diskount = 0;
	float weight = 0, cost = 0, weight_all = 0;
	float disc_cost = 0, cost_delivery = 0;
	float cost_sep[3] = { 1, 1, 1 }, weight_sep[3] = { 0 };
	char veggies;

	printf("Choose one of the options:\n");
	printf("a) artichokes\t\t\tb) beet\n"
			"c) carrot\t\t\tq) if order is completed\n");

	while (scanf("%c", &veggies) == 1)	// ?.
	{
		if ((veggies < 'a' || veggies > 'c') && veggies != 'q')
			continue;
		
		printf("Please, enter weight of a vegetable:\n");
		while (scanf("%f", &weight) == 1)
		{
			switch (veggies)
			{
				case 'a': 
					printf("Cost of a one pound of artichokes: %.2f", ARTICHOKES);
					if ((cost = ARTICHOKES * weight) >= 100)
						cost *= 1 - DISCOUNT;
					weight_sep[0] = weight;
					break;
				case 'b': 
					printf("Cost of a one pound of beet: %.2f", BEET);
					if ((cost = BEET * weight) >= 100)
						cost *= 1 - DISCOUNT;
					weight_sep[1] = weight;
					break;
				case 'c': 
					printf("Cost of a one pound of carrot: %.2f", CARROT);
					if ((cost = CARROT * weight) >= 100)
						cost *= 1 - DISCOUNT;
					weight_sep[2] = weight;
					break;
				case 'q': printf("Order completed! Please, wait...\n\n");
					break;
			}

			diskount += disc_cost;
			weight_all += weight;
		}
		printf("Pounds ordered: %.2f", weight);


		if (weight <= 5)
			cost += (cost_delivery = 3.5);
		else if (weight > 5 && weight <= 20)
			cost += (cost_delivery = 10.0);
		else if (weight > 20)
		{
			cost += (cost_delivery = 8.0);
			for (int count = 21; count <= weight; ++count)
				cost += (cost_delivery += 0.1);
		}

		printf("The weight of every vegetable in order separately: ");

		
		printf("\nChoose one of the options:\n");
		printf("a) artichokes\t\t\tb) beet\n"
				"c) carrot\t\t\tq) if order is completed\n");
	}
	
	return 0;
}