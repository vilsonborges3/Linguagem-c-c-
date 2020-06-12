//vilson
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
typedef struct Ponto
{
    float x;
    float y;
}Ponto;
typedef struct Poligono
{
    int vertices;
    Ponto p[20];
}Poligono;

void poli(Poligono *polygons, int num);
void imprime(Poligono *polygons, int num);
void space(float *a, Poligono *pol, int n);
void centroid (Poligono *po, int n, float **cent);
int main()
{
    int n,i,j;
    float *area;
    float **centroide;
    printf("Digite o numero de poligonos: \n");
    scanf("%d",&n);
    centroide = calloc(n, sizeof(float));
    for(i=0; i<n; i++)
    {
        centroide[i] = calloc(2, sizeof(float));
        for(j=0; j<2; j++);
            centroide[i][j] = 0;
    }
    Poligono *polygons;
    polygons = (Poligono *) calloc(sizeof(Poligono),n);
    area = (float *) calloc(sizeof(float), n);
    for(i=0; i<n; i++)
        area[i] = 0;
    //preenche os pontos e imprime
    poli(polygons, n);
    imprime(polygons, n);
    for(i=0; i<n; i++)
        space(area, polygons, n);
    for(i=0; i<n; i++)
        printf("\nArea poligono N%d: %f ",i+1, area[i]);
    centroid(polygons, n, centroide);
    for(i=0; i<n; i++)
    {
        printf("\n\nCentroide X poligono %d: %f.", i+1, centroide[i][0]);
        printf("Centroide Y poligono %d: %f.", i+1, centroide[i][1]);
    }

    free(polygons);
    free(area);
    for(i = 0; i < n; i++)
        free(centroide[i]);
    free(centroide);
    return 0;
}
void poli(Poligono *polygons, int num)
{
    int i,j;
    for (j=0; j<num; j++)
    {
        printf("Digite o numero de vertices para o poligono %d\n",j+1);
        scanf("%d", &polygons[j].vertices);
        for(i = 0; i<polygons[j].vertices; i++)
        {
            printf("Digite os pontos x e y do poligono %d, respectivamente:\n ",j+1);
            scanf("%f",&polygons[j].p[i].x);
            scanf("%f",&polygons[j].p[i].y);
        }
        system("cls");
    }
    system("cls");
}
void imprime(Poligono *polygons, int num)
{
    int i,j;
    for (j=0; j<num; j++)
    {
        printf("\n\nPoligono %d",j+1);
        printf("\nNumero de Vertices %d ",polygons[j].vertices);
        for(i = 0; polygons[j].vertices > i; i++)
        {
           printf("\nX: %f",polygons[j].p[i].x);
           printf("\nY: %f",polygons[j].p[i].y);
        }
    }
}
void space(float *a, Poligono *pol, int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<pol[i].vertices; j++)
            a[i] = a[i] + (pol[i].p[j].x*pol[i].p[j+1].y - pol[i].p[j].y*pol[i].p[j+1].x);
        a[i] = a[i]/2;
    }
}
void centroid(Poligono *po, int n, float **cent)
{
    int i,j;
    for (i=0; i<n; i++)
    {
        for(j=0; j<po[i].vertices; j++)
        {
            cent[i][0] = po[i].p[j].x + cent[i][0];
            cent[i][1] = po[i].p[j].y + cent[i][1];
        }
        cent[i][0] = cent[i][0]/po[i].vertices;
        cent[i][1] = cent[i][1]/po[i].vertices;
    }
}

