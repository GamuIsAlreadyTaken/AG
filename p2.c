#include<stdio.h>
#include<stdbool.h>


// Algoritmo 1


// Algoritmo 2




void ord_shell(int v[], int n) {
    int incremento =n;
    int j;
    int tmp;
    bool seguir;
    while (incremento != 1){
        incremento = incremento/2;
        for (int i = 0; i < n; i++) {
            tmp = v[i];
            j = i;
            seguir = true;
            while (j - incremento > 0) {
                if (tmp < v[j - incremento]) {
                    v[j] = v[j - incremento];
                    j = j - incremento;
                } else {
                    seguir = false;
                }
            }
            v[j] = tmp;
        }
    }
}
