#include <stdlib.h>
#include <stdio.h>
#include "p0.h"
#include "bootstrap.h"

int main()
{
    init_rand_seed();
    test1();
    // test2();
    return 0;
}

int sumaSubMax1(int v[], int n)
{
    int sumaMax = 0;
    int estaSuma, i, j;
    for (i = 0; i < n; i++)
    {
        estaSuma = 0;
        for (j = i; j < n; j++)
        {
            estaSuma += v[j];
            if (estaSuma > sumaMax)
                sumaMax = estaSuma;
        }
    }
    return sumaMax;
}

int sumaSubMax2(int v[], int n)
{
    int i;
    int estaSuma = 0;
    int sumaMax = 0;
    for (i = 0; i < n; i++)
    {
        estaSuma += v[i];
        if (estaSuma > sumaMax)
            sumaMax = estaSuma;
        else if (estaSuma < 0)
        {
            estaSuma = 0;
        }
    }
    return sumaMax;
}

void test1()
{
    int n = 500;
    int repeats = 7;
    int i;
    int *v;
    double times[repeats * 2];
    for (i = 0; i < repeats; i++)
    {
        v = calloc(n, sizeof(int));
        rand_fill_int(v, n);

        times[2 * i] = time_it$(sumaSubMax1(v, n));
        times[2 * i + 1] = time_it$(sumaSubMax2(v, n));

        free(v);
        n *= 2;
    }
    print_vector_double(times, repeats * 2);
}

void test2()
{
    int i, a, b;
    int v[9];
    printf("test\n");
    printf("%33s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");
    for (i = 0; i < 10; i++)
    {
        rand_fill_int(v, 9);
        print_vector_int(v, 9);
        a = sumaSubMax1(v, 9);
        b = sumaSubMax2(v, 9);
        printf("%15d%15d\n", a, b);
    }
}

void test3()
{
    int *v;
    double times[7];
    exponential_increment$({
        v = calloc(n, sizeof(int));
        rand_fill_int(v, n);

        times[i] = time_it$(sumaSubMax1(v, n));

        free(v);
    });
    print_vector_double(times, 7);
}