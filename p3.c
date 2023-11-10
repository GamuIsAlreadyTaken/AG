#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

#include "p3.h"
#include "bootstrap.h"

int main()
{
    inicializar_semilla();

    test_ordenarPorMonticulos();

    printf("HEAP SORT\n");
    time_crearMonticulo();
}
// Peor caso -> n log n
// Caso medio-> n log n
// Mejor caso-> n
void crearMonticulo(int v[], int n, pmonticulo m)
{
    // Copiar el vector en el struct del monticulo
    for (int i = 0; i < n; i++) // n
        m->vector[i] = v[i];
    m->ultimo = n;

    for (int i = m->ultimo / 2; i >= 0; i--) // (n/2) * hundir -> n * hundir
        hundir(m, i);
}

// Peor caso -> hundir hasta el final -> log n
// Caso medio-> hundir a la mitad -> log (n/2) -> log n
// Mejor caso-> no se hunde nada -> 1
void hundir(pmonticulo m, int i)
{
    int j, hijoIzq, hijoDer, tmp;
    do
    {
        hijoIzq = 2 * i + 1;
        hijoDer = 2 * i + 2;
        j = i;

        if (hijoDer < m->ultimo && m->vector[hijoDer] < m->vector[i])
            i = hijoDer;

        if (hijoIzq < m->ultimo && m->vector[hijoIzq] < m->vector[i])
            i = hijoIzq;

        // Intercambiar m->vector[j] y m->vector[i]
        tmp = m->vector[j];
        m->vector[j] = m->vector[i];
        m->vector[i] = tmp;
    } while (i != j);
}

void listar_monticulo(pmonticulo m)
{
    printf("[ ");
    for (int i = 0; i < m->ultimo; i++)
        printf("%- d ", quitarMenor(m));
    printf("]\n");
}

// Peor caso -> log n
// Caso medio-> log (n/2) -> log n
// Mejor caso-> 1
int quitarMenor(pmonticulo m)
{
    int x;
    if (monticuloVacio(m))
        assert(0 && "Monticulo vacío");
    x = m->vector[0];
    m->vector[0] = m->vector[m->ultimo - 1];
    m->ultimo -= 1;
    if (!monticuloVacio(m)) // hundir
        hundir(m, 0);
    return x;
}
// Todos casos -> 1
bool monticuloVacio(pmonticulo m)
{
    return m->ultimo == 0;
}

void test_ordenarPorMonticulos()
{
    int n = 9;
    struct monticulo m;
    int v[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Target:\t");
    listar_vector(v, n);

    printf("Input:\t");
    descendente(v, n);
    listar_vector(v, n);

    printf("Heap:\t");
    crearMonticulo(v, n, &m);
    listar_vector(m.vector, m.ultimo);

    printf("Output:\t[ ");
    for (int i = 0; i < n; i++)
        printf("%- d ", quitarMenor(&m));
    printf("]\n");
}

void OrdenarPorMonticulo(int v[], int n)
{
    struct monticulo m;
    int i;
    crearMonticulo(v, n, &m);
    for (i = 0; i < n - 1; i++)
    {
        v[i] = quitarMenor(&m);
    }
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

void time_crearMonticulo()
{
    struct monticulo m;
    MEASURE_TIME_TABLE(aleatorio, crearMonticulo(v, n, &m),
                       "n^0.8", "n", "n^1.2",
                       n_to_0_8, linear, n_to_1_2);
}

void time_ordenarPorMonticulos_rand()
{
    struct monticulo m;
    MEASURE_TIME_TABLE(aleatorio, crearMonticulo(v, n, &m),
                       "n^0.8", "n", "n^1.2",
                       n_to_0_8, linear, n_to_1_2);
    // Por determinar complejidad
}
void time_ordenarPorMonticulos_asc()
{
    struct monticulo m;
    MEASURE_TIME_TABLE(ascendente, crearMonticulo(v, n, &m),
                       "n^0.8", "n", "n^1.2",
                       n_to_0_8, linear, n_to_1_2);
    // Por determinar complejidad
}
void time_ordenarPorMonticulos_desc()
{
    struct monticulo m;
    MEASURE_TIME_TABLE(descendente, crearMonticulo(v, n, &m),
                       "n^0.8", "n", "n^1.2",
                       n_to_0_8, linear, n_to_1_2);
    // Por determinar complejidad
}
