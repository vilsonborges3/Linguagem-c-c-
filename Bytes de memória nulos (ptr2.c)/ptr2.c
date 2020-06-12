//vilson borges 11821eel001
#include <stdio.h>

int main() {
    int vetor[] = {0,1,2,4,8,16,1025}; //cada valor não ocupa todos espaços nos endereços de memório, assim ficam vazios, e vamos conta-los
    int nBytes = 0, cont=0, i;
    unsigned char *pv;
    nBytes = sizeof(vetor);
    pv = (unsigned char*)vetor; //converte vetor em char para andar de 1 em 1 byte no vetor;
    for (i=0; i<nBytes; i++)
    {
    	printf("Byte %d: %X (decimal: %d)\n", i+1, *(pv+i), *(pv+i));//%x mostra valor no byte sem converte-lo em decimal
    	if(*(pv+i) == 0)
    	cont++;
	}
	printf("\nO numero total de bytes zerados sao: %i", cont);
    printf("\nO numero de bytes da variavel vetor e: %i", nBytes);
    return 0;
}

