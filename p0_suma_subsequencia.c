
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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

void listar_vector(int v[], int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++)
    {
        printf("% d ", v[i]);
    }
    printf("]");
}
void listar_vector_double(double v[], int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++)
    {
        printf("% f ", v[i]);
    }
    printf("]");
}

void inicializar_semilla()
{
    srand(time(NULL));
    /* se establece la semilla de una nueva serie de enteros pseudo-aleatorios */
}
void aleatorio(int v[], int n)
{
    int i, m = 2 * n + 1;
    for (i = 0; i < n; i++)
        v[i] = (rand() % m) - n;
    /* se generan números pseudoaleatorio entre -n y +n */
}

double microsegundos()
{ /* obtiene la hora del sistema en microsegundos */
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

double time_it(int (*func)(int v[], int n), int v[], int n)
{
    double start, end;
    start = microsegundos();
    sumaSubMax1(v, n);
    end = microsegundos();
    return end - start;
}

void test1()
{
    int n = 500;     // MACRO
    int repeats = 7; // MACRO
    int i;
    int *v;
    double times[repeats * 2];
    for (i = 0; i < repeats; i++)
    {
        v = calloc(n, sizeof(int));
        aleatorio(v, n);

        times[2 * i] = time_it(sumaSubMax1, v, n);
        times[2 * i + 1] = time_it(sumaSubMax2, v, n);

        free(v);
        n *= 2;
    }
    listar_vector_double(times, repeats * 2);
}

void test2()
{
    int i, a, b;
    int v[9];
    printf("test\n");
    printf("%33s%15s%15s\n", "", "sumaSubMax1", "sumaSubMax2");
    for (i = 0; i < 10; i++)
    {
        aleatorio(v, 9);
        listar_vector(v, 9);
        a = sumaSubMax1(v, 9);
        b = sumaSubMax2(v, 9);
        printf("%15d%15d\n", a, b);
    }
}

int main()
{
    // int v_rand[5];
    // int v1[5] = {-9, 2, -5, -4, 6};
    // int v2[5] = {4, 0, 9, 2, 5};

    // printf("%d\n", sumaSubMax1(v1, 5));
    // printf("%d\n", sumaSubMax1(v2, 5));

    // printf("%d\n", sumaSubMax2(v1, 5));
    // printf("%d\n", sumaSubMax2(v2, 5));

    // aleatorio(v_rand, 5);
    // printf("%d\n", sumaSubMax2(v_rand, 5));

    inicializar_semilla();
    // test2();
    test1();

    // test1();
    // test2();
    return 0;
}