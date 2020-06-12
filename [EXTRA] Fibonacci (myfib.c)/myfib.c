//vilson borges 11821eel001
#include <stdio.h>
#include <time.h>
int fibonacci(int vet[], int n)
{
	if(n == 0 || n == 1)
	{
		vet[0] = 1;
		vet[1] = 1;
		return 1;
	}
	if(vet[n-1] == 0)
		vet[n-1] = fibonacci(vet,n-1);
		return vet[n-1] + vet[n-2];		
}

int fib(int n) {
    int f;
    switch(n) {
        case 0: 
        case 1: f = 1; break;
        default: f = fib(n-1) + fib(n-2);
    }
    return f; 
}

int main ()
{
	int num=0, vet[100];
	int i;
	double tempo,tempo2;
	clock_t  f1t0, f2t0;
	for(i=0; i<100; i++)
		vet[i] = 0;
	printf("Digite o numero do termo da sequencia: \n");
	scanf("%d", &num);
	
	f1t0 = clock();
	fibonacci(vet, num); // chamando a função criada
	tempo = (clock()- f1t0);
	
	printf("Printando termos da funcao criada ate o termo solicitado: \n");
	for(i=0; i<num; i++)
		printf("%d ", vet[i]);
	printf("\n\nTempo gasto da funcao criada: %g.", tempo);
	
	f2t0 = clock();
	fib(num);
	tempo2 = (clock() - f2t0);
	 
	printf("\nTempo gasto da funcao dada: %g.", tempo2);
	return 0;
}
