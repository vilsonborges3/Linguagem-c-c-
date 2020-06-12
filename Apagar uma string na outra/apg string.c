#include <stdio.h>
#include <string.h>
char *StrDelStr(char *s1, char *s2);
int main()
{
	int i;
	char str1[80];
	char str2[80];
	for(i=0;i<80;i++)
	{
		str1[i]='\0';
		str2[i]='\0';
	}
	char *ptr;
	printf("Digite a string 1\n");
	gets(str1);
	printf("\nDigite a string 2 que apaga-se em 1\n");
	gets(str2);
	ptr = StrDelStr(str1, str2);
	printf("\nString apagada: %s\n",ptr);
	system("PAUSE");
	return 0;
}
char *StrDelStr(char *s1, char *s2)
{
	int tam1 = strlen(s1);
	int tam2 = strlen(s2);
	int cont = 0, i,j,k;
	
	for(i=0; i<tam1; i++)
	{
		cont=0;
		for(j=0; j<tam2; j++)
		{
			if(s1[i+j] == s2[j])
				cont++;
		}
		
		if(cont == tam2)
			{
				
				for(k=i; k<tam1; k++)
					s1[k] = s1[k+tam2];
					return (&s1[0]);
			}	
	}
	return(&s1[0]);		
}
