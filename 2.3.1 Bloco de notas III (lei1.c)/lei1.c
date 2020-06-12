#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    char c=0;
    printf("lendo bloco de notas:\n");
    f = fopen("meutexto.txt","r");
    if(f != NULL)
    {
        while((c = fgetc(f)) != EOF)
            printf("%c", c);
    }
    else
        printf("Nao foi possivel abrir o arquivo.");

    fclose(f);
    return 0;
}
