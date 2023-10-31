//
// Created by ismael on 27/10/23.
//

#ifndef PRACTICAS_P3_H
#define PRACTICAS_P3_H

#endif //PRACTICAS_P3_H
#define TAM 256000
#define NULL NULL


struct monticulo {
    int ultimo;
    int vector[TAM];
};
typedef struct monticulo * pmonticulo;

void inicializarMonticulo (pmonticulo m);
void crearMonticulo(int vector[], int n, pmonticulo m);
int quitarMenor(pmonticulo m);


//Funciones auxiliares
int Padre(pmonticulo m, int i);
int Izquierdo(pmonticulo m, int i);
int Derecho(pmonticulo m, int i);