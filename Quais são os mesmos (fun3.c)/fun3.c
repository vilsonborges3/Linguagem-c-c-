//vilson 11821eel001
#include <stdio.h>
void ver(int *tamA, int *tamB, int *A, int *B)
{
	int i,j;
	for(i = 0; i < *tamA; i++)
	{
		for(j = 0; j < *tamB; j++)
		{
			if(A[i] == B[j])
			{
				printf("%d ", A[i]);
			}
		}
	}
	
	
}

int main ()
{
	
	int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31};
	int B[] = {1, 2, 3, 4, 5, 6, 8, 10, 12, 7, 29};
	int tamA, tamB;
	tamA = sizeof(A)/sizeof(int);
	
	tamB = sizeof(B)/sizeof(int);
	
	ver(&tamA, &tamB, A, B);
	
	return 0;
}
