#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define num 3
void mostrad(char str[][50], int n);
int main() {
	int i,tam;
	//int num;
	char palavras[15][50];
	//printf("\nDigite o numero de frases:\n");
	//scanf("%d", &num);
	
	for(i=0; i<num; i++)
	{
		printf("Digite a frase %i: \n",i+1);
		gets(palavras[i]);
	}
	for(i=0; i<num; i++)
		printf("\n\nA palavra %i e %s: ",i+1,palavras[i]);
	system("PAUSE");
	
	mostrad(palavras, num);
		
	return 0;
}
void mostrad(char str[][50], int n)
{
	system("cls");
	int i,j=0;
	char fraseD[15][50];
	for(i=0; i<n; i++)
	{
		if((str[i][0] == 'D') || (str[i][0] == 'd'))
		{
			strcpy(fraseD[j],str[i]);
			j++;
		}
	}
	fraseD[j+1][50] = '\0';
	for(i=0; i<j; i++)
		printf("\n%s", fraseD[i]);
}
