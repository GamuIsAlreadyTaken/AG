
#include "bootstrap.h"
#include <stdio.h>
#include <stdbool.h>

/* Ordenar ascendentemente un vector con el siguiente algoritmo
procedimiento ordenar (var v[1..n]
	
*/

void ordenar(int v[], int n)
{ 
	int x;
    int i = 1;
    int j = n;

/*el pseudocodigo que da
mientras i < j hacer
    x:= v[i]
    v[i] = v[j]
    v[j] = x
    i = i + 1
    j = j - 1
fin mientras;
*/
    while (i < j){ 
    	x = v[i];
    	v[i] = v[j];
    	v[j] = x;

    	i = i + 1;
    	j = j -1;

    };

    for (i = n-1; i < n; i++) //para i = n - 1 hasta 1 paso -1 hacer
    {
    	x = v[i];
    	j = i + 1;

    	while(j <= n && v[j] < x){ //mientras j <= n y v[j] < x hacer
    		v[j-1] = v[j];
    		j = j + 1;
    	};
    	v[j-1] = x;
    }
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
double n_to_1_25(double n)
{
    return pow(n, 1.25);
}
double n_to_1_2(double n)
{
    return pow(n, 1.2);
}
double n_to_1_4(double n)
{
    return pow(n, 1.4);
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
double nlogn_to_1_25(double n)
{
    return pow(n * log(n), 1.25);
}



void test_ordenar()
{
    const int n = 10;
    int v[10] = {0};

    printf("Test ordenado\n");
    aleatorio(v, n); // Test con inicialización aleatoria

    printf("Aleatorio:\t");
    listar_vector(v, n);

    ordenar(v, n);

    printf("Ordenado:\t");
    listar_vector(v, n);

    ascendente(v, n); // Test con inicialización descendente

    printf("\nAscendente:\t");
    listar_vector(v, n);

    ordenar(v, n);

    printf("Ordenado:\t");
    listar_vector(v, n);

    descendente(v, n); // Test con inicialización descendente

    printf("\nDescendente:\t");
    listar_vector(v, n);

    ordenar(v, n);
    
}

int main()
{
    inicializar_semilla();
    test_ordenar();

    printf("\n");

    /*printf("ORDENAR\n");

    printf("************ ALEATORIO ************\n");
    MEASURE_TIME_TABLE(aleatorio, ordenar(v, n),
                       "n*logn", "n^1.2", "n^1.4",
                       nlogn, n_to_1_2, n_to_1_4);

    printf("************ ASCENDENTE ************\n");
    MEASURE_TIME_TABLE(ascendente, ordenar(v, n),
                       "(n*log n)^0.8", "n*log(n)", "(n*log n)^1.25",
                       nlogn_to_0_8, nlogn, nlogn_to_1_25);

	printf("************ DESCENDENTE ************\n");
    MEASURE_TIME_TABLE(descendente, ordenar(v, n),
                       "(n*log n)^0.8", "n*log n", "(n*log n)^1.25",
                       nlogn_to_0_8, nlogn, nlogn_to_1_25);
    */

    printf("\n");

}
