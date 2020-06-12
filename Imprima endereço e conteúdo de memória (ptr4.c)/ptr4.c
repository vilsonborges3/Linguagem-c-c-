//vilson borges 11821eel001
#include <stdio.h>

int main() {
	int a, b, soma;
	int *pointA, *pointB, *pointSoma;
	printf("Digite os valores de A e B, respectivamente:\n");
	scanf("%i",&a);
	scanf("%i",&b);
	soma = a+b;
	pointA = &a;
	pointB = &b;
	pointSoma = &soma;
	printf("\nOs valores e enderecos de A, B e da soma respectivamente:");
	printf("\n0x%X %i; 0x%X %i; 0x%X %i.",pointA,*pointA,pointB,*pointB,pointSoma,*pointSoma);
    return 0;
}
