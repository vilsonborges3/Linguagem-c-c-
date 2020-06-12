#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
char *vogal(char *str);

int main()
{
	char frase[80];
	char *pt;
	printf("Digite a frase: ");
	gets(frase);
	pt = vogal(frase);
	printf("\n\nO endereco da frase: 0x%X e o final da frase apos encontrar uma vogal: %s.",pt,pt);
	system("PAUSE");
	return 0;
}
char *vogal(char *str)
{
	int i=0, j, nvogais = 0;
	char vogais[] = {"aeiou"};
	do
	{
		for(j=0; j<5; j++)
			{
				if(str[i] == vogais[j])
				{
					nvogais++;
					return (&str[i]);
				}
			}
			i++;
		
	}while(str[i] != '\0');
	
	
	if(nvogais < 0)
		return NULL;
}

