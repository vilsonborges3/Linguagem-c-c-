#include <stdio.h>
int plus(int *A,int tam)
{
	if (tam != 0)
		return *A + plus(A+1, tam-1);
	else
		return 0;
}

int main()
{
	int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31};
	int tam,soma=0;
	tam = sizeof(A)/sizeof(int);
	soma = plus(A, tam);
	printf("%d",soma);
	return 0;
}
