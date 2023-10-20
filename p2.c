#include "p2.h"
#include "bootstrap.h"
#include <stdio.h>
#include <stdbool.h>

int main()
{
    init_rand_seed();
    test_ord_ins();
    test_ord_shell();

    // time_ord_ins_rand();
    // time_ord_ins_asc();
    // time_ord_ins_desc();
    // time_ord_shell_rand();
    // time_ord_shell_asc();
    // time_ord_shell_desc();
}

// Algoritmo 1
void ord_ins(int v[], int n) // Mejor : linear, Peor : n^2, Medio : n^2
{
    int x, j;
    for (int i = 1; i < n; i++)
    {
        x = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > x)
        {
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
            while (j - incremento >= 0 && seguir) // mejor caso : const
            {
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

// TODO determinar la complejidad algoritmica
double unknown(double n)
{
#include <assert.h>
    assert(false && "Falta determinar la complejidad algoritmica");
    return n;
}

// ORD_INS
void time_ord_ins_rand()
{
    MEASURE_TIME_TABLE(aleatorio, ord_ins,
                       "unknown", "unknown", "unknown",
                       unknown, unknown, unknown);
}

void time_ord_ins_asc()
{
    MEASURE_TIME_TABLE(ascencente, ord_ins,
                       "unknown", "unknown", "unknown",
                       unknown, unknown, unknown);
}

void time_ord_ins_desc()
{
    MEASURE_TIME_TABLE(descendente, ord_ins,
                       "unknown", "unknown", "unknown",
                       unknown, unknown, unknown);
}

// ORD_SHELL
void time_ord_shell_rand()
{
    MEASURE_TIME_TABLE(aleatorio, ord_shell,
                       "unknown", "unknown", "unknown",
                       unknown, unknown, unknown);
}

void time_ord_shell_asc()
{
    MEASURE_TIME_TABLE(ascencente, ord_shell,
                       "unknown", "unknown", "unknown",
                       unknown, unknown, unknown);
}

void time_ord_shell_desc()
{
    MEASURE_TIME_TABLE(descendente, ord_shell,
                       "unknown", "unknown", "unknown",
                       unknown, unknown, unknown);
}
