//vilson 11821eel001
#include <stdio.h>
void divide(int *num, int *den, int *resto, int *quociente)
{
	*quociente = *num/(*den);
	*resto = (*num)%(*den);
}

int main ()
{
	int num, den, resto, quociente;
	printf("Digite o numerador e o denominador, respectivamente:");
	scanf("%d%d", &num, &den);
	divide(&num,&den,&resto,&quociente);
	printf("\nO quociente e %d\nO resto e %d", quociente, resto);
	
	return 0;
}
