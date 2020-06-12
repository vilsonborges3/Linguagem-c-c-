#include <stdio.h>
#include <stdlib.h>
typedef struct {
    double x,y;
}Ponto;
int main()
{
    FILE *f;
    char c=0;
    char *nome;
    int k = 1;
    int n, i;
    Ponto *p;
    nome = (char *) calloc(k, sizeof(char));
    nome[0] = 0;
    printf("Quantos pontos deseja adicionar: ");
    scanf("%d", &n);
    p = (Ponto*) calloc(n, sizeof(Ponto));
    printf("Digite os pontos: ");
    for(i = 0; i < n; i++)
    {
        printf("\n\nX%i=", i+1);
        scanf("%lg", &p[i].x);
        printf("\nY%i=", i+1);
        scanf("%lg", &p[i].y);
    }

    printf("\nDigite o nome do arquivo em binario: ");
    fflush(stdin);
    while((c = getchar())!= '\n')
    {
    	printf("T ");
        nome[k-1] = c;
        nome[k] = '\0';
        k++;
        nome = (char*) realloc(nome, k*sizeof(char));
    }

    f = fopen(nome, "wb");
    for(i=0; i<n; i++)
        fwrite(&p[i], sizeof(Ponto), 1, f);
    fclose(f);

    f  = fopen(nome, "rb");
    if(!f)
    {
        printf("Erro ao tentar abrir o arquivo...");
        exit(1);
    }
    i=0;
        while (fread(&p[i], sizeof(Ponto), 1, f) )
        {
            printf("X%d = %lg\n Y%d = %lg \n",i+1, p[i].x, i+1, p[i].y);
            i++;
        }
    fclose(f);
    free(nome);
    free(p);
    return 0;
}
