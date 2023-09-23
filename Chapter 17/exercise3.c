/* exercise3.c -- Chapter 17                                        */
/*                compile with exercise3_support.c                  */
#include <stdio.h>
#include <string.h>                     /* for strchr()                         */
#include <stdlib.h>                     /* prototype for exit(), EXIT_FAILURE   */
#include "exercise3.h"                  /* definition of List, Item             */

void eatline(void);
char * s_gets(char * str, int n);
void showmovies(Item item);             /* Item is a structure                  */
void displaying(const List * plist);

int main(void)
{
    List movies;
    Item temp;

    /* initialization */
    initialize_list(&movies);
    if (list_is_full(&movies))
    {
        fputs("There is no available memory. "
            "The program has ended.\n", stderr);
        exit(EXIT_FAILURE);
    }

    /* collection and storage of information */
    puts("Enter the first film title:");
    while (s_gets(temp.title, TSIZE) != NULL && 
        temp.title[0] != '\0')
    {
        puts("Enter your rating value <0-10>:");
        scanf("%d", &temp.raiting);
        eatline();
        if (add_item(&movies, temp) == false)
        {
            fputs("There is a memory allocation problem.\n", stderr);
            break;
        }
        if (list_is_full(&movies))
        {
            puts("The list is full.");
            break;
        }

        puts("Enter the next film title:");
    }
    displaying(&movies);

    /* freeing */
    empty_the_list(&movies);
    puts("The program has ended.");
    
    return 0;
}

void displaying(const List * plist)
{
    if (list_is_empty(plist))
        puts("There is no input data.");        /* on the screen or another output file */
    else
    {
        puts("The film list:");
        traverse(plist, showmovies);
    }
    printf("You have entered %u movie(s).\n", list_item_count(plist));
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void showmovies(Item item)
{
    printf("Film: %s  Raiting: %d\n", item.title, item.raiting);
}

char * s_gets(char * str, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            eatline();
    }

    return ret_val;
}
