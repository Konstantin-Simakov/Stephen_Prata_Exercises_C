/* exercise7_support.c */
#include <stdio.h>
#include <string.h>             /* for strchr() */
#include <ctype.h>              /* for tolower() */
#include <stdbool.h>
#include "exercise7_head.h"     /* for structure template */

/* local (static) function prototypes for this source file */
static void eatline(void);
static bool is_empty_arr(struct book library[], int n);
static char * s_gets(char * str, int n);
static char choice2(void);
static void struct_cpy(struct book * pstruct1, struct book * pstruct2);
static void change(struct book * entry, int num);
static void to_empty(struct book * entry);

bool is_empty(struct book * entry)
{
    bool zero = false;
    struct book temp = { 0 };

    if ((strcmp(entry->title, temp.title) == 0
        || strcmp(entry->author, temp.author) == 0))
            zero = true;

    return zero;
}

char action(void)
{
    char ans;

    puts("\nWhat do you want to do?");
    puts("a) add data to the file;");
    puts("d) delete the entry;");
    puts("c) change the entry;");
    puts("q) quit from the program;");
    ans = tolower(getchar());
    eatline();
    while (strchr("adcq", ans) == NULL)
    {
        puts("You can choose \'a\', \'d\', \'c\', \'q\' only.");
        ans = tolower(getchar());
        eatline();
    }

    return ans;
}

int add_entry(struct book library[], int count)
{
    puts("Enter new titles:");
    puts("Press [enter] in the beginning of the line to finish the input.");
    while (count < MAXBKS && s_gets(library[count].title, LEN) != NULL 
        && library[count].title[0] != '\0')
    {
        puts("Now enter the author's name:");
        if (s_gets(library[count].author, LEN) == NULL 
            || '\0' == library[count].author[0])
        {
            puts("\nIncorrect ahour's name entered.");
            break;
        }
        puts("Now enter the value of this book:");
        if (scanf("%f", &library[count].value) != 1 || library[count].value < 0.0f)
        {
            eatline();
            puts("\nIncorrect value was entered for value of this book.");
            break;
        }
        eatline();
        library[count].number = count + 1;
        
        count++;

        if (count < MAXBKS)
            puts("Enter the next title:");
    }

    return count;
}

void change_entry(struct book library[], int count)
{
    int num;                        /* number of entry; interactively */

    if (count > 0)
    {
        if (1 == count)
            change(&library[count - 1], count);
        else
        {
            puts("What entry do you want to change?");
            printf("Enter the number from 1 to %d "
                "(or \'q\' to return to the menu.)\n", count);
            while (scanf("%d", &num) == 1)
            {
                if (num >= 1 && num <= count)
                {
                    eatline();                          /* for correct work of change() */
                    change(&library[num - 1], num);

                    printf("Enter the next number from 1 to %d "
                        "(or \'q\' to return to the menu.)\n", count);
                }
                else
                    puts("Invalid range.");
            }
            eatline();
        }
    }
    else
        puts("All entries is empty. There is nothing to change. Choose a) or q)");
}

void delete_entry(struct book library[], int count)
{
    int num;                        /* number of entry */

    if (count > 0)
    {
        if (1 == count)
        {
            to_empty(&library[count - 1]);
            printf("The entry %d has been deleted successfully.\n", count);
            puts("All entries is empty. There is nothing more to delete. Choose a) or q)");
        }
        else
        {
            puts("What entry do you want to delete?");
            printf("Enter the number from 1 to %d "
                "(or \'q\' to return to the menu.)\n", count);
            while (scanf("%d", &num) == 1)
            {
                if (num >= 1 && num <= count)
                {
                    if (!is_empty(&library[num - 1]))
                    {
                        to_empty(&library[num - 1]);
                        printf("The entry %d has been deleted successfully.\n", num);

                        printf("Enter the next number from 1 to %d "
                            "(or \'q\' to return to the menu.)\n", count);
                    }
                    else if (is_empty_arr(library, count))
                    {
                        puts("All entries is empty. There is nothing to delete. Choose a) or q)");
                        break;
                    }
                }
                else
                    puts("Invalid range.");
            }
            eatline();      /* "eats" the 'q' character after its input --- */
        }
    }
    else
        puts("All entries is empty. There is nothing to delete. Choose a) or q)");
}

int sort_struct_arr(struct book library[], int count)       /* count is a number of elements in the array */
{
    int i, j;
    struct book temp;

    i = 0;
    while (i < count)
    {
        if (is_empty(&library[i]))
        {
            for (j = i; j < count - 1; j++)
            {
                temp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = temp;
            }
            --count;
            continue;
        }
        i++;
    }

    return count;
}

void set_nums(struct book library[], int count)
{
    int i;

    for (i = 0; i < count; i++)
        library[i].number = i + 1;
}

int output_from_file_binary(struct book library[], int n, FILE * fp)
{
    int count = 0;

    while (count < n && fread(&library[count], sizeof(struct book), 1, fp) == 1 
        && !is_empty(&library[count]))
    {
        if (0 == count)
            puts("There is a current file consist:");
        printf("%d. %s by %s: $%.2f\n", library[count].number, 
            library[count].title, library[count].author, library[count].value);
        count++;
    }

    return count;
}

void output_content(struct book library[], int count)
{
    int i;

    puts("\nCurrent content:");
    for (i = 0; i < count; i++)
        printf("%d. %s by %s: $%.2f\n", 
            library[i].number, library[i].title, library[i].author, library[i].value);
}

void output_to_file(struct book library[], int count, int filecount, FILE * fp)
{
    int i;

    /* output on the screen */
    if (count > 0)
    {
        puts("\nThere is your library:");
        for (i = 0; i < count; i++)
            printf("%d. %s by %s: $%.2f\n", library[i].number, 
                library[i].title, library[i].author, library[i].value);
    }
    else
        fputs("Is there no books at all? It is very bad.\n", stderr);

    /* output in the file in binary mode */
    if (count > filecount)
        fwrite(library, sizeof(struct book), count, fp);
    else
        fwrite(library, sizeof(struct book), filecount, fp);
}


/* local (static) function definitions */

static void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

/* using by change_entry(), num is a number of the entry */
static void change(struct book * entry, int num)
{
    struct book temp;
    bool status = true;         /* to choose: copy or not; true -- copy, false -- not */

    struct_cpy(&temp, entry);
    switch (choice2())
    {
        case '1': puts("Enter the title to this entry:");
            if (s_gets(temp.title, LEN) == NULL || is_empty(&temp))
            {
                puts("An invalid value was entered for title of the book.");
                puts("Source structure won't be changed.");
                status = false;
            }
            break;
        case '2': puts("Enter the author's name:");
            if (s_gets(temp.author, LEN) == NULL || is_empty(&temp))
            {
                puts("An invalid value was entered for author's name.");
                puts("Source structure won't be changed.");
                status = false;
            }
            break;
        case '3': puts("Enter the value of this book:");
            if (scanf("%f", &temp.value) != 1)
            {
                puts("An invalid value was entered for value of the book.");
                puts("Source structure won't be changed.");
                status = false;
            }
            else if (temp.value < 0.0f)
            {
                puts("Invalid range for value of the book.");
                puts("Source structure won't be changed.");
                status = false;
            }
            eatline();
            break;
        default : puts("Error 2");
                status = false;
    }

    if (status)
    {
        struct_cpy(entry, &temp);
        printf("The entry %d has been changed successfully.\n", num);
    }
}

static bool is_empty_arr(struct book library[], int n)
{
    int i, k;
    int nums[n];            /* (c99 -- variable length array) */
    bool empty = true;      /* default value */

    /* default values for the nums array */
    for (k = 0; k < n; k++)
        nums[k] = 0;

    for (k = 0, i = 0; i < n; i++)
        if (!is_empty(&library[i]))
            nums[k++] = i + 1;
    
    if (nums[0] != 0)
    {
        empty = false;
        printf("The next number of entries of the array is non-empty: ");
        for (i = 0; i < k; i++)
            printf("%d, ", nums[i]);
        printf("\b\b.\n");
    }

    return empty;
}

static char * s_gets(char * str, int n)
{
    char * ret_val;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        while (*str != '\n' && *str != '\0')
            str++;
        if ('\n' == *str)
            *str = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}

static char choice2(void)
{
    char ans;

    puts("What structure field do you want to change?");
    puts("1) title      2) ahour's name     3) value of the book");
    ans = getchar();
    eatline();
    while (strchr("123", ans) == NULL)
    {
        puts("Incorrect number entered. Try again:");
        ans = getchar();
        eatline();
    }

    return ans;
}

static void struct_cpy(struct book * pstruct1, struct book * pstruct2)
{
    strcpy(pstruct1->title, pstruct2->title);
    strcpy(pstruct1->author, pstruct2->author);
    pstruct1->value = pstruct2->value;
    pstruct1->number = pstruct2->number;
}

static void to_empty(struct book * entry)
{
    struct book temp = { 0 };

    strcpy(entry->title, temp.title);
    strcpy(entry->author, temp.author);
    entry->value = temp.value;
    entry->number = temp.number;
}
