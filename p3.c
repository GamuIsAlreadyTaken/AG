//
// Created by ismael on 27/10/23.
//

#include "p3.h"
#include "bootstrap.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarMonticulo (pmonticulo m){
    m->ultimo = NULL;
}

void crearMonticulo(int v [], int n, pmonticulo m) {
    if (n>TAM){
        printf("Vector demasiado grande");
        return;
    }
    m->ultimo = n;
    for (int i = 0; i < n; i++) {
        m->vector[i] = v[i];
    }
}

int Padre(pmonticulo m, int i) {
    return i/2;
}
int Izquierdo(pmonticulo m, int i) {
    return 2*i;
}
int Derecho(pmonticulo m, int i) {
    return 2*i+1;
}




int quitarMenor(pmonticulo m){

}


//Algoritmo
void OrdenarPorMonticulos(int v[], int a){

    crearMonticulo(v ,a ,m);
    for (int i = 0; i < n; i++) {
        V[i] = quitarMenor(M);
    }
}


int main () {
    inicializar_semilla();
    int v[];
    int n = sizeof(v) / sizeof(v[0]);
    pmonticulo m = (pmonticulo)malloc(sizeof(struct monticulo));



}