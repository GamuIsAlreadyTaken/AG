
#include "bootstrap.h"
#include <stdio.h>
#include <stdbool.h>

/* Ordenar ascendentemente un vector con el siguiente algoritmo
procedimiento ordenar (var v[1..n]
	
*/

void ord_ins(int v[], int n)
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

// Algoritmo 1
void ord_ins(int v[], int n)
{ // Mejor : linear, Peor : n^2, Medio : n^2
    int x, j, i;

    for (i = 1; i < n; i++)
    {
        x = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > x)
        { // mejor caso const
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = x;
    }
}


int main()
{
    inicializar_semilla();
    test_ord();

    printf("\n");

    printf("ORDENAR\n");
    time_ord_ins_rand();
    time_ord_ins_asc();
    time_ord_ins_desc();

    printf("\n");

}
