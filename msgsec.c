//vilson borges 11821eel001
#include <stdio.h>
#include <string.h>
int main() {
	
	int valor;
	printf("Digite 1 para criplitografar ou 2 para descriplitografar");
	scanf("%d", &valor);
	if((valor != 2) && (valor != 1))
	{
		printf("\nO valor digitado esta errado!!");
	}
	else{
		system("cls");
		fflush(stdin);
		if(valor == 1){
		printf("Funcao criplitografar!!");
		char str1[256];
		int i;
		long long int *pStr1;
		pStr1 = (long long unsigned int*)str1;
		for(i=0; i<256; i++)
			str1[i] = '\0';
		printf("\nDigite uma string: ");
		fgets(str1, 256, stdin);
		for(i = 0; i<8; i++)
		{
			if(*(pStr1+i) != 0)
				printf("\n%lld %X ", *(pStr1+i), (pStr1+i));	
		}	
	}else{
		int j;
		printf("Opcao descriplitografar ativada:");
		long long int number[32];
		for(j=0; j<32; j++)
			number[j] = 0;
		printf("\nDigite a string criplitografada na forma de inteiro e o numero 'zero' para dererminar o final: ");
		for(j=0;j<32;j++)
		{
			scanf("%lld",&number[j]);
			if(number[j] == 0)
				j = 33; //break
		}
		char *pointN;
		int nBytes = sizeof(number);
		pointN = (unsigned char*)number;	
		for(j=0; j<nBytes; j++)
		{
			printf("%c", *(pointN+j));
		}	
	}	
	}
	return 0;
}
