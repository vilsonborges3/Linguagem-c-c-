#include <stdio.h>
#include <stdlib.h>

//
// Created by Vilson on 18/05/2019.
//

void tran(float **transposta, float **matriz, int m, int n);

void imprime(float **transposta, int m, int n);
#include <stdio.h>
int main()
{
    int i,j;
    int n,m;
    float **matriz;
    float **transposta;
    printf("Entre com a ordem da matriz, no formato 'NXM': ");
    scanf("%d %d", &n, &m);
    matriz = calloc(n, sizeof(float));
    //preenche a matriz dinamicamente
    for(i = 0; i<n; i++)
    {
        matriz[i] = calloc(m, sizeof(float));
        for (j = 0; j < m; j++)
        {
            printf("\nElemento(%d,%d): ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }

    transposta = calloc(m, sizeof(float));
    for(i = 0; i<m; i++)
    {
        transposta[i] = calloc(n, sizeof(float));
        for (j = 0; j < n; j++)
            transposta[i][j] = 0;
    }
    tran(transposta, matriz, m,n);
    imprime(transposta, m, n);
	for(i = 0; i < n; i++)
        free(matriz[i]);
  		free(matriz);
  		
  	for(i = 0; i < m; i++)
        free(transposta[i]);
  		free(transposta);
    return  0;
}
void tran(float **transposta, float **matriz, int m, int n)
{
    int i, j;
    //preenche a transposta com 0 dinamicamente
    for(i = 0; i<m; i++)
    {
        for (j = 0; j < n; j++)
            transposta[i][j] = matriz[j][i];
    }
}
void imprime(float **transposta, int m, int n)
{
    int i, j;
    for(i = 0; i < m; i++)
    {
        for(j=0; j<n; j++)
            printf("%g ", transposta[i][j]);
        printf("\n");
    }
}
