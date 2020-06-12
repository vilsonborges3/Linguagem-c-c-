//vilson borges 11821eel001
#include <stdio.h>
#include <string.h>

int main() {
	char str[17];
	int *pointStr = (unsigned int*)str;
	int i;
	for(i=0; i<=16; i++)
	str[i]=0;
	printf("Digite uma string: ");
	fgets(str,16,stdin);
	
	printf("\nDec: ");
	for(i=0; i<4; i++)
	{
		printf(" %d ", *(pointStr+i));
	}
	printf("\nHex:");
	for(i=0; i<4; i++)
	{
		printf(" %X ", *(pointStr+i));
	}
	
	return 0;
}
