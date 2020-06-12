#include <stdio.h>
#include <ctype.h>
#include <conio.h>
char *strchr(char str[], char ch);

int main()
{
	int i;
	char c;
	char frase[40];
	char *pt;
	printf("Digite uma frase: \n");
	gets(frase);
	printf("Digite um caracter: \n");
	c = getche();
	i = 0;
	pt = strchr(frase, c);
	printf("\nOnde o corre o caracter: \n'%s'", pt);
	return 0;
}
char *strchr(char str[], char ch)
{
	if(*str == 0) //fim da string e nao achou nada
		return NULL;
	else
		if(*str == ch)
			return (str); //retorna endereco de str
		else
			strchr(str+1, ch); //soma 1 no endereço de str e analisa o proximo byte artmetica de ponteiro
}
