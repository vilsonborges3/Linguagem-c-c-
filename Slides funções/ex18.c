#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void cripCerca(char frase[], char crip[], int n);
int main() 
{
	char str[300];
	char crip[300];
	int i=0, tam,j;
	int prof;
	printf("Digite uma frase para criplitografar: ");
	gets(str);
	system("cls");
	system("PAUSE");
	system("cls");
	printf("Digite a profundidade: ");
	scanf("%d", &prof);
	tam = strlen(str);
	while(str[i] != '\0')
		{
			if(isspace(str[i]))
				{
					for(j=i; j<tam; j++)
						str[j] = str[j+1];
				}
				i++;
		}
	cripCerca(str, crip, prof);
	system("cls");
	system("PAUSE");
	system("cls");
	printf("A frase criplitografada e: \n");
	printf("\n%s\n", crip);
	system("PAUSE");	
	return 0;
}
void cripCerca(char frase[], char crip[], int n)
{
	int tam = strlen(frase);
	int i=0, j=0, k=0;
	int vet[n];
	for(i=0; i<n; i++)
		vet[i] = 0;	
	char aux[15][200];
	for(i=0;i<15;i++)
	{
		for(j=0; j<200;j++)
			aux[i][j] = '\0';
	}
	while(k != tam) //K é o numero de atribuições da string que deseja-se criptografar
		{
			for(i=0; i<n; i++) //esse for anda na parte da decida para preencher a matriz auxiliar
				{
					aux[i][(vet[i])] = frase[k];
					k++;
					vet[i] = vet[i] + 1;
					if(k == tam)
					{
						i = n+1;
					} //força sair do laço
				}
			if(i == n+1)
			{
				for(i=n-2; i>=1; i--) //esse for anda na parte da subida para concluir o padrao 
				{
					aux[i][(vet[i])] = frase[k];
					k++;
					vet[i] = vet[i] + 1;
					if(k == tam)
					{
						i = -1;
					}
						
				}
			}	
		}
		for(i=0; i<300; i++)
			{
				crip[i] = '\0';
			}
		k=0;
		for(i=0; i<n; i++)
			printf("\n%s", aux[i]);
		for(i=0; i<n; i++)
			for(j = 0; j<(vet[i]); j++)
				{
					crip[k] = aux[i][j];
					k++;
				}	
}
