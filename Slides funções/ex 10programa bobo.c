#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define n 3
int ma(char str[][80], int num);
int main()
{
	int i;
	int pt;
	char frase[n][80];
	for (i=0; i<n; i++)
        {
        	printf ("Digite uma string:\n");
        	gets (frase[i]);
        }
    pt = ma(frase,n);
	printf("\nMaior string e: %s", frase[pt]);
	system("PAUSE");
	return 0;
}
int ma(char str[][80], int num)
{
	int i, maior=0, j=0,lugar=0;
	for(i=0; i<num; i++)
	{
		j =0;
		while(str[i][j] != '\0')
			j++;
			printf("\nLinha: %d somou %d",i,j);
		if(j > maior)
			{
				maior = j;
				lugar = i;
			}
	}
	printf("\nStr: %s",str[lugar]);
	return lugar;
}


