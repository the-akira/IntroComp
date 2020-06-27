#include <stdio.h>

// Programa que implementa o algoritmo Shell Sort
// Adaptive & Inplace

// função shell_sort que implementa o algoritmo Shell Sort
void shell_sort(int A[], int n)
{
	int gap, i, j, temp;

	for(gap=n/2;gap>=1;gap/=2)
	{
		for(i=gap;i<n;i++)
		{
			temp = A[i];
			j = i - gap;
			while(j >= 0 && A[j] > temp)
			{
				A[j+gap] = A[j];
				j = j - gap;
			}
			A[j+gap] = temp;
		}
	}
}

int main()
{
	int array[] = {3,10,13,27,2,1,8,15,99,180,4,5};
	int n = 12;
	shell_sort(array,n);
	for(int i=0;i<n;i++)
		printf("%d\n",array[i]);
}