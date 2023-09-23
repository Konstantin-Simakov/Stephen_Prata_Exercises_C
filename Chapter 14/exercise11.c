/* exercise11.c -- Chapter 14 */
#include <stdio.h>
#include <math.h>       /* add option for correct compilation of this program: -lm */

#define SIZE 100
#define NUMS 4
#define PI   3.14159

void init_arr(double [], int);
void transform(double [], double [], int, double (*) (double));
double circumference(double);
double area_circle(double);
void output_arrs(const double trg[], const double src[], int n);

int main(void)
{
    double source[SIZE];
    double target[SIZE];
    double (* pfuncs[NUMS]) (double) = { sin, tan, circumference, area_circle };
    int index;

    init_arr(source, SIZE);

    for (index = 0; index < NUMS; index++)
    {
        switch (index)
        {
            case 0: puts("The function: sin()");
                break;
            case 1: puts("The function: tan()");
                break;
            case 2: puts("The function: circumference()");
                break;
            case 3: puts("The function: area_circle()");
                break;
        }
        transform(target, source, SIZE, pfuncs[index]);
        output_arrs(target, source, SIZE);
        if (index < NUMS - 1)
            putchar('\n');
    }

    return 0;
}

void init_arr(double arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        arr[i] = (i + 2) / 3.0;
}

void transform(double trg[], double src[], int n, double (* pfunc) (double))
{
    int i;

    for (i = 0; i < n; i++)
        trg[i] = (*pfunc)(src[i]); 
}

double circumference(double r)
{
    return 2 * PI * r;
}

double area_circle(double r)
{
    return PI * r * r;
}

void output_arrs(const double target[], const double source[], int n)
{
    int i;

    printf("%5s\t %5s\n", "Arg", "Ret_val");
    for (i = 0; i < n; i++)
        printf("%5.1f\t %5.1f\n", source[i], target[i]);
}
