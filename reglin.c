

#include <stdio.h>
#include "Matriz.h"
#include <math.h>

int main() {
    int d;
    Matriz solucao = criarMatriz(3,1);
    printf("Digite o numero de dados: \n");
    scanf("%d", &d);
    printf("Digite os dados de X1 e X2 sequencial e um para primeira coluna: \n\n\n");
    Matriz cof = criarMatriz(d, 2); //matriz dos dados x1 e x2 {A}
    preencherMatriz(cof);

    printf("Digite os dados de de Y sequencial: \n\n\n");
    Matriz saida = criarMatriz(d, 1); //matriz dos dados y = {B}
    preencherMatriz(saida);
    printf("\n\nResultado:");
    add_one(&cof);
    imprimirMatriz(cof);
    solucao = solveSystem(&cof, &saida);
    imprimirMatriz(solucao);
    destruirMatriz(solucao);
    return 0;
}
