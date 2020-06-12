#include <stdio.h>0
#include <stdlib.h>
#include <conio.h>
char *strrchar(char *s, char ch); //prototipo

int main()
{
	char frase[80], caracter;
	char *pt;
	printf("Digite a frase: \n");
	gets(frase);
	printf("Digite o caracter limitante: ");
	caracter = getchar();
	pt = strrchar(frase, caracter);
	if(pt)
		printf("\nO endereço limitante e %p e o pedaco final e: '%s'\n",pt,pt);
	else
		printf("\nNao houve ocorrencias");
	system("PAUSE");
	return 0;
}

char *strrchar(char *s, char ch)
{
	
	int i = 0;
	int j = 0;
	int k = 0;
	printf("\nlooping1");
	do
	{
		printf("\nlooping2");
		if(s[i] == ch)
		{
			j = i;
			k++;
		}
		i++;	
	}while(s[i] != '\0');
	printf("\nlooping3");
	if(k > 0)
		return (&s[j]);	
	else
		return 0;
}
