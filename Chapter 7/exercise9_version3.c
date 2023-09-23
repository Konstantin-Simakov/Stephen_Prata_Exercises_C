/* exercise9_version3.c -- the program searching nth prime number   */
#include <stdio.h>
#include <stdbool.h>                /* for bool, true, false */

unsigned long prime_number(unsigned n);
bool is_prime(unsigned num);

int main(void)
{
    const char * str;
    int n;

    printf("Enter the number (q or non-positive to quit): ");
    while (scanf("%d", &n) == 1 && n > 0)
    {
        switch (n)
        {
            case 1: str = "st";
                break;
            case 2: str = "nd";
                break;
            case 3: str = "rd";
                break;
            default: str = "th";
        }
        printf("%d%s by counting prime number is %lu.\n", n, str, prime_number(n));

        printf("Enter the next number (q or 0 to quit): ");
    }
    puts("Bye!");

    return 0;
}

/* n_prime is the ordinal number of the prime   */
unsigned long prime_number(unsigned n_prime)
{
    unsigned count = 0;
    unsigned num = 1;

    while (count < n_prime)
    {
        ++num;
        if (is_prime(num))
            count++;
    }
    
    return num;
}

bool is_prime(unsigned num)
{
    unsigned div;
    bool prime = true;

    for (div = 2; div * div <= num; div++)
        if (num % div == 0)
        {
            prime = false;
            break;
        }

    return prime;
}
