/* exercise8_vers2.c -- Chapter 13 */
#include <stdio.h>
#include <stdlib.h>     // for exit()
#include <string.h>     // for strlen()

#define LEN 100

int fsearch_ch(FILE * in, char ch);

int main(int argc, char * argv[])
{
    FILE * fp;
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
    ch = argv[1][0];    // It is good step for programming.

    // It is good situation. It is less common.
    if (2 == argc)
    {
        puts("Enter any characters or strings "
            "(enter <Ctrl+D> to finish):");
        sum_ch = fsearch_ch(stdin, ch);
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
        sum_ch = fsearch_ch(fp, ch);
        printf("The \"%s\" file consists of %d characters \'%c\'.\n", 
            argv[i], sum_ch, ch);
    }
    
    return 0;
}

int fsearch_ch(FILE * in, char ch)
{
    int count = 0;
    int temp;

    while ((temp = getc(in)) != EOF)
        if (temp == ch)
            count++;

    return count;
}
