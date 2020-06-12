#include <stdio.h>
#include <stdlib.h>
typedef struct {
    double x,y;
}Ponto;
int main(){
    FILE *f;
    char c=0;
    char *nome;
    int k = 1;
    int n, i;
    Ponto *p, centroide;
    nome = (char *) calloc(k, sizeof(char));
    nome[0] = 0;

    printf("Digite o nome do arquivo em binario: ");
    fflush(stdin);
    while((c = getchar())!= '\n')
    {
        nome[k-1] = c;
        nome[k] = '\0';
        k++;
        nome = (char*) realloc(nome, k*sizeof(char));
    }
    f  = fopen(nome, "rb");
    if(!f)
    {
        printf("Erro ao tentar abrir o arquivo...");
        exit(1);
    }
    printf("Digite o numero de pontos que estao no arquivo binario: ");
    scanf("%d", &n);
    p = (Ponto *) calloc(n, sizeof(Ponto));
    i = 0;
        while (i !=n )
        {
            fread(&p[i], sizeof(Ponto), 1, f);
            printf("X%d = %lg\nY%d = %lg \n\n",i+1, p[i].x, i+1, p[i].y);
            i++;
        }
        centroide.x = 0.0;
        centroide.y = 0.0;
        for(i=0; i<n; i++)
        {
            centroide.x = centroide.x + p[i].x;
            centroide.y = centroide.y + p[i].y;
        }
        centroide.x = centroide.x/n;
        centroide.y = centroide.y/n;
        printf("Centroide:\nXc = %lg\nYc = %lg", centroide.x,centroide.y);
        
    fclose(f);
    free(nome);
    free(p);
    return 0;
}
