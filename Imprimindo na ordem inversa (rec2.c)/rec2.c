//vilson borges 11821eel001
#include <stdio.h>
#include <string.h>
void inverte(char *str)
{
	if(*str)
	{
		inverte(str+1);
		printf("%c", *str);
	}
}
int main()
{
	char str[30];
	printf("Digite um Texto: ");
	fgets(str,30,stdin);
	str[strlen(str)+1] = '\0';
	inverte(str);
	return 0;
}

