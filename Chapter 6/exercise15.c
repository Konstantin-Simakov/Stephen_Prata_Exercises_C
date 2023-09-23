/* exercise15.c -- Chapter 6 */
/* the first version of this program -- with for cycle */
#include <stdio.h>

#define SIZE 255            // the max array size (by problem statement)
#define NEW_LINE_CH '\n'    // loop check condition

int main(void)
{
    int i;
    char arr_ch[SIZE];

    // data input into the character array
    printf("Please enter the string:\n");
    for (i = 0, scanf("%c", &arr_ch[i]); 
        arr_ch[i] != NEW_LINE_CH; 
            i++, scanf("%c", &arr_ch[i]))
                ;

    // data output into the screen (output device)
    printf("This string into reverse sequence:\n");
    for (i--; i >= 0; i--)
        printf("%c", arr_ch[i]);
    printf("\n");

    // notification of the end of the program
    printf("The program has been completed...\n");

    return 0;
}
