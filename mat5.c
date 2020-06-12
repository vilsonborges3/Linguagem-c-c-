#include <stdio.h>
#include "Matriz.h"
#include <math.h>

int main() {
	char c = '\t';
	
	while(c == '\t')
	{
		system("cls");
		printf("***SOLUCAO MATRIZ DO TIPO AX=B***\n");
	    printf("***LEST BEGUIN***\n\n\n");
	    int a,b;
	    printf("Digite a ordem MXN da matriz A:");
	    scanf("%d", &a);
	    scanf("%d", &b);
	    printf("\n\nVamos preencher a Matriz A: \n");
	    Matriz A = criarMatriz(a,b);
	    preencherMatriz(A);
	    Matriz B = criarMatriz(a,1);
	    printf("\n\nVamos preencher o vetor B: \n");
	    preencherMatriz(B);
	    Matriz Sol = criarMatriz(a, 1);
	    Sol = solucaoSistemas(A,B);
	    printf("Resultado: \n\n");
	    imprimirMatriz(Sol);
	    destruirMatriz(A);
	    destruirMatriz(B);
	    destruirMatriz(Sol);
	    printf("\n\nDigite TAB para calcular novamente: \n");
	    c = getche();
	}
    return 0;
}
