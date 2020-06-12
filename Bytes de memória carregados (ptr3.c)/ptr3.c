//vilson borges 11821eel001
#include <stdio.h>

int main() {
	int vetor[] = {0x0F,0xFF,0xFFFF,0xFFFFFF,0x80000001,0xFFFFFFFF};
	int nBytes = 0,i,cont=0;
	unsigned char *pointV;
	nBytes = sizeof(vetor);
	pointV = (unsigned char*)vetor; //converte v em char para somar 1 byte na aritmetica de ponteiros
	for(i=0; i<nBytes; i++)
	{
		printf("\nByte %d, %X (decimal %i)", i+1, *(pointV+i), *(pointV+i));
		if(*(pointV + i) != 0)
			cont++;
		
	}
    printf("\nO numero total de bytes: %i, bytes com pelo menos um bit: %i",nBytes,cont);
    return 0;
}
