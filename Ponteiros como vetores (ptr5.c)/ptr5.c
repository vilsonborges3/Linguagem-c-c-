//vilson borges 11821eel001
#include <stdio.h>

int main() {
	srand(time(0));
	int vetor[1000], i, digito, nBytes,cont=0;
	int *pointv;
	pointv = &vetor[0];
	
	for(i=0; i<1000; i++)
	{
		vetor[i] = rand();
	}
	
	printf("\nDigite um valor inteiro para teste:\n");
	scanf("%d", &digito);
	nBytes = sizeof(vetor);
	unsigned char *pointVet;
	pointVet = (unsigned char*)vetor;
	for(i=0; i<nBytes; i++)
	{
		if(*(pointVet+i) == digito)
		{
			printf("\nEndereco:0x%X", pointVet+i);
			cont++;
		}
	}
	printf("\nNumero digitado pelo usuario:%d\nNumero de Bytes que contem o numero:%d\nEndereco inicial do vetor:0x%X\nEndereco imediatamente posterior ao termino do vetor na memoria:0x%X\n",digito,cont,pointVet,pointv+999);
    return 0;
}
