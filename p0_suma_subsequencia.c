
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int sumaSubMax1(int v[], int n)
{
    int sumaMax = 0;
    int estaSuma;

    for (int i = 0; i < n; i++)
    {
        estaSuma = 0;
        for (int j = i; j < n; j++)
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
    int estaSuma = 0;
    int sumaMax = 0;
    for (int j = 0; j < n; j++)
    {
        estaSuma += v[j];
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
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("% d ", v[i]);
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

// void test1()
// {
// }

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
    int v_rand[5];
    int v1[5] = {-9, 2, -5, -4, 6};
    int v2[5] = {4, 0, 9, 2, 5};

    // printf("%d\n", sumaSubMax1(v1, 5));
    // printf("%d\n", sumaSubMax1(v2, 5));

    // printf("%d\n", sumaSubMax2(v1, 5));
    // printf("%d\n", sumaSubMax2(v2, 5));

    // aleatorio(v_rand, 5);
    // printf("%d\n", sumaSubMax2(v_rand, 5));

    inicializar_semilla();
    test2();

    // test1();
    // test2();
    return 0;
}