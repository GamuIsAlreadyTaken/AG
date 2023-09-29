#include <stdlib.h>
#include <stdio.h>
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

    print_vector_double(times, EXP_INCREMENT_STEPS);
}

int main()
{
    init_rand_seed();
    time_sumaSubMax1();
    return 0;
}