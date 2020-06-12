#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    srand(time(NULL));
    FILE *file;
    double media, somadp=0, dp;
    char *nome;
    char c = 0;
    int opcao, n = 1, num, i;
    int N = 1, *a;
    nome = (char *)calloc(n,sizeof(char));
    printf("Digite:\n1 - Novo arquivo\n2 - Acrescentar ao arquivo\n3 - Ler Arquivo\n");
    scanf("%d", &opcao);
    system("cls");

    switch (opcao)
    {
        case 1:
        {
            fflush(stdin);
            printf("Digite o nome do arquivo em que se deseja criar e clique na tecla 'ENTER': ");
            while ((c = getchar()) != '\n')
            {
                nome[n-1] = c;
                nome[n] = 0;
                n++;
                nome =(char *)realloc(nome,n*sizeof(char));
            }
            if((file = fopen(nome, "w")) != NULL)
            {
                printf("\nDigite quantos numeros aleatorios serao gerados: ");
                scanf("%d", &num);
                for(i = 0; i < num; i++)
                    fprintf(file,"%d ",(rand()%100));
            }
            else
                printf("Nao foi possivel criar o arquivo...\n");
            fclose(file);
        }break;
        case 2:
        {
            fflush(stdin);
            printf("Digite o nome do arquivo em que se deseja acrescentar e clique na tecla 'ENTER': ");
            while ((c = getchar()) != '\n')
            {

                nome[n-1] = c;
                nome[n] = 0;
                n++;
                nome =(char *)realloc(nome,n*sizeof(char));
            }
            if((file = fopen(nome, "a")) != NULL)
            {
                printf("\nDigite quantos numeros aleatorios serao gerados: ");
                scanf("%d", &num);
                for(i = 0; i < num; i++)
                    fprintf(file,"%d ",(rand()%100));
            }
            else
            {
                printf("Erro!! O arquivo nao foi encontrado...\n");
            }
            fclose(file);
        }
            break;
        case 3:
        {
            printf("Digite o arquivo que deseja abrir: ");
            fflush(stdin);
            while ((c = getchar()) != '\n')
            {
                nome[n-1] = c;
                nome[n] = 0;
                n++;
                nome =(char *)realloc(nome,n*sizeof(char));
            }
            if((file = fopen(nome,"r")) == NULL)
                printf("Arquivo nao pode ser aberto...");
            else
            {
                a = (int *) calloc(N, sizeof(int));
                i = 0;
                while (fscanf(file, "%d ", &a[i]) != EOF)
                {
                    printf("%d ", a[i]);
                    i++;
                    N++;
                    a = (int*) realloc(a,N* sizeof(int));
                }
	            media=0;
	            for(i=0; i<N-1; i++)
	                media = media + a[i];
	            media = (media/(N-1));
	            
	            for(i=0; i<N-1; i++)
	                somadp = somadp + ((a[i] - media)*(a[i] - media));
	                
	            dp = sqrt(somadp/(N-2));
	            printf("\n\n\nMedia: %lg\nDesvio padrao: %lg", media, dp);
	            }
	            fclose(file);
	            free(a);
        }
            break;
    }
    free(nome);
    return 0;
}
