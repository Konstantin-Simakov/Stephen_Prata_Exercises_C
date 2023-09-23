/* exercise11.c -- Chapter 7 */
#include <stdio.h>

// vegetables, cost (dollars per pound)
#define ARTICHOKE   2.05
#define BEET        1.15
#define CARROT      1.09
// discount (percentages / 100); excluding delivery
#define DISCOUNT    0.05
// delivery, dollars
#define DELIVERY_1  6.5     // up to 5 pounds
#define DELIVERY_2  14.00   // from 5 to 20 pounds
#define SURCHARGE   0.5     // over pound 20, for each additional pound
// delivery, pounds
#define WEIGHT_1    5       // (see above ^)
#define WEIGHT_2    20      // (see above ^)


int main(void)
{
    char ch;
    int status;                         // for scanf() return value
    float weight;                       // temporary, in pounds
    float weight_a = 0.0f;              // in pounds
    float weight_b = 0.0f;              // in pounds
    float weight_c = 0.0f;              // in pounds
    float final_cost = 0.0f;            // in dollars
    float total_weight = 0.0f;          // in pounds
    float delivery_cost = 0.0f;         // in dollars
    float discount = 0.0f;              // in dollars
    float products_sum = 0.0f;          // in dollars

    printf("Enter the letter: a - artichoke, b - beet, c - carrot, "
        "q - complete the order:\n");
    while ((ch = getchar()) != 'q')
    {
        // if ('\n' == ch)
        //  continue;
        if (ch >= 'a' && ch <= 'c')
        {
            switch (ch)
            {
                case 'a': 
                    printf("Enter the artichokes weight in pounds:\n");
                    status = scanf("%f", &weight);
                    if (weight < 0 || status != 1)
                    {
                        printf("Incorrect data input. Try again:\n");
                        break;
                    }
                    weight_a += weight;
                    break;
                case 'b': 
                    printf("Enter the beets weight in pounds:\n");
                    status = scanf("%f", &weight);
                    if (weight < 0 || status != 1)
                    {
                        printf("Incorrect data input. Try again:\n");
                        break;
                    }
                    weight_b += weight;
                    break;
                case 'c': 
                    printf("Enter the carrots weight in pounds:\n");
                    status = scanf("%f", &weight);
                    if (weight < 0 || status != 1)
                    {
                        printf("Incorrect data input. Try again:\n");
                        break;
                    }
                    weight_c += weight;
                    break;
            }
        }
        else
            printf("Incorrect data input. Try again:\n");
        while (getchar() != '\n')
            continue;
        
        printf("Enter the next letter: a - artichoke, b - beet, c - carrot, "
        "q - complete the order:\n");
    }
    products_sum = weight_a * ARTICHOKE + weight_b * BEET + weight_c * CARROT;

    total_weight = weight_a + weight_b + weight_c;

    // discount cost calculating
    if (products_sum >= 100.0f)
        discount = products_sum * DISCOUNT;

    // delivery cost calculating
    if (total_weight <= WEIGHT_1)
        delivery_cost = DELIVERY_1;
    else if (total_weight <= WEIGHT_2)
        delivery_cost = DELIVERY_2;
    else
        delivery_cost = DELIVERY_2 + (total_weight - WEIGHT_2) * SURCHARGE;

    final_cost = products_sum - discount + delivery_cost;

    /* output of all calculating above */   
    // the cost of a pound of goods
    printf("A pound of artichokes costs $%.2f, beets $%.2f, and carrots $%.2f.\n", 
        ARTICHOKE, BEET, CARROT);
    // weight of each item, total weight
    printf("The number of pounds ordered is %.2f pounds of artichokes, %.2f pounds of beets "
        "and %.2f pounds of carrots. Total weight is %.2f pounds.\n", 
        weight_a, weight_b, weight_c, total_weight);
    // the cost of each ordered type of product
    printf("Artichokes cost $%.2f, beets $%.2f, carrots $%.2f.\n", 
        weight_a * ARTICHOKE, weight_b * BEET, weight_c * CARROT);
    // total cost, discount, delivery cost, final cost
    printf("The total cost of the order is $%.2f.\n", products_sum);
    printf("The discount is $%.2f.\n", discount);
    printf("Delivery cost is $%.2f.\n", delivery_cost);
    printf("The final cost of the order is $%.2f.\n", final_cost);

    return 0;
}
