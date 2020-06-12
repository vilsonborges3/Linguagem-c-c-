#include <stdio.h>
#include <stdlib.h>


void troca_numeros(int *n1, int *n2);

int main() 
{
	int num1,num2;
	printf("Digite dois numeros:\n");
	scanf("%d%d",&num1,&num2);
	printf("\nOs numeros um e dois em sequencia %d %d",num1,num2);
	troca_numeros(&num1, &num2);
	printf("\n\nOs numeros um e dois em sequencia %d %d",num1,num2);
	return 0;
}
void troca_numeros(int *n1, int *n2)
{
	int aux;
	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}
