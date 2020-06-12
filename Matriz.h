#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct aMatriz {
    double **m;
    int lin, col;
} Matriz;

Matriz criarMatriz(int M, int N);
Matriz solveSystem(Matriz *A,Matriz *B);
void imprimirMatriz(Matriz A);

double det(Matriz *A);

void destruirMatriz(Matriz A);

double menor(Matriz *A, int i, int j);

double cofator(Matriz *A, int i, int j)
{
   double minor = menor(A, i, j);
   return ((i + j) % 2 == 0 ? 1 : -1)*minor;
}

Matriz comatriz(Matriz *A) {              //matriz dos cofatores
    Matriz cofatores = criarMatriz(A->lin, A->col);
    int i, j;
    for (i = 0; i < cofatores.lin; i++)
    {
        for (j = 0; j < cofatores.col; j++)
        {
            cofatores.m[i][j] = cofator(A, i, j);
        }
    }
    return cofatores;
}

Matriz subMatriz(Matriz *A, int i_, int j_) { // transforma matriz mxm em m-1xm-1
    Matriz result = criarMatriz(A->col - 1, A->lin - 1);
    int i, j, k, l;
    for (i = 0, k = 0; i < result.lin; i++, k++)
    {
        for (j = 0, l = 0; j < result.col; j++, l++)
        {
            if (k == i_)
                k++;
            if (l == j_)
                l++;
            result.m[i][j] = A->m[k][l];
        }
    }
    return result;
}

double det(Matriz *A) {
    double d = 0;
    int M = A->lin;

    int i, j;
    if (M == 1)
        return A->m[0][0];
    if (M == 2)
        return A->m[0][0] * A->m[1][1] - A->m[1][0] * A->m[0][1];
    if (M == 3){
        return (A->m[0][0] * A->m[1][1] * A->m[2][2] + A->m[0][1] * A->m[1][2] * A->m[2][0] +
                A->m[0][2] * A->m[1][0] * A->m[2][1]) -
               (A->m[0][0] * A->m[1][2] * A->m[2][1] + A->m[0][1] * A->m[1][0] * A->m[2][2] +
                A->m[0][2] * A->m[1][1] * A->m[2][0]);
    }

    if (M > 3) {
        double d2d=0;
        for (i = 0; i < A->lin; ++i) {
            d2d =   A->m[i][j] * cofator(A, i, j);
            d = d + d2d;
            }
        return d;
    }

}
double menor(Matriz *A, int i, int j) { //determinate da matriz M-1
    Matriz aux;
    aux = subMatriz(A, i, j);
    double determinante = det(&aux);
    destruirMatriz(aux);
    return determinante;
}

Matriz criarMatriz(int M, int N) {
    Matriz A;
    int i;
    A.m = (double **) calloc(M, sizeof(double *));
    for (i = 0; i < M; i++)
        A.m[i] = (double *) calloc(N, sizeof(double *));
    A.lin = M;
    A.col = N;
    return A;
}

void destruirMatriz(Matriz A) {
    int i;
    for (i = 0; i < A.lin; i++)
        free(A.m[i]);
    free(A.m);
}

void preencherMatriz(Matriz A) {
    int i, j;
    for (i = 0; i < A.lin; i++)
        for (j = 0; j < A.col; j++) {
            printf("Entre com o elemento [%d][%d]: ", i, j);
            scanf("%lf", &A.m[i][j]);
        }
}

void imprimirMatriz(Matriz A) {
    int i, j;
    for (i = 0; i < A.lin; i++) {
        for (j = 0; j < A.col; j++)
            printf("%lg\t", A.m[i][j]);
        printf("\n");
    }
    printf("> %dx%d\n\n", A.lin, A.col);
}
Matriz transposta(Matriz A) {
    Matriz At = criarMatriz(A.col, A.lin); // ordem transposta
    int i, j;
    for (i = 0; i < A.col; i++)
        for (j = 0; j < A.lin; j++)
            At.m[i][j] = A.m[j][i];
    return At;
}
Matriz adjunta(Matriz *A)
{
    Matriz com = comatriz(A);
    Matriz adj= transposta(com);
    destruirMatriz(com);
    return adj;
}
Matriz inversa(Matriz A, double det)
{
    int i,j;
    Matriz inv = criarMatriz(A.lin, A.col);
    inv = adjunta(&A);

    for(i=0; i<inv.lin; i++)
    {
        for(j=0; j<inv.col; j++)
            inv.m[i][j] = inv.m[i][j]/det;
    }
    return inv;
}
Matriz multiplicaMatrizes(Matriz A, Matriz B)
{
    int linha ,coluna,i;
    double acumula;
    Matriz mult = criarMatriz(A.lin, B.col);
    if(A.col == B.lin)
    {
        for(linha=0; linha<A.lin; linha++)
        {
            for(coluna = 0; coluna<B.col; coluna++)
            {
                acumula = 0;
                for(i=0; i<A.col; i++)
                    acumula = acumula + A.m[linha][i]*B.m[i][coluna];
                mult.m[linha][coluna] = acumula;
            }
        }
        return mult;
    }
    else
    {
        printf("\n\nNAO E POSSIVEL, FAVOR DIGITE OUTRA...");
        return mult;
    }
}
Matriz solucaoSistemas(Matriz A, Matriz M)
{
    double d; //calcular determinate
    Matriz inv = criarMatriz(A.lin, A.col);
    d = det(&A);
    inv = inversa(A, d);
    Matriz m = criarMatriz(A.lin, 1);
    m = multiplicaMatrizes(inv, M);
    return m;
}
Matriz solveSystem(Matriz *A, Matriz *B){
    Matriz transposta_A = transposta(*A);//transpondo A
    Matriz aux = multiplicaMatrizes(transposta_A,*A);// fazendo A^t*A
    Matriz aux2 = inversa(aux,det(&aux));//(A^t*A)^-1
    destruirMatriz(aux);
    aux2 = multiplicaMatrizes(aux2,transposta_A);//(A^t*A)^-1*A^t = aux2
    destruirMatriz(transposta_A);
    aux = multiplicaMatrizes(aux2,*B);//aux2*B  = A^-1*B
    destruirMatriz(aux2);
    return aux;
}
void add_one(Matriz *a){

    Matriz chang = criarMatriz(a->lin,a->col+1);
    int i,j;
    for (i = 0; i < a->lin; ++i) {
        chang.m[i][0] = 1;
        for (j = 0; j < a->col; ++j) {
            chang.m[i][j+1]=a->m[i][j];
        }
    }
    destruirMatriz(*a);
    *a = chang;
}

#endif
