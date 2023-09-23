/* exercise8.c -- Chapter 13 */
#include <stdio.h>
#include <stdlib.h>     // for exit()
#include <string.h>     // for strlen()

#define LEN 100

int str_search_ch(const char * str, char ch);

int main(int argc, char * argv[])
{
    FILE * fp;
    char temp_str[LEN];
    int i;
    int sum_ch = 0;
    char ch;            // It isn't int because EOF absents.

    // It is not good situation.
    if (argc < 2 || strlen(argv[1]) > 1)
    {
        fputs("Incorrect arguments is entered.\n", stderr);
        fputs("Usage:\n", stderr);
        fprintf(stderr, "\n%s < 1 character> <file_1> <file_2> ... <file_n>\n", argv[0]);
        fputs("\n(Note: input <file_1> <file_2> ... <file_n> is optional.)\n", stderr);
        exit(EXIT_FAILURE);
    }

    // It is made for more conivinience.
    ch = argv[1][0];

    // It is good situation. It is less common.
    if (2 == argc)
    {
        puts("Enter any characters or strings "
            "(enter <Ctrl+D> to finish):");
        while(fgets(temp_str, LEN, stdin))
            sum_ch += str_search_ch(temp_str, ch);
        printf("Here is %d characters \'%c\'.\n", sum_ch, ch);
        exit(EXIT_SUCCESS);
    }

    // It is good situation. It is more common.
    for (i = 2; i < argc; i++)
    {
        if (!(fp = fopen(argv[i], "r")))
        {
            fprintf(stderr, "Cannot open file %s\n"
                "The next file will be read.", argv[i]);
            break;
        }
        // Line-by-line recalculation for one file.
        while (fgets(temp_str, LEN, fp))
            sum_ch += str_search_ch(temp_str, ch);
        
        // It is conclusion of results.
        printf("The \"%s\" file consists of %d characters \'%c\'.\n", 
            argv[i], sum_ch, ch);
    }
    
    return 0;
}

int str_search_ch(const char * str, char ch)
{
    int count = 0;

    while (*str != '\0')
    {
        if (*str == ch)
            count++;
        str++;
    }

    return count;
}
