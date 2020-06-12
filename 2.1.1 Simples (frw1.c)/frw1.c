#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//p = (int *) calloc(10,sizeof(int))

int main()
{
	int opcao, age;
	FILE *f;
	char *nome, c;
	float h;
	int n = 1;
	nome = (char *) calloc(n, sizeof(char));
	printf("Digite 1 para preencher seus dados e 2 para ler os dados armazenados: ");
	scanf("%i", &opcao);
	switch(opcao)
	{
		case 1:
			{
				f = fopen("info.txt", "w");
				printf("\nDigite o seu nome e clique 'TAB': \n");
				while((c = getche()) != '\t')
				{
					nome[n-1] = c;
					n++;
					nome[n] = '\0';
					
					nome = (char*) realloc(nome, n*sizeof(char));
				}
				printf("\nDigite sua idade: ");
				scanf("%d", &age);
				printf("\nDigite sua altura: ");
				scanf("%g", &h);
				fprintf(f, "Nome: %s, Idade %d anos, Altura: %gm", nome, age, h);
			}
			break;
		case 2:
			{
				if((f = fopen("info.txt", "r")) == NULL)
					{
						printf("Arquivo nao pode ser aberto...");
						break;
					}
					
						nome = (char*) realloc(nome, 400*sizeof(char));	
				while((fgets(nome,400,f)) != NULL)
						printf("%s\n", nome);
			}
			break;
	}
	free(nome);
	fclose(f);
	return 0;
}
