//
// Created by ismael on 17/11/23.
//

#ifndef PRACTICAS_P4_H
#define PRACTICAS_P4_H

#define TAM_MAX 10

typedef int **matriz;

matriz crearMatriz(int n);
void iniMatriz(matriz m, int n);
void liberarMatriz(matriz m, int n);

void dijkstra(matriz grafo, matriz distancias, int tam);

void print_matriz(matriz m, int tam);
void test_dijkstra_1();
void test_dijkstra_2();
void time_dijkstra();


#endif