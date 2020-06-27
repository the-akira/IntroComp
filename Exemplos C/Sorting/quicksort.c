#include <stdio.h>
#include "swap.h"

// Programa que implementa o algoritmo Quick Sort
// Time -> Min: O(nlogn) Max: O(n²)

// função partition: responsável por particionar o array
// Retorna a posição do elemento pivot
int partition(int A[], int l, int h)
{
	int pivot = A[l];
	int i = l, j = h;

	do
	{
		do{i++;}while(A[i] <= pivot);
		do{j--;}while(A[j] > pivot);
		if(i < j)swap(&A[i],&A[j]);
	}while(i < j);

	swap(&A[l],&A[j]);
	return j;
}

// função que implementa o algoritmo quick sort
void quicksort(int A[], int l, int h)
{
	int j;
	if(l < h)
	{
		j = partition(A,l,h);
		quicksort(A,l,j);
		quicksort(A,j+1,h);
	}
}

int main()
{
	int array[] = {3,10,13,27,2,1,8,15,99,180,4,5};
	int n = 12;
	quicksort(array,0,n);
	for(int i=0;i<n;i++)
		printf("%d\n",array[i]);
}