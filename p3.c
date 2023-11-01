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
    time_crearMonticulo();
}

void crearMonticulo(int v[], int n, pmonticulo m)
{
    // Copiar el vector en el struct del monticulo
    for (int i = 0; i < n; i++)
        m->vector[i] = v[i];
    m->ultimo = n;

    for (int i = m->ultimo / 2; i >= 0; i--)
        hundir(m, i);
}

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

int quitarMenor(pmonticulo m)
{
    int x;
    if (monticuloVacio(m))
        assert(0 && "Monticulo vacio");
    x = m->vector[0];
    m->vector[0] = m->vector[m->ultimo - 1];
    m->ultimo -= 1;
    if (!monticuloVacio(m))
        hundir(m, 0);
    return x;
}

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