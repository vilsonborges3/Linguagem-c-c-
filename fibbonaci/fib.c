#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n, f;
	printf("Digite qual  numero de fibonacci voce quer: ");
	scanf("%d", &n);
	f = fib(n);
	printf("\nO numero de fib e: %d", f);
	
	
	return 0;
}
int fib(int n)
{
	if((n == 0) || (n == 1))
		return 1;
	else
		return (fib(n-1) + fib(n-2));
}
