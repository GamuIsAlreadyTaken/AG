#include "p2.h"
#include "bootstrap.h"
#include <stdio.h>
#include <stdbool.h>

// Tests //TODO move to bootstrap
void test_ins_sort()
{
    const int n = 10;
    int v[n] = {};
    // Test con inicialización aleatoria
    rand_fill_int(v, n);

    printf("Vector aleatoriamente ordenado: \n");
    print_vector_int(v, n);

    ord_ins(v, n);

    printf("Vector ordenado: \n");
    print_vector_int(v, n);

    // Test con inicialización descendente
    desc_fill_int(v, n);

    printf("Vector ordenado descendente: \n");
    print_vector_int(v, n);

    ord_ins(v, n);

    printf("Vector ordenado: \n");
    print_vector_int(v, n);
}
void test_shell_sort()
{
    const int n = 10;
    int v[n] = {};
    // Test con inicialización aleatoria
    rand_fill_int(v, n);

    printf("Vector aleatoriamente ordenado: \n");
    print_vector_int(v, n);

    ord_shell(v, n);

    printf("Vector ordenado: \n");
    print_vector_int(v, n);

    // Test con inicialización descendente
    desc_fill_int(v, n);

    printf("Vector ordenado descendente: \n");
    print_vector_int(v, n);

    ord_shell(v, n);

    printf("Vector ordenado: \n");
    print_vector_int(v, n);
}

// Algoritmo 1

// Algoritmo 2

void ord_shell(int v[], int n)
{
    int incremento = n;
    int j;
    int tmp;
    bool seguir;
    while (incremento != 1)
    {
        incremento = incremento / 2;
        for (int i = 0; i < n; i++)
        {
            tmp = v[i];
            j = i;
            seguir = true;
            while (j - incremento > 0)
            {
                if (tmp < v[j - incremento])
                {
                    v[j] = v[j - incremento];
                    j = j - incremento;
                }
                else
                {
                    seguir = false;
                }
            }
            v[j] = tmp;
        }
    }
}
