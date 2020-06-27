#include <stdio.h>

// Programa que implementa o algoritmo Insertion Sort
// Adaptive & Stable
// Time -> Min: O(n) Max: O(n²)

// função que implementa o algoritmo insertion sort
// Recebe um array e o número de elementos do array
void insertion_sort(int A[], int n)
{
	int i, j, x;

	for(i=1;i<n;i++)
	{
		j = i - 1;
		x = A[i];

		while(j > -1 && A[j] > x)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = x;
	}
}

int main()
{
	int array[] = {3,10,13,27,2,1,8,15,99,180,4,5};
	int n = 12;
	insertion_sort(array,n);
	for(int i=0;i<n;i++)
		printf("%d\n",array[i]);
}