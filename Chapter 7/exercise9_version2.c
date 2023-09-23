/* exercise9_version2.c -- Chapter 7 */
#include <stdio.h>
#include <stdbool.h>                            // for bool variable

unsigned prime_num(unsigned num_prime);                 // n is the number of a number that is prime

int main(void)
{
    unsigned num_prime;                     // the number of a number that is prime

    printf("Enter a positive integer number "
        "(or q to finish the program):\n");
    while (scanf("%u", &num_prime) == 1)
    {
        printf("%u - %uth prime number.\n", prime_num(num_prime), 
            num_prime);
        
        printf("Enter the next positive integer number "
            "(or q to finish the program):\n");
    }
    printf("Exit --> OK.\n");

    return 0;
}

unsigned prime_num(unsigned num_prime)                  // n is the number of a number that is prime
{
    unsigned number;
    unsigned div;
    unsigned count;
    bool is_prime;

    number = 2 - 1;                         // it should be so
    count = 1;

    while (count <= num_prime)
    {
        is_prime = true;                    // initially the flag is set to true...
        number++;                       // pass over all numbers to upper
            
        for (div = 2; (div * div) <= number; div++)
            if (number % div == 0)              // if at least 1 divisor was found for the number number,
                is_prime = false;           // then such a number is not prime
        
        if (is_prime)                       // if the number is prime
        {
            // printf("%u\t", number);          // output this prime number (optional)
            count++;                    // count prime number
        }
    }
    // putchar('\n');

    return number;
}
