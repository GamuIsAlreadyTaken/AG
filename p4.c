
#include "p4.h"
#include "bootstrap.h"


#define TAM_MAX 1000


matriz crearMatriz(int n) {
    int i;
    matriz aux;
    if ((aux = malloc(n*sizeof(int *))) == NULL)
        return NULL;
    for (i=0; i<n; i++)
        if ((aux[i] = malloc(n*sizeof(int))) == NULL)
            return NULL;
    return aux;
}
/* Inicializacion pseudoaleatoria [1..TAM_MAX] de un grafo completo
no dirigido con n nodos, representado por su matriz de adayencia */
void iniMatriz(matriz m, int n) {
    int i, j;
    for (i=0; i<n; i++)
        for (j=i+1; j<n; j++)
            m[i][j] = rand() % TAM_MAX + 1;
    for (i=0; i<n; i++)
        for (j=0; j<=i; j++)
            if (i==j)
                m[i][j] = 0;
            else
                m[i][j] = m[j][i];
}
void liberarMatriz(matriz m, int n) {
    int i;
    for (i=0; i<n; i++)
        free(m[i]);
    free(m);
}


void dijkstra (matriz M, int n, matriz D){
    int noVisitados [];
    int m, i, j, w;
    for (m = 0; m < n ; m++) {
        for (j = 0; j <= n; j++) {
            if (j >= m) noVisitados[j]=j+1;
            else noVisitados[j]=j;
        }
        for (i = 0; i < n; ++i) {
            D[m][i]= M[m][i];
        }
        for (i = 0; i < (n-2); ++i) {
            //v=distanciaMinimaVdf;
            for (int w = 0; w < ; w++) {
                j= noVisitados[w];
                if(D[m][w]>D[m][v] + M[v][w])
                    D[m][w]=D[m][v] + M[v][w];
            }
        }
    }
}