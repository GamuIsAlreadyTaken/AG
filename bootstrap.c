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

void print_table (int n[], double tiempos[], *funcion1, *funcion2, *funcion3){
    printf("$ ./p1\n");
    printf("\t\tn\t\tt(n)\t\tt(n)/n^1.8\t\tt(n)/n^2\t\tt(n)/n^2.2\n");
    for (int i=0; i<sizeof(n); i++){
        printf("\t\t%s\t\t%d3\t\t%d3\t\t%d3\t\t%d3", n[i], funcion1(tiempos), funcion2(tiempos), funcion3(tiempos));
    }
}
