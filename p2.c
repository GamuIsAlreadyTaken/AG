#include "p2.h"
#include "bootstrap.h"
#include <stdio.h>
#include <stdbool.h>

int main()
{
    init_rand_seed();
    // test_ord_ins();
    // test_ord_shell();

    // printf("INSERTION SORT\n");
    // time_ord_ins_rand();
    // time_ord_ins_asc();
    // time_ord_ins_desc();

    // printf("\n");

    // printf("INSERTION SHELL\n");
    time_ord_shell_rand();
    time_ord_shell_asc();
    time_ord_shell_desc();
}

// Algoritmo 1
void ord_ins(int v[], int n)
{ // Mejor : linear, Peor : n^2, Medio : n^2
    int x, j;

    for (int i = 1; i < n; i++)
    {
        x = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > x)
        { // mejor caso const
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = x;
    }
}

// Algoritmo 2
void ord_shell(int v[], int n)
{
    int incremento = n;
    int j, tmp;
    bool seguir;

    do
    {
        incremento = incremento / 2;

        for (int i = incremento; i < n; i++)
        {
            tmp = v[i];
            j = i;
            seguir = true;

            while (j - incremento >= 0 && seguir)
            { // mejor caso : const

                if (tmp < v[j - incremento])
                {
                    v[j] = v[j - incremento];
                    j = j - incremento;
                }
                else
                    seguir = false;
            }
            v[j] = tmp;
        }
    } while (incremento != 1);
}

// Tests //MAYBE move to bootstrap
void test_ord_ins()
{
    const int n = 10;
    int v[10] = {0};

    printf("Test insertion sort\n");
    aleatorio(v, n); // Test con inicialización aleatoria

    printf("Aleatorio:\t");
    print_vector_int(v, n);

    ord_ins(v, n);

    printf("Ordenado:\t");
    print_vector_int(v, n);

    descendente(v, n); // Test con inicialización descendente

    printf("\nDescendente:\t");
    print_vector_int(v, n);

    ord_ins(v, n);

    printf("Ordenado:\t");
    print_vector_int(v, n);
}

void test_ord_shell()
{
    const int n = 10;
    int v[10] = {0};

    printf("Test shell sort\n");
    aleatorio(v, n); // Test con inicialización aleatoria

    printf("Aleatorio:\t");
    print_vector_int(v, n);

    ord_shell(v, n);

    printf("Ordenado:\t");
    print_vector_int(v, n);

    descendente(v, n); // Test con inicialización descendente

    printf("\nDescendente:\t");
    print_vector_int(v, n);

    ord_shell(v, n);

    printf("Ordenado:\t");
    print_vector_int(v, n);
}

double n_to_1_8(double n)
{
    return pow(n, 1.8);
}
double n_squared(double n)
{
    return n * n;
}
double n_to_2_2(double n)
{
    return pow(n, 2.2);
}
double n_to_1_2(double n)
{
    return pow(n, 1.2);
}
double linear(double n)
{
    return n;
}
double n_to_0_8(double n)
{
    return pow(n, 0.8);
}
double nlogn(double n)
{
    return n * log(n);
}
double nlogn_to_0_8(double n)
{
    return pow(n * log(n), 0.8);
}
double nlogn_to_1_2(double n)
{
    return pow(n * log(n), 1.2);
}

// ORD_INS
void time_ord_ins_rand()
{
    printf("************ ALEATORIO ************\n");
    MEASURE_TIME_TABLE(aleatorio, ord_ins,
                       "n^1.8", "n^2", "n^2.2",
                       n_to_1_8, n_squared, n_to_2_2);
}

void time_ord_ins_asc()
{
    printf("************ ASCENDENTE ************\n");
    MEASURE_TIME_TABLE(ascencente, ord_ins,
                       "n^0.8", "n", "n^1.2",
                       n_to_0_8, linear, n_to_1_2);
}

void time_ord_ins_desc()
{
    printf("************ DESCENDENTE ************\n");
    MEASURE_TIME_TABLE(descendente, ord_ins,
                       "n^1.8", "n^2", "n^2.2",
                       n_to_1_8, n_squared, n_to_2_2);
}

// ORD_SHELL
// No es el peor caso, el while mas interno de media se va ejecutar varias veces
void time_ord_shell_rand()
{
    printf("************ ALEATORIO ************\n");
    MEASURE_TIME_TABLE(aleatorio, ord_shell,
                       "(n*log n)^0.8", "n*log n", "(n*log n)^1.2",
                       nlogn_to_0_8, nlogn, nlogn_to_1_2);
}
// Es el mejor caso, el while mas interno no se ejecuta
void time_ord_shell_asc()
{
    printf("************ ASCENDENTE ************\n");
    MEASURE_TIME_TABLE(ascencente, ord_shell,
                       "(n*log n)^0.8", "n*log n", "(n*log n)^1.2",
                       nlogn_to_0_8, nlogn, nlogn_to_1_2);
}
// Descendente no es el peor caso, de hecho es relativamente bueno
// Por que el while mas interno solo se ejecuta 1 vez
void time_ord_shell_desc()
{
    printf("************ DESCENDENTE ************\n");
    MEASURE_TIME_TABLE(descendente, ord_shell,
                       "(n*log n)^0.8", "n*log n", "(n*log n)^1.2",
                       nlogn_to_0_8, nlogn, nlogn_to_1_2);
}
