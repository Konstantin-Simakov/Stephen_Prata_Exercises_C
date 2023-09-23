// add_file5.c -- for exercise5.c support module,
// function definition

double difference(double x, double y)
{
    return x - y;
}

double biggest(double ar[], int n)
{
    int i;
    double max;

    max = ar[0];

    for (i = 1; i < n; i++)
        if (max < ar[i])
            max = ar[i];

    return max;
}

double smallest(double ar[], int n)
{
    int i;
    double min;

    min = ar[0];

    for (i = 1; i < n; i++)
        if (min > ar[i])
            min = ar[i];

    return min;
}
