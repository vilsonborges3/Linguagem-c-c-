#include <stdio.h>
#include <stdlib.h>
typedef struct aMatriz {
    float x, y;
} Pontos;

int main()
{
	FILE *f;
	char c=0;
	int i;
	printf("Preencha seu bloco de notas: \n");
	f = fopen("meutexto.txt","w");
	while(c != '\n')
	{
		c = getchar();
		fputc(c, f);
	}
	fclose(f);
	return 0;
}
