#include<stdio.h>

int temp;

void swap_largest(int arr[], int n, int i) 
{ 
    int largest = i; // Inicializa o maior elemento como root
    int left = 2*i + 1; 
    int right = 2*i + 2; 

    // Testa se o left child é maior do que o root
    if (left < n && arr[left] > arr[largest]) 
        largest = left; 

    // Testa se o right child é maior que o maior elemento
    if (right < n && arr[right] > arr[largest]) 
        largest = right; 

    // Testa se o maior elemento não é root
    if (largest != i) 
    { 
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Chama recurisvamente a função swap_largest
        swap_largest(arr, n, largest); 
    } 
} 

void heap(int arr[], int n) 
{ 
    // Constrói a heap através de um array desordenado
    for (int i = n / 2 - 1; i >= 0; i--) 
        swap_largest(arr, n, i); 

    // Extrai elemento por elemento da heap
    for (int i = n - 1; i >= 0; i--) 
    { 
        // Move o root atual para o fim
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // chama a função swap_largest na heap reduzida
        swap_largest(arr, i, 0); 
    } 
}

int print(int arr[], int n)
{
	printf("Array ordenado:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
}

int main()
{
    int n, i;
    printf("Informe o tamanho do array:\n");
    if(scanf("%d",&n)){};
    int arr[n];
    printf("Informe os elementos do array:\n");
    for(i=0;i<n;i++)
    {
        if(scanf("%d",&arr[i])){};
    }
    heap(arr, n);
    print(arr, n);
}