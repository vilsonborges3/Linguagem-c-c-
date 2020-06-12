//Vilson borges - 11821eel001
#include <stdio.h>
#include <math.h>
typedef void TipoFuncao();
void fun1(double a[], double b[], int sizea)
{
	int i;
	
	for(i=0; i<sizea; i++)
	a[i] = sqrt(a[i] + b[i]);
	
}
void fun2(double a[], double b[], int sizea)
{
	int i;
	for(i=0; i<sizea; i++)
	a[i] = a[i]+(3*b[i]);
	
}
void fun3(double a[], double b[], int sizea)
{
	int i;
	for(i=0; i<sizea; i++)
	a[i] = (b[i]*b[i])/a[i];
}
int main()
{
	int sizeA, sizeB, digito=0,i;
	void fun1(double a[], double b[], int sizea);
	double A[] = {1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0, 17.0, 19.0, 21.0, 23.0, 25.0, 27.0, 29.0, 31.0};
	double B[] = {0.5, 0.25, 0.125, 0.0625, 0.5, 0.25, 0.125, 0.0625, 0.5, 0.25, 0.125, 0.0625, 0.5, 0.25, 0.125, 0.0625};
	TipoFuncao *p;
	
	sizeA = sizeof(A)/sizeof(double);
	sizeB = sizeof(B)/sizeof(double);

	
	printf("Digite 1 para raiz de A+B, 2 para A + 3B e 3 para B^2/A \n");
	scanf("%d", &digito);
	switch(digito)
	{
		case 1:{
			p = fun1;
			p(A, B, sizeA);
			for(i=0; i<sizeA; i++)
			printf("\n%lf", A[i]);
			break;
		}
		case 2:{
			p = fun2;
			p(A, B, sizeA);
			for(i=0; i<sizeA; i++)
			printf("\n%lf", A[i]);
			break;
		}
		case 3:{
			p = fun3;
			p(A, B, sizeA);
			for(i=0; i<sizeA; i++)
			printf("\n%lf", A[i]);
			break;
		}
		default :
    	printf ("Valor invalido!\n");
		
	}
	return 0;
}
