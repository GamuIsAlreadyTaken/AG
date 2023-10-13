#include "p2.h"
#include "bootstrap.h"
#include <stdio.h>
#include <stdbool.h>

int main()
{
    init_rand_seed();
    test_ord_ins();
    test_ord_shell();
}

// Algoritmo 1
void ord_ins(int v[], int n)
{
    int x, j;
    for (int i = 1; i < n; i++)
    {
        x = v[i];
        j = i - 1;
        while (j > 0 && v[j] > x)
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
            while (j - incremento > 0 && seguir)
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

// Tests //TODO move to bootstrap
void test_ord_ins()
{
    printf("Test insertion sort\n");
    const int n = 10;
    int v[10] = {0};
    // Test con inicialización aleatoria
    aleatorio(v, n);

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
    printf("Test shell sort\n");

    const int n = 10;
    int v[10] = {0};
    // Test con inicialización aleatoria
    aleatorio(v, n);

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
    printf("Du nono");
    return -1;
}

// ORD_INS
void time_ord_ins_rand()
{
    MEASURE_TIME_TABLE$(aleatorio, ord_ins,
                        "unknown", "unknown", "unknown",
                        unknown, unknown, unknown);
}
void time_ord_ins_asc()
{
    MEASURE_TIME_TABLE$(ascencente, ord_ins,
                        "unknown", "unknown", "unknown",
                        unknown, unknown, unknown);
}
void time_ord_ins_desc()
{
    MEASURE_TIME_TABLE$(descendente, ord_ins,
                        "unknown", "unknown", "unknown",
                        unknown, unknown, unknown);
}

// ORD_SHELL
void time_ord_shell_rand()
{
    MEASURE_TIME_TABLE$(aleatorio, ord_shell,
                        "unknown", "unknown", "unknown",
                        unknown, unknown, unknown);
}
void time_ord_shell_asc()
{
    MEASURE_TIME_TABLE$(ascencente, ord_shell,
                        "unknown", "unknown", "unknown",
                        unknown, unknown, unknown);
}
void time_ord_shell_desc()
{
    MEASURE_TIME_TABLE$(descendente, ord_shell,
                        "unknown", "unknown", "unknown",
                        unknown, unknown, unknown);
}
