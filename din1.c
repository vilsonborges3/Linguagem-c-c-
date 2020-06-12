//vilson
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

float media(float *x, int num);
float desvio(int m, int n, float *x);

int main()
{	
		int i,n;
		printf("Digite o numero de valores:");
		scanf("%d", &n);
		float  soma=0, m,dp;
		float *x;
		x = calloc(n, sizeof(float));
		printf("Digite os %i valores:", n);
		for(i=0; i<n; i++)
			scanf("%f", &x[i]);
		//calculo da media
		m = media(x, n);
			printf("\nA media e: %f", m);
		//calculo do dp
		dp = desvio(m ,n , x);
		printf("\nO desvio padrao: %f",dp);
		free(x);
	return 0;
}

float media(float *x, int n)
{
	int i;
	float m, soma=0;
	for(i = 0; i < n; i++)
		soma = soma + x[i];
	m = soma/n;
	return m;
}

float desvio(int m, int n, float *x)
{
	float dif, pot, soma2 = 0,div,dp, media=0;
	int i;
		for(i=0; i<n; i++)
		{
			dif = x[i] - m;
			pot = dif*dif;
			soma2 = soma2 + pot;
		}
	div = soma2/(n-1);
	dp = sqrt(div);
	return dp;
}
