//vilson borges 11821eel001
#include <stdio.h>
#include <string.h>

int main() {
	int vetor[4];
	int i;
	for(i=0; i<=3; i++)
		vetor[i] = 0;
	printf("Digite os valores:\n");
	for(i=0;i<=3;i++)
		scanf("%d", &vetor[i]);
	int nBytes = sizeof(vetor);
	char *pointVet = (unsigned char*)vetor;
	for(i=0; i<nBytes; i++)
	{
		printf("%c", *(pointVet+i));
	}
	
	
	
	
	return 0;
}
