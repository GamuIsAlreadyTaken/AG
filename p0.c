#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "p0.h"
#include "bootstrap.h"

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

double cuadratico(double n)
{
    return n * n;
}
double n_to_18(double n)
{
    return pow(n, 1.8);
}
double n_to_22(double n)
{
    return pow(n, 2.2);
}

void time_sumaSubMax1()
{
    int v[LAST_N];
    double t;
    double times[EXP_INCREMENT_STEPS];
    exponential_increment$({
        rand_fill_int(v, n);
        t = time_it$(sumaSubMax1(v, n));

        if (t < TRUSTED_TIME)
        {
            t = time_repeated$(rand_fill_int(v, n), sumaSubMax1(v, n));
        }
        times[i] = t;
    });

    print_table(times, n_to_18, cuadratico, n_to_22);
}

int main()
{
    init_rand_seed();
    time_sumaSubMax1();
    return 0;
}