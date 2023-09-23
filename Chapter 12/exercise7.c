/* exercise7.c -- Chapter 12` */
/* compile with support7.c */
/* compilation in any based on Debian Linux system:
gcc exercise7.c support7.c -o exercise7 -Wall */
/* then launch:
./exercise7 */
#include <stdio.h>
#include <stdlib.h>     // for rand(), srand()
#include <time.h>       // for time()

/* tosses output */
extern void output_tosses(int tosses, int dice, int sides);

int main(void)
{
    int tosses, dice, sides;
    int status;         // for scanf() return value saving

    srand((unsigned) time(0));      // seed randomize

    printf("Enter the number of dice tosses or q to finish. ");
    while (scanf("%d", &tosses) == 1)
    {
        if (tosses < 1)
        {
            puts("A number dice tosses input should be positive digital number. Try again.");
            printf("\nEnter the number of dice tosses or q to finish. ");
            continue;
        }
        printf("How many dices and sides? ");
        if ((status = scanf("%d %d", &dice, &sides)) != 2)
        {
            if (EOF == status)
                break;
            else
            {
                puts("Incorrect data input. Try again from the beginning.");
                printf("\nEnter the number of dice tosses or q to finish. ");
                continue;

            }
        }
        output_tosses(tosses, dice, sides);
        printf("\nEnter the number of dice tosses or q to finish. ");
    }
    puts("The program has been completed.");
    
    return 0;
}
