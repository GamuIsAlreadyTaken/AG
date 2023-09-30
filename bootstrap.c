#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#include "bootstrap.h"

void init_rand_seed()
{
    srand(time(NULL));
}

void rand_fill_int(int v[], int n)
{
    int i, m = 2 * n + 1;
    for (i = 0; i < n; i++)
        v[i] = (rand() % m) - n;
}

double get_micro_seconds()
{
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

void print_vector_int(int v[], int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++)
    {
        printf("% d ", v[i]);
    }
    printf("]");
}

void print_vector_double(double v[], int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++)
    {
        printf("% f ", v[i]);
    }
    printf("]");
}

void print_table(
    double tiempos[],
    char *f1_name, char *f2_name, char *f3_name,
    double (*f1)(double), double (*f2)(double), double (*f3)(double))
{
    int n;
    printf("$ ./p1\n");

    char a[15] = "t(n)/";
    char b[15] = "t(n)/";
    char c[15] = "t(n)/";

    strncat(a, f1_name, 10);
    strncat(b, f2_name, 10);
    strncat(c, f3_name, 10);

    printf("%5s%15s\t%15s\t%15s\t%15s\n",
           "n",
           "t(n)",
           a,
           b,
           c);

    for (int i = 0; i < EXP_INCREMENT_STEPS; i++)
    {
        n = EXP_INCREMENT_START * pow(EXP_INCREMENT_BASE, i);
        printf("%5d%15.5lf\t%15.7lf\t%15.7lf\t%15.7lf\n",
               n,
               tiempos[i],
               tiempos[i] / f1(n),
               tiempos[i] / f2(n),
               tiempos[i] / f3(n));
    }
}
