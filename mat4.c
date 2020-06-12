#include <stdio.h>
#include "Matriz.h"
#include <math.h>

int main() {
    int a,s,d,f;
    printf("Digite a ordem MXN da matriz 1:");
    scanf("%d", &a);
    scanf("%d", &s);
    printf("\n\nVamos preencher a Matriz 1: \n");
    Matriz M1 = criarMatriz(a,s);
    preencherMatriz(M1);
    printf("Digite a ordem MXN da matriz 2:");
    scanf("%d", &d);
    scanf("%d", &f);
    Matriz M2 = criarMatriz(d,f);
    printf("\n\nVamos preencher a Matriz 2: \n");
    preencherMatriz(M2);
    Matriz m = criarMatriz(a,f);
	
	if(M1.col == M2.lin)
	{
		m = multiplicaMatrizes(M1,M2);
    	printf("\n\nResultdo: \n");
    	imprimirMatriz(m);	
	}
    else
    	printf("\n\nNAO E POSSIVEL, FAVOR DIGITE OUTRA...");
    destruirMatriz(m);
    destruirMatriz(M1);
    destruirMatriz(M2);
    return 0;
}
