#include "bootstrap.h"

void intercambiar(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void auxOrd(int v[], int izq, int der)
{
    if (izq < der)
    {
        int piv = v[der - 1];

        intercambiar(&v[izq], &v[der - 1]);

        int i = izq + 1;
        int j = der;

        while (i <= j)
        {
            while (v[j] > piv)
                j -= 1;

            while (i <= der && v[i] < piv)
                i += 1;

            if (i <= j)
            {
                intercambiar(&v[i], &v[j]);
                i += 1;
                j -= 1;
            }
        }
        intercambiar(&v[izq], &v[j]);
        auxOrd(v, izq, j - 1);
        auxOrd(v, j + 1, der);
    }
}

void ordenar(int v[], int n)
{
    auxOrd(v, 0, n - 1);
}

void testOrdenar()
{
#define _n 9
    int nums[_n];
    aleatorio(nums, _n);
    listar_vector(nums, _n);

    ordenar(nums, _n);
    listar_vector(nums, _n);
#undef _n
}

double nlogn(double n)
{
    return n * log(n);
}
double linear(double n)
{
    return n;
}
double n_to_1_3(double n)
{
    return pow(n, 1.3);
}
double n_to_2(double n)
{
    return pow(n, 2);
}
double n_to_1_8(double n)
{
    return pow(n, 1.8);
}
double n_to_2_2(double n)
{
    return pow(n, 2.2);
}

int main()
{
    inicializar_semilla();
    testOrdenar();


    // MEASURE_TIME_TABLE(descendente, ordenar(v, n), 
    //     "n^1.8", "n^2", "n^2.2", n_to_1_8, n_to_2, n_to_2_2);

    MEASURE_TIME_TABLE(ascendente, ordenar(v, n), 
        "n^1.8", "n^2", "n^2.2", n_to_1_8, n_to_2, n_to_2_2);

    // MEASURE_TIME_TABLE(aleatorio, ordenar(v, n), 
    //     "n", "nlogn", "n^1.3", linear, nlogn, n_to_1_3);
}