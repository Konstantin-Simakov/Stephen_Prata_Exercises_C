/* exercise6_support.c */
/* compile with exercise6.c */
#include "exercise6_head.h"
#include <stdio.h>
#include <ctype.h>          /* for tolower() */
#include <string.h>         /* for strchr() */

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

char show_menu(void)
{
    int ans;

    putchar('\n');
    puts("f) change font    s) change size    a) align");
    puts("b) bold           i) italic         u) underline");
    puts("q) quit");
    ans = tolower(getchar());
    eatline();
    while (strchr("qfsabiu", ans) == NULL)
    {
        puts("Incorrect letter was entered. Try again:");
        ans = tolower(getchar());
        eatline();
    }

    return ans;
}

void font_id_change(struct font * ptext)
{
    int temp;

    printf("Enter the identifier of the font (integer 0-255): ");
    while (scanf("%d", &temp) != 1)
    {
        eatline();
        printf("Non-digit character was entered. Try again: ");
    }
    eatline();

    if (temp >= 0 && temp <= MAX1)
        ptext->id = temp;
    else
        puts("Invalid range. Source value won't be changed.");
}

void size_change(struct font * ptext)
{
    int temp;

    printf("Enter the size of the font (integer 0-127): ");
    while (scanf("%d", &temp) != 1)
    {
        eatline();
        printf("Non-digit character was entered. Try again: ");
    }
    eatline();

    if (temp >= 0 && temp <= MAX2)
        ptext->size = temp;
    else
        puts("Invalid range. Source value won't be changed.");
}

void align_change(struct font * ptext)
{
    char ans;

    ans = show_menu_2();
    switch (ans)
    {
        case 'l': ptext->align = 0;
            break;
        case 'c': ptext->align = 1;
            break;
        case 'r': ptext->align = 2;
            break;
        default : puts("Error 2");
    }
}

char show_menu_2(void)
{
    char ans;

    puts("Choose the align:");
    puts("l) left\t\t c) center\t\t r) right");

    ans = tolower(getchar());
    eatline();
    while (strchr("lcr", ans) == NULL)
    {
        puts("Incorrect letter was entered. Try again:");
        ans = tolower(getchar());
        eatline();
    }

    return ans;
}

void bold(struct font * ptext)
{
    if (ptext->bold)
        ptext->bold = false;
    else
        ptext->bold = true;
}

void italic(struct font * ptext)
{
    if (ptext->italic)
        ptext->italic = false;
    else
        ptext->italic = true;
}

void underline(struct font * ptext)
{
    if (ptext->underline)
        ptext->underline = false;
    else
        ptext->underline = true;
}

void output_st(const struct font * ptext)
{
    char * str;

    if (0 == ptext->align)
        str = "left";
    else if (1 == ptext->align)
        str = "center";
    else
        str = "right";

    putchar('\n');
    printf("%-8s %-8s %-8s %-8s %-8s %-8s\n", "ID", "SIZE", "ALIGN", "Bold", "Italic", "Underline");
    printf("%-8u %-8u %-8s %-8s %-8s %-8s\n", ptext->id, ptext->size, 
        str, ptext->bold ? "on" : "off", ptext->italic ? "on" : "off", ptext->underline ? "on" : "off");
}
