#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
	char name[80];
	int i=0, j, tam =0;
	printf("\nDigite uma frase:");
	gets(name); 
	if(name) //ponter não retornou nulo Null, /0 ou 0
	{
		tam = strlen(name)-1; //mede tamanho da string NOME para poder manipular ela pelo fim
		printf("\nTamanho da string: %d", tam);
		for(j=tam; (j>=0) && (name[j] == ' '); j--) //verifica se existe espaçoes depois do nome
				name[j] = 0;
				i = j;
		while((i>=0) && (name[i] != ' ')) 
		{
			i--;
		}
	
		printf("\n");
		printf("%s\n", name+i);	
	}
	system("PAUSE");
	return 0;
}
