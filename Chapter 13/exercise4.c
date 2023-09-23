/* exercise4.c -- Chapter 13 */
#include <stdio.h>
#include <stdlib.h>     // for exit()

// Here you can choose any value that is more than 0.
#define BUFFER 20

int main(int argc, char * argv[])
{
    int i;
    FILE * fp;
    char temp[BUFFER];

    if (argc < 2)
    {
        puts("Too few arguments.");
        puts("Usage:");
        printf("%s argv[1] argv[2] ... argv[n]\n", argv[0]);
        puts("(With at least one (with at least argv[1]) "
            "additional command-line argument besides the program name.)");
        exit(EXIT_FAILURE);
    }

    for (i = 1; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Cannot open file %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        while (fgets(temp, BUFFER, fp) != NULL)
            fputs(temp, stdout);
        fclose(fp);
    }

    return 0;
}
