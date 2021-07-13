#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Programa que implementa o algoritmo Count Sort
// Time -> O(n) 

// função find_max: retorna o maior elemento de um array
int find_max(int A[], int n)
{
    int max = INT_MIN;
    int i;

    for(i=0;i<n;i++)
    {
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

// função count_sort que implementa o algoritmo Count Sort
void count_sort(int A[], int n)
{
    int i, j, max, *count;
    max = find_max(A,n);
    count = (int *)malloc(sizeof(int)*(max+1));
    for(i=0;i<max+1;i++)
    {
        count[i] = 0;
    }
    for(i=0;i<n;i++)
    {
        count[A[i]]++;
    }
    i = 0; j = 0;
    while(j < max+1)
    {
        if(count[j] > 0)
        {
            A[i++] = j;
            count[j]--;
        }
        else
            j++;
    }
}

int main()
{
    int array[] = {3,10,13,27,2,1,8,15,99,180,4,5};
    int n = 12;
    count_sort(array,n);
    for(int i=0;i<n;i++)
        printf("%d\n",array[i]);
}