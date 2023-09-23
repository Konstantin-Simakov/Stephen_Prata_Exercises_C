// exercise5.c -- Chapter 14 
#include "exercise5_head.h"

int main(void)
{
    struct student group[CSIZE];        // group consists of CSIZE students
    int stop;

    stop = init_struct_arr(group, CSIZE);
    output_struct_arr(group, stop);

    return 0;
}
