//vilson borges 11821eel001
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define n 256

int main()
{
	int j,i;
	char palavra[5][n];
	char aux[n];

    printf("Digite tres frase!\n");
    for(i=0;i<5;i++)
    {
    	fflush(stdin);
    	scanf("%s",palavra[i]);
	}

    for(i=0;i<5;i++)
	{
		 for(j=i;j<5;j++)
		 {
		 	if(i==j)
		 	continue;
		 	if(strcmp(palavra[i], palavra[j]) > 0)
		 	{
			strncpy(aux, palavra[i],n);
		 	strncpy(palavra[i], palavra[j],n);
		 	strncpy(palavra[j], aux,n);
			}
		 
		 }
	
	}
	
	for(i=0;i<5;i++)
	{
	printf("\n%s\n",palavra[i]);
	
	}
	

    
 //   for(i=0; i<pal-1; i++)
//	frase[i] = toupper(frase[i]);   
    
    

    return 0;
}
