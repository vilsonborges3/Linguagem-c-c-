#include <stdio.h>
#include <stdlib.h>


void strlen(char *frase, int *num);

int main() 
{
	char str[30];
	int n = 0;
	printf("Digite uma frase: \n");
	gets(str);
	strlen(str, &n);
	printf("\n\nO numero de caracteres: %d", n);
	return 0;
}
void strlen(char *frase, int *num)
{
	while(frase[*num] != '\0')
		{
			(*num)++;
		
		}
		*num = *num;
}
