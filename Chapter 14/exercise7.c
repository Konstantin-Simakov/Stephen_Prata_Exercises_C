/* exercise7.c -- Chapter 14 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercise7_head.h"

int main(void)
{
    struct book library[MAXBKS];
    FILE * fp;
    int count, filecount;
    char choice;

    if ((fp = fopen("book.dat", "r+b")) == NULL)
    {
        fputs("Cannot open file \"book.dat\".\n", stderr);
        exit(EXIT_FAILURE);
    }
    filecount = count = output_from_file_binary(library, MAXBKS, fp);
    if (MAXBKS == count)
    {
        fputs("The file \"book.dat\" is full.\n", stderr);
        exit(EXIT_FAILURE);
    }

    /* basic actions */
    while ((choice = action()) != 'q')
    {
        switch (choice)
        {
            case 'a': 
                count = add_entry(library, count);
                break;
            case 'd': 
                delete_entry(library, count);
                count = sort_struct_arr(library, count);
                set_nums(library, count);
                break;
            case 'c': 
                change_entry(library, count);
                break;
            default :               /* optional -- action() will take care of everything about it */
                puts("Error 1");
                exit(EXIT_FAILURE);
        }
        if (!is_empty(&library[0]))
            output_content(library, count);
    }

    rewind(fp);
    output_to_file(library, count, filecount, fp);
    fclose(fp);
    puts("\nThe program has been completed.");
    
    return 0;
}
