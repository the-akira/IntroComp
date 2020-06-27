#include <stdio.h>

// Programa que implementa o algoritmo Merge Sort

// função merge: faz a união de dois arrays
void merge(int A[], int low, int mid, int high)
{
	int i=low, j=mid+1, k=low;
	int B[100];

	while(i <= mid && j <= high)
	{
		if(A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	for(;i<=mid;i++)
		B[k++] = A[i];
	for(;j<=high;j++)
		B[k++] = A[j];
	for(int i=low;i<=high;i++)
		A[i] = B[i];
}

// função que implementa o algoritmo merge sort iterativo
void merge_sort_iterative(int A[], int n)
{
	int p, low, high, mid, i;
	for(p=2;p<=n;p=p*2)
	{
		for(i=0;i+p-1<n;i=i+p)
		{
			low = i;
			high = i + p - 1;
			mid = (low + high)/2;
			merge(A,low,mid,high);
		}
	}
	if(p/2 < n)
		merge(A,0,(p/2)-1,n-1);
}

// função que implementa o algoritmo merge sort recursivo
void merge_sort(int A[], int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high)/2;
		merge_sort(A,low,mid);
		merge_sort(A,mid+1,high);
		merge(A,low,mid,high);
	}
}

int main()
{
	int arr[] = {100,200,350,222,111,66,88,33,40,21,45,93};
	int array[] = {3,10,13,27,2,1,8,15,99,180,4,5};
	int n = 12;

	merge_sort_iterative(array,n);
	for(int i=0;i<n;i++)
		printf("%d\n",array[i]);

	printf("\n");

	merge_sort(arr,0,n-1);
	for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);
}