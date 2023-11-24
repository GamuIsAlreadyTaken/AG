#include <stdio.h>
#include <stdlib.h>

#include "p4.h"
#include "bootstrap.h"

int main()
{
    inicializar_semilla();

    // test_dijkstra_1();
    // test_dijkstra_2();

    time_dijkstra();

    return 0;
}

void test_dijkstra_1()
{
    int tam = 5;
    matriz m = (int *[5]){};
    m[0] = (int[5]){0, 1, 8, 4, 7};
    m[1] = (int[5]){1, 0, 2, 6, 5};
    m[2] = (int[5]){8, 2, 0, 9, 5};
    m[3] = (int[5]){4, 6, 9, 0, 3};
    m[4] = (int[5]){7, 5, 5, 3, 0};

    matriz d_obj = (int *[5]){};
    d_obj[0] = (int[5]){0, 1, 3, 4, 6};
    d_obj[1] = (int[5]){1, 0, 2, 5, 5};
    d_obj[2] = (int[5]){3, 2, 0, 7, 5};
    d_obj[3] = (int[5]){4, 5, 7, 0, 3};
    d_obj[4] = (int[5]){6, 5, 5, 3, 0};

    matriz d = crearMatriz(tam);

    dijkstra(m, d, tam);

    printf("Input:\n");
    print_matriz(m, tam);
    printf("Target:\n");
    print_matriz(d_obj, tam);
    printf("Result:\n");
    print_matriz(d, tam);
    printf("\n");

    liberarMatriz(d, tam);
}

void test_dijkstra_2()
{
    int tam = 4;
    matriz m = (int *[4]){};
    m[0] = (int[4]){0, 1, 4, 7};
    m[1] = (int[4]){1, 0, 2, 8};
    m[2] = (int[4]){4, 2, 0, 3};
    m[3] = (int[4]){7, 8, 3, 0};

    matriz d_obj = (int *[4]){};
    d_obj[0] = (int[4]){0, 1, 3, 6};
    d_obj[1] = (int[4]){1, 0, 2, 5};
    d_obj[2] = (int[4]){3, 2, 0, 3};
    d_obj[3] = (int[4]){6, 5, 3, 0};

    matriz d = crearMatriz(tam);

    dijkstra(m, d, tam);

    printf("Input:\n");
    print_matriz(m, tam);
    printf("Target:\n");
    print_matriz(d_obj, tam);
    printf("Result:\n");
    print_matriz(d, tam);
    printf("\n");

    liberarMatriz(d, tam);
}

double n_to_2_8(double n)
{
    return pow(n, 2.8);
}
double n_to_2_9(double n)
{
    return pow(n, 2.9);
}
double n_to_3(double n)
{
    return pow(n, 3);
}

void time_dijkstra()
{
    matriz m;
    matriz d;
    double t;
    double times[EXP_INCREMENT_STEPS];

    EXPONENTIAL_INCREMENT({
        // Inicializar
        m = crearMatriz(n);
        iniMatriz(m, n);

        d = crearMatriz(n);
        // ^

        t = TIME_IT(dijkstra(m, d, n));
        if (t < TRUSTED_TIME)
            t = TIME_REPEATED({
                // Inicializar
                m = crearMatriz(n);
                iniMatriz(m, n);

                d = crearMatriz(n);
                // ^
            },
                              dijkstra(m, d, n));
        times[i] = t;
    });
    // (n * (n-1) * 2log n )/2 ->
    print_table(times,
                "n^2.8", "n^2.9", "n^3",
                n_to_2_8, n_to_2_9, n_to_3);
}

void print_matriz(matriz m, int tam)
{
    int i, j;
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
            printf("%2d ", m[i][j]);
        printf("\n");
    }
}

matriz crearMatriz(int n)
{
    int i;
    matriz aux;
    if ((aux = malloc(n * sizeof(int *))) == NULL)
        return NULL;
    for (i = 0; i < n; i++)
        if ((aux[i] = malloc(n * sizeof(int))) == NULL)
            return NULL;
    return aux;
}

void iniMatriz(matriz m, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            m[i][j] = rand() % TAM_MAX + 1;
    for (i = 0; i < n; i++)
        for (j = 0; j <= i; j++)
            if (i == j)
                m[i][j] = 0;
            else
                m[i][j] = m[j][i];
}

void liberarMatriz(matriz m, int n)
{
    int i;
    for (i = 0; i < n; i++)
        free(m[i]);
    free(m);
}

void dijkstra(matriz grafo, matriz distancias, int tam)
{

    int n, i, j, min, v = 0;
    int *noVisitados = malloc(tam * sizeof(int));
    for (n = 0; n < tam; n++)
    {
        for (i = 0; i < tam; i++)
        {
            noVisitados[i] = 1;
            distancias[n][i] = grafo[n][i];
        }
        noVisitados[n] = 0;

        for (j = 0; j < tam - 1; j++)
        {
            min = TAM_MAX + 1;
            for (i = 0; i < tam; i++)
            {
                if (distancias[n][i] != 0 &&
                    distancias[n][i] < min &&
                    noVisitados[i])
                {
                    min = distancias[n][i];
                    v = i;
                }
            }
            noVisitados[v] = 0; // noVisitados - { v }
            for (i = 0; i < tam; i++)
            {
                if (!noVisitados[i])
                    continue;

                if (distancias[n][i] > distancias[n][v] + grafo[v][i])
                    distancias[n][i] = distancias[n][v] + grafo[v][i];
            }
        }
    }
    free(noVisitados);
}
