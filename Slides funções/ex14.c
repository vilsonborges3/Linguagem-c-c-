#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz(int mat[][100], int l, int c);
void identidade(int mat[ ][100],int N);
int main()
{
	int m[100][100];
	
	int tam,i,j,linhas,colunas;
	printf("Dig. a ordem da matriz: ");
	scanf("%i", &tam);
	identidade(m, tam);
	printf("Digite quantas linhas e quantas colunas imprimir:\n");
	scanf("%d%d", &linhas, &colunas);
	imprimeMatriz(m,linhas,colunas);
	return 0;
}
void identidade(int mat[ ][100],int N)
{
	 int i,j;
	 for(i = 0;i < N;i++)
		 for(j = 0;j < N;j++)
		 {
			 if(i == j)
			 mat[i][j] = 1;
			 else
			 mat[i][j] = 0;
		 }
}
void imprimeMatriz(int mat[][100], int l, int c)
{
	int i,j;
	printf("\nImprimindo a matriz identidade\n");
	for(i=0; i<l; i++)
		{
			for(j=0; j<c; j++)
				printf("%i ", mat[i][j]);
			printf("\n");	
		}
}

