// C Program for counting sort
#include <stdio.h>
#include <string.h>
#define RANGE 255

void counting_sort(char * str);

int main(void)
{
    char str[] = "Hello, dear friend!";

    puts(str);
    counting_sort(str);
    puts(str);

    return 0;
}

void counting_sort(char * str)
{ 
    // Create a count array to store count of a separate input character.
    int i, j, c;
    int cnt[RANGE + 1];
    
    // Initialize count array as 0 for all its elements.
    memset(cnt, 0, sizeof(cnt));
 
    // Store count of an each input character.
    for(i = 0; str[i]; ++i)
    {
        cnt[(int) str[i]]++;
    }
    
    // Make the sort string by alphabetic order.
    i = 0;
    for (j = 0; j < RANGE + 1 && str[i]; ++j)
    {
        for (c = 0; c < cnt[j]; ++c)
        {
            str[i++] = j;
        }
    }
}
