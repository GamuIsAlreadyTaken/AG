#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "p1.h"
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

double n_to_1_8(double n)
{
    return pow(n, 1.8);
}
double cuadratico(double n)
{
    return n * n;
}
double n_to_2_2(double n)
{
    return pow(n, 2.2);
}
double nlogn(double n)
{
    return n * log(n);
}
double lineal(double n)
{
    return n;
}
double logn(double n)
{
    return log(n);
}

void time_sumaSubMax1()
{
    int v[LAST_N];
    double t;
    double times[EXP_INCREMENT_STEPS];
    EXPONENTIAL_INCREMENT({
        aleatorio(v, n);
        t = TIME_IT(sumaSubMax1(v, n));

        if (t < TRUSTED_TIME)
        {
            t = TIME_REPEATED(aleatorio(v, n), sumaSubMax1(v, n));
        }
        times[i] = t;
    });

    print_table(times,
                "n^1.8", "n^2", "n^2.2",
                n_to_1_8, cuadratico, n_to_2_2);
}

void time_sumaSubMax2()
{
    int v[LAST_N];
    double t;
    double times[EXP_INCREMENT_STEPS];
    EXPONENTIAL_INCREMENT({
        aleatorio(v, n);
        t = TIME_IT(sumaSubMax2(v, n));

        if (t < TRUSTED_TIME)
        {
            t = TIME_REPEATED(aleatorio(v, n), sumaSubMax2(v, n));
        }
        times[i] = t;
    });

    print_table(times,
                "log(n)", "n", "n*log(n)",
                logn, lineal, nlogn);
}

int main()
{
    inicializar_semilla();
    time_sumaSubMax1();
    time_sumaSubMax2();
    return 0;
}