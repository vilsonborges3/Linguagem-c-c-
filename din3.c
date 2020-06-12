#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main()
{
	char *texto;
	texto = calloc(1,sizeof(char));
	char c[1];
	int size = 0, i;
	while(c[1] != '\n')
	{
		scanf("%c", &c[1]);
		texto[size] = c[1];
		size++;
		texto = realloc(texto,size*sizeof(char));
	}
	for(i=0; i<size; i++)
		texto[i] = toupper(texto[i]);
	printf("%s", texto);
	free(texto);
	return 0;
}
