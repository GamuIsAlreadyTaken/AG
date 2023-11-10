
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

void ordenarPorMonticulos(int v[], int n);

void time_ordenarPorMonticulos_rand();
void time_ordenarPorMonticulos_asc();
void time_ordenarPorMonticulos_desc();

#endif