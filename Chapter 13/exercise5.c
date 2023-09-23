// exercise5.c -- Chapter 13 
#include <stdio.h>
#include <stdlib.h>     // for exit(), atoi()
#include <string.h>     // for strlen()
#include <ctype.h>      // for isdigit()

#define ARSIZE 1000
void set_array_double(double ar[], int n);

int main(int argc, char ** argv)
{
    double numbers[ARSIZE];
    double value;
    int i;
    long pos;
    FILE * iofile;

    if (argc != 3)
    {
        puts("Invalid number of arguments.");
        puts("Usage:");
        printf("%s <filename> <number >= 0>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // Checking that argv[2] consists of alphanumeric characters only.
    for (i = 0; i < strlen(argv[2]); i++)
        if (!isdigit(argv[2][i]))
        {
            puts("Incorrect argv[2] entered.");
            puts("Usage:");
            printf("%s <filename> <number >= 0>\n", argv[0]);
            exit(EXIT_FAILURE);
        }

    // Creating a set of values double.
    set_array_double(number, ARSIZE);

    // It is trying to open a file.
    if ((iofile = fopen(argv[1], "wb")) == NULL)
    {
        fprintf(stderr, "Couldn't open file %s for output.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    // It is writing to an array file in BINARY!!! format.
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);     // It is good tone in programming.

    if ((iofile = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Couldn't open file %s for random access.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // It is reading chosen elements from the file.
    // It is re-initialization of the "i" variable.
    i = atoi(argv[2]);
    pos = (long) i * sizeof(double);    // calculating offset
    fseek(iofile, pos, SEEK_SET);       // move to the desired position
        
    fread(&value, sizeof(double), 1, iofile);
    printf("At this index, the value %f is found.\n", value);

    fclose(iofile);
        
    return 0;
}

void set_array_double(double ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        ar[i] = 100.0 * i + 1.0 / (i + 1);
}
