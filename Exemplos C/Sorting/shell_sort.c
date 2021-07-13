#include <stdio.h>

void shellsort(int v[], int n);

// Testando o algoritmo Shell Sort
int main(void)
{
    int array[] = {5,6,7,9,8,10,3,1,2};
    printf("Primeiro item do array: %d\n", array[0]);
    printf("Último item do array: %d\n", array[8]);
    printf("Array desordenado\n");
    for(int i = 0; i < 9; i++)
        printf("%u\n", array[i]);
    shellsort(array, 9);
    printf("---\n");
    printf("Array ordenado\n");
    for(int i = 0; i < 9; i++)
        printf("%u\n", array[i]);
}

// shellsort: organiza v[0]...v[n-1] em ordem crescente
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for(gap = n/2; gap > 0; gap /= 2)
        for(i = gap; i < n; i++)
            for(j = i-gap; j >= 0 && v[j] > v[j+gap]; j-=gap)
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}