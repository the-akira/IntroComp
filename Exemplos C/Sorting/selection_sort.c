#include <stdio.h>
#include "swap.h"

// Programa que implementa o algoritmo Selection Sort
// Non-Adaptive & Non-Stable
// Time -> Min: O(n) Max: O(n²)

// função que implementa o algoritmo selection sort
// Recebe um array e o número de elementos do array
void selection_sort(int A[], int n)
{
	int i, j, k;

	for(i=0;i<n-1;i++)
	{
		for(j=k=i;j<n;j++)
		{
			if(A[j] < A[k])
				k = j;
		}
		swap(&A[i],&A[k]);
	}
}

int main()
{
	int array[] = {3,10,13,27,2,1,8,15,99,180,4,5};
	int n = 12;
	selection_sort(array,n);
	for(int i=0;i<n;i++)
		printf("%d\n",array[i]);
}