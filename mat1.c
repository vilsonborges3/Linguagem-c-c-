#include <stdio.h>
#include "Matriz.h"
#include <math.h>

int main() {
    Matriz M, result;
    int m;
    printf("Digite a ordem M da matriz quadrada: \n ");
    scanf("%d", &m);
    M = criarMatriz(m, m);
    preencherMatriz(M);

    printf("\n ");
    imprimirMatriz(M);
    printf("%lf\n",cofator(&M,0,0));
    result = adjunta(&M);
    imprimirMatriz(result);
    destruirMatriz(M);
    destruirMatriz(result);
    return 0;
}
