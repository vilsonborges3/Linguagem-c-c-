#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char *string(char *dest, char *orig);

int main()
{
	char destino[80], origem[80];
	char *ptr;
	printf("Digite a string destino: ");
	gets(destino);
	printf("\nDigite a string que vai na origem: ");
	gets(origem);
	ptr = string(destino, origem);
	printf("\nA string destino ficara: '%s'\n\n", ptr);
	system("PAUSE");
	return 0;
}

char *string(char *dest, char *orig)
{
	int i=0, j=0, k=0;
	while(orig[i] != '\0')
		i++;
	while(dest[j] != '\0')
		j++;
	for(k=j; k>=0; k--)
	{
		dest[k+i] = dest[k];
	}
	for(k=0; k<i; k++)
		dest[k] = orig[k];
	if(dest)
		return (&dest[0]);
}

