// exercise5_support.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>         // for exit(), EXIT_FAILURE
#include "exercise5_head.h"

static char * s_gets(char * str, int n);
static void eatline(void);
static void init_grades(struct student * person);
static void average_value(struct student * person);

int init_struct_arr(struct student group[], int num)
{
    int count = 0;
    int i; 

    puts("Enter the first name of the student (or empty line to quit).");
    while (s_gets(group[count].sname.fname, LEN) != NULL && 
        group[count].sname.fname[0] != '\0')
    {
        puts("Enter the last name of the student (or empty line to quit).");
        if (s_gets(group[count].sname.lname, LEN) == NULL || 
            group[count].sname.lname[0] == '\0')
                break;

        printf("Enter the grades: %d times.\n", GRADES);
        init_grades(&group[count]);
        for (i = 0; i < GRADES; i++)
            scanf("%f", &group[count].grade[i]);
        eatline();

        average_value(&group[count]);

        if (++count < num)
            puts("Enter the first name of the student (or empty line to quit).");
    }
    if (0 == count)
    {
        puts("There are no any students in this group.");
        exit(EXIT_FAILURE);
    }

    return count;
}

void output_struct_arr(const struct student group[], int n)
{
    int i, j;

    // table header
    printf("%12s %20s %28s\n", 
        "Full name", "Grades", "Average of grades");
    // table contents
    for (i = 0; i < n; i++)
    {
        printf("%s %-9s ", group[i].sname.fname, group[i].sname.lname);
        for (j = 0; j < GRADES; j++)
            printf("%6.2f ", group[i].grade[j]);
        printf("%14.2f\n", group[i].average);
    }
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

// initial values for grade array
static void init_grades(struct student * person)
{
    int i;

    for (i = 0; i < GRADES; i++)
        person->grade[i] = 0.0f;
}

static void average_value(struct student * person)
{
    int i;
    float sum = 0.0f;

    for (i = 0; i < GRADES; i++)
        sum += person->grade[i];
    
    person->average = sum / GRADES;
}
