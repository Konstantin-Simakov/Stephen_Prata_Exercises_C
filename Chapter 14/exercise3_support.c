// exercise3_support.c
#include <stdio.h>              // for stdin, puts(), scanf(), printf()
#include <string.h>             // for strchr()
#include "exercise3_head.h"     // for template of the structure

static char * s_gets(char * str, int n);
static void eatline(void);

// returns the number of successfully read structures
int init_struct_arr(struct book lib[], int num)     // num is a number of elements in the structure array
{
    int count = 0;      // the number of successfully read structures

    puts("Enter the title of your first book:");
    while (count < num && s_gets(lib[count].title, LEN) && lib[count].title[0])
    {
        puts("Now enter the author's name of this book:");
        s_gets(lib[count].author, LEN);
        puts("Now enter the value of this book:");
        printf("$_____\b\b\b\b\b");
        scanf("%f", &lib[count].value);
        eatline();

        if (++count < num)
            puts("Enter the title of your next book "
                "(or enter an empty line):");
    }

    return count;
}

void sort_struct_title(struct book lib[], int n)
{
    int top, seek;
    struct book temp;

    for (top = 0; top < n - 1; top++)
        for (seek = top + 1; seek < n; seek++)
            if (strcmp(lib[top].title, lib[seek].title) > 0)
            {
                temp = lib[top];
                lib[top] = lib[seek];
                lib[seek] = temp;
            }
}

void sort_struct_value(struct book lib[], int n)
{
    int top, seek;
    struct book temp;

    for (top = 0; top < n - 1; top++)
        for (seek = top + 1; seek < n; seek++)
            if (lib[top].value > lib[seek].value)
            {
                temp = lib[top];
                lib[top] = lib[seek];
                lib[seek] = temp;
            }
}

void output_struct_arr(const struct book lib[], int n)
{
    int i;

    if (n > 0)
    {
        puts("Your book library:");
        for (i = 0; i < n; i++)
            printf("%s by %s: $%.2f\n", 
                lib[i].title, lib[i].author, lib[i].value);
    }
    else
        puts("There are no books in your library.");
}

static char * s_gets(char * str, int n)
{
    char * ret_val, * find;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}

static void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
