//vilson borges
#include <stdio.h>
int soma_racional(int num1, int den1, int num2, int den2, int *Rnum, int *Rden)
{
	if((den1 == 0) || (den2 == 0))
	{
		printf("\nErro!!");
		return 0;	
	}
	else
	{
		*Rnum = den2*num1 + den1*num2;
		*Rden = den1*den2;
		return 1;	
	}
}
int calculoMDC(int ma, int me)
{
	int resto=1, m,aux;
	while (resto != 0)
	{
		resto = ma%me;
		aux = me;
		me = resto;
		ma = aux;
		if(resto == 0)
		{
			m = ma;
			return m;
		}
		calculoMDC(ma,me);	
	}
}
int main()
{
	int n1, d1, n2, d2, Rnum, Rden,mdc,aux1,aux2,maior,menor;
	printf("Entre com o primeiro numerador e o denominador, separados por virgula:");
	scanf("%d,%d",&n1,&d1);
	printf("\nEntre com o primeiro numerador e o denominador, separados por virgula:");
	scanf("%d,%d",&n2,&d2);
	soma_racional(n1, d1, n2, d2, &Rnum, &Rden);
		printf("%i/%i",Rnum,Rden);

	if(Rnum>Rden)
		{
			maior = Rnum;
			menor = Rden;
			mdc = calculoMDC(maior, menor);
		}
	if(Rden>Rnum)
		{
			maior = Rden;
			menor = Rnum;
			mdc = calculoMDC(maior, menor);
		}
printf("\nMDC %d", mdc);
Rnum = Rnum/mdc;
Rden = Rden/mdc;
printf("\nNumero Simplificado: %i/%i",Rnum,Rden);
return 0;
}
