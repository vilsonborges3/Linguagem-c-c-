#include <stdio.h>
#include "Matriz.h"
#include <math.h>

int main() {
    Matriz M, result;
    int m;
    double d;
    printf("Digite a ordem M da matriz quadrada: \n ");
    scanf("%d", &m);
    M = criarMatriz(m, m);
    preencherMatriz(M);

    printf("\n ");
    imprimirMatriz(M);
    d = det(&M);
    printf("\nDeterminate: %lf", d);
    if(d==0)
    {
        printf("\nMatriz Irreversivel!!");
        return 0;
    }
    else
    {
        result = inversa(M, d);
        imprimirMatriz(result);
        destruirMatriz(M);
        destruirMatriz(result);
    }
    return 0;
}
