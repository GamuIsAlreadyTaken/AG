#include <stdio.h>
#include <stdlib.h>
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
    double (*f1)(double),
    double (*f2)(double),
    double (*f3)(double))
{
    int n;
    printf("$ ./p1\n");
    printf("%5s%15s\t%15s\t%15s\t%15s\n", "n", "t(n)", "t(n)/n^1.8", "t(n)/n^2", "t(n)/n^2.2");
    for (int i = 0; i < sizeof(n); i++)
    {
        n = EXP_INCREMENT_START * pow(EXP_INCREMENT_BASE, i);
        printf("%5d%15.5lf\t%15.7lf\t%15.7lf\t%15.7lf\n",
               n, tiempos[i],
               tiempos[i] / f1(n),
               tiempos[i] / f2(n),
               tiempos[i] / f3(n));
    }
}
