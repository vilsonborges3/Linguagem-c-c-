#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *strdell(char *s);

int main()
{
	int i;
	char str[80];
	for(i=0; i<80; i++)
		str[i] = '\0';
	char *pt;
	fflush(stdin);
	gets(str);
	pt = strdell(str);
	printf("\n\n%s\n", pt);
	system("PAUSE");
	return 0;
}
char *strdell(char *s)
{
	int tam = (strlen(s));
	printf("\ntam: %d",tam);
	int i=0, j=0, cont=0;
	for(i=0; i<tam; i++) 
		{
			
			if(isupper(s[i])) 
				{
					s[i] = '\0';
					cont++;
					for(j=i; j<tam; j++)
						s[j] = s[j+1];
				}
				
		}
		
		printf("\nmaiu:%d",cont);
		return (&s[0]); //retorna endereço da primeira posição para escrever a string inteira
}
