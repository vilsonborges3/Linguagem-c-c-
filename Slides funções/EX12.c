#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Vamos descobrir o digito verificador da sua agencia formato ABCD-DV!\n");
	printf("Onde ABCD e o codigo da agencia e DV o digito verificador\n\n\n");
	int ag[4];
	int i, soma=0, dv,j;
	system("PAUSE");
	system("cls");
	for(i=0; i<4; i++)
	{
		printf("Digite o numero %c da agencia e tecle enter: ",65+i);
		scanf("%d", &ag[i]);
		system("cls");
	}
	system("PAUSE");
	for(i=0,j=5; i<4,j>=2; i++,j--)
	{
		ag[i] = ag[i]*j; 
	}	
	for(i=0; i<4; i++)
	{
		soma = soma+ag[i];
	}
	soma = soma*10;
	dv = soma%11;
	printf("DV = %d",dv);
	return 0;
}
