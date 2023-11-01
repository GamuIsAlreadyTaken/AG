
#ifndef PRACTICAS_P3_H
#define PRACTICAS_P3_H

#define TAM 256000

struct monticulo
{
    int ultimo;
    int vector[TAM];
};
typedef struct monticulo *pmonticulo;

void crearMonticulo(int v[], int n, pmonticulo m);
int quitarMenor(pmonticulo m);

void hundir(pmonticulo m, int i);
bool monticuloVacio(pmonticulo m);

void listar_monticulo(pmonticulo m);

void test_ordenarPorMonticulos();
void time_crearMonticulo();

// Funciones auxiliares
// void inicializarMonticulo(pmonticulo m);
// int Padre(pmonticulo m, int i);
// int Izquierdo(pmonticulo m, int i);
// int Derecho(pmonticulo m, int i);

#endif // PRACTICAS_P3_H