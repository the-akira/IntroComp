#include <stdio.h>
#include "swap.h"

// Programa que implementa o algoritmo Bubble Sort
// Adaptive & Stable
// Time -> Min: O(n) Max: O(n²)

// função que define o algoritmo bubble sort
// Recebe um array e o número de elementos desse array
void bubble_sort(int A[], int n)
{
    int i, j, flag=0;

    for(i=0;i<n-1;i++)
    {
        flag = 0;
        for(j=0;j<n-i-1;j++)
        {
            if(A[j] > A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}

int main()
{
    int array[] = {3,10,13,27,2,1,8,15,99,180,4,5};
    int n = 12;
    bubble_sort(array,n);
    for(int i=0;i<n;i++)
        printf("%d\n",array[i]);
}