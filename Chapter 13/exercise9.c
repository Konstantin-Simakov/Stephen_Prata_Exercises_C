/* exercise9.c -- Chapter 13 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void)
{
    FILE * fp;
    char words[MAX];
    int count = 0;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fputs("Cannot open file \"wordy\".\n", stderr);
        exit(EXIT_FAILURE);
    }

    puts("Enter the words for addition to the file; for finish");
    puts("Enter the \'#\' character in begin of the new line.");
    while ((fscanf(stdin, "%40s", words)) == 1 && words[0] != '#')
        fprintf(fp, "%d. %s\n", ++count, words);

    puts("The file contains:");
    rewind(fp);     // back to the begin of file
    while(fgets(words, MAX, fp))
        fputs(words, stdout);
    puts("Done!");

    if (fclose(fp) != 0)
        fputs("An error is occured for the closing file.\n", stderr);
    
    return 0;
}
