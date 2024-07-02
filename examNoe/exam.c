
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

    while (i < j){ 
    	x = v[j];
    	v[i] = v[j];
    	v[j] = x;

    	i = i + 1;
    	j = j -1;

    };
    for (i = n-1; i < n; i++) //para i = n - 1 hasta 1 paso -1 hacer
    {
    	x = v[i];
    	j = j + 1;

    	while(j <= n && v[j] < x){ //mientras j <= n y v[j] < x hacer
    		v[j-1] = v[j];
    		j = j + 1;
    	};
    	v[j-1] = x;
    }
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

    printf("ORDENAR\n");
    time_ordenar_asc();
    time_ordenar_desc();
    time_ordenar_rand();

    printf("\n");

}
