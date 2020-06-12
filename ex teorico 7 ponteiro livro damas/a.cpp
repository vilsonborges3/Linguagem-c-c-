#include <stdio.h>
#include <stdlib.h>

int  main()
{
	int i;
	int v[] = {10,20,30,40,50};
	int *pv;
	int **ppv;
	pv = &v[0];
	ppv = &pv;
	for(i=0; i<5; i++)
		{
			printf("vetor inteiro: %p",v[i]);
			printf("\nponteiro para inteiro: %p", pv[i]);
			printf("\nPonteiro para ponteiro de inteiro: %p\n\n\n ",v[i]);
			
		}
	system("PAUSE");
	return 0;
}
