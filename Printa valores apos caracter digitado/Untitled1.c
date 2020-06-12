#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
char *findCharactere(char caractere, char *str); //prototipo

int main()
{
	char frase[80];
	char chr, *pointer;
	printf("\nDigite uma frase:");
	gets(frase);
	printf("\nDigite um caracter: ");
	chr = getche();
	pointer = findCharactere(chr, frase);
	if(pointer)
	printf("\n\n%s\n\n", pointer); //se encontrar correspondencia imprime frase a partir dela
	else
	printf("\n\nNenhuma paridade\n\n");
	
	system("PAUSE");
	return 0;
}

char *findCharactere(char caractere, char *str)
{
	int counter = 0;
	while((caractere != str[counter]) && (str[counter] != '\0'))
	counter++;
	
	if(str[counter] )
		return (&str[counter]);
	else
		return 0;
}
