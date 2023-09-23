/* exercise3.c -- Chapter 13 */
#include <stdio.h>
#include <stdlib.h>     // for exit()
#include <ctype.h>      // for toupper()

#define SIZE 40
char * s_gets(char *, int);

int main(void)
{
    char fname_src[SIZE], fname_trg[SIZE];
    FILE * fp_src, * fp_trg;
    char ch;

    puts("Enter the filename of source file:");
    s_gets(fname_src, SIZE);
    puts("Enter the filename of target file");
    s_gets(fname_trg, SIZE);

    if ((fp_src = fopen(fname_src, "r")) == NULL)
    {
        fprintf(stderr, "Cannot open file %s\n", fname_src);
        exit(EXIT_FAILURE);
    }
    if ((fp_trg = fopen(fname_trg, "w")) == NULL)
    {
        fprintf(stderr, "Cannot open file %s\n", fname_trg);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp_src)) != EOF)
    {
        ch = toupper(ch);
        putc(ch, fp_trg);
    }
    
    fclose(fp_src);
    fclose(fp_trg);
    
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;

    ret_val = fgets(st, n, stdin);

    if (ret_val)
    {
        while (*st != '\n' && *st)
            st++;

        if ('\n' == *st)
            *st = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
