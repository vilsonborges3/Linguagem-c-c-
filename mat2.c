#include <stdio.h>
#include "Matriz.h"
#include <math.h>

int main() {
    Matriz M;
    int m;
    double d;
    printf("Digite a ordem da matriz: \n");
    scanf("%d",&m);
    M = criarMatriz(m,m);
    preencherMatriz(M);
    
    d = det(&M);
    printf("\nDeterminate: %lf", d);
    
    destruirMatriz(M);
    return 0;
}


