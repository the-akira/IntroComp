#include <stdio.h>
#include <stdlib.h>

// Criando uma Estrutura de Dados Array

// Estrutura que define um Array
struct Array
{
    int *A;
    int size;
    int length;
};

// Função que imprime os valores do Array
// Recebe um array
void display_array(struct Array arr)
{
    int i;
    printf("Elementos atuais do array:\n");
    for(i=0;i<arr.length;i++)
        printf("%d \n",arr.A[i]);
}

// Função que adiciona um elemento no fim do array
// Recebe um array e um elemento a ser adicionado
void append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
        arr->A[arr->length++]=x;
}

// Função que adiciona um elemento em um determinado índice do array
// Recebe um array, um índice e um elemento
void insert(struct Array *arr, int index, int x)
{
    int i;
    if(index >= 0 && index <= arr->length)
    {
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
    else {
        printf("Índice inválido\n");
    }
}

// Função que deleta um elemento em um determinado índice
// Recebe um array e o índice do elemento a ser removido
int delete(struct Array *arr, int index)
{
    int i, x=0;

    if(index >= 0 && index <= arr->length)
    {
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }
    else {
        printf("Índice inválido\n");
    }
}

// Função que troca o valor de dois elementos
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Função de busca linear
// Recebe um array e um elemento a ser procurado
// Retorna o elemento encontrado 
// Retorna -1 se ele não estiver presente
int linear_search(struct Array arr, int key)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        if(key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}

// Função de busca linear otimizada
// Recebe um array e um elemento a ser procurado
// Retorna o elemento encontrado e coloca ele no ínicio do array 
// Retorna -1 se ele não estiver presente
int linear_search_optm(struct Array *arr, int key)
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i],&arr->A[0]);
            return i;
        }
    }
    return -1;
}

// Algoritmo de busca binária
// Recebe um array ordenado e um elemento a ser procurado
int binary_search(struct Array arr, int key)
{
    int low, mid, high;
    low = 0;
    high = arr.length-1;

    while(low <= high)
    {
        mid = (low+high)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

// Algoritmo de busca binária recursivo
// Recebe um array ordenado, primeiro índice, último índice e o elemento
int bin_search_rec(int a[], int low, int high, int key)
{
    int mid;
    if(low <= high)
    {
        mid = (low + high)/2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return bin_search_rec(a,low,mid-1,key);
        else
            return bin_search_rec(a,mid+1,high,key);
    }
    return -1;
}

// Função get
// Recebe um array e um índice 
// Retorna o elemento caso ele exista
int get(struct Array arr, int index)
{
    if(index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

// Função set
// Recebe um array, um índice e um elemento
// Altera o elemento no índice fornecido
void set(struct Array *arr, int index, int x)
{
    if(index >= 0 && index < arr->length)
        arr->A[index]=x;
}

// Função max: retorna o maior elemento do array
int max(struct Array arr)
{
    int i, max=arr.A[0];
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i] > max)
            max=arr.A[i];
    }
    return max;
}

// Função min: retorna o menor elemento do array
int min(struct Array arr)
{
    int i, min=arr.A[0];
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i] < min)
            min=arr.A[i];
    }
    return min;
}

// Função sum: retorna a soma dos elementos do array
int sum(struct Array arr)
{
    int i, soma=0;
    for(i=0;i<arr.length;i++)
        soma += arr.A[i];
    return soma;
}

// Função avg: retorna a média dos elementos do array
float avg(struct Array arr)
{
    return (float)sum(arr)/arr.length;
}

// Função reverse: reverte o conteúdo o array
void reverse(struct Array *arr)
{
    int *B;
    int i, j;
    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        B[j]=arr->A[i];
    for(i=0;i<arr->length;i++)
        arr->A[i]=B[i];
}

// Função rev: reverte o conteúdo o array
void rev(struct Array *arr)
{
    int i, j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

// Função insert_sort: insere um elemento em um array ordenado
void insert_sort(struct Array *arr, int x)
{
    int i = arr->length-1;
    if(arr->length == arr->size)
        return;
    while(i >= 0 && arr->A[i] > x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

// Função merge: faz a união de dois arrays
// Recebe dois arrays e retorna a união deles
struct Array* merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;
    return arr3;
}

// Função is_sorted: checa se o array está ordenado ou não
int is_sorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i] > arr.A[i+1])
            return 0;
    }
    return 1;
}

/* Operações de Conjuntos */

// Função Union: Faz a união de dois conjuntos (sem repetir elementos)
struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else 
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

// Função Difference: Retorna os elementos presentes apenas no primeiro array
struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else 
        {
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

// Função Intersection: Seleciona apenas os elementos em comum dos arrays
struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            i++;
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else if(arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

int main()
{
    struct Array arr1;
    int choice, index, x;

    printf("Informe o tamanho do array: ");
    if(scanf("%d",&arr1.size)){};
    arr1.A=(int *)malloc(arr1.size*sizeof(int));
    arr1.length=0;

    do {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display Data\n");
        printf("6. Exit\n");

        printf("Qual sua escolha?\n");
        if(scanf("%d", &choice)){};

        switch(choice)
        {
            case 1: printf("Entre um elemento e o índice: ");
                    if(scanf("%d%d",&x,&index)){};
                    insert(&arr1,index,x);
                    break;
            case 2: printf("Informe o índice do elemento: ");
                    if(scanf("%d",&index)){};
                    x = delete(&arr1,index);
                    printf("O elemento removido é: %d\n",x);
                    break;
            case 3: printf("Entre um elemento a ser buscado: ");
                    if(scanf("%d",&x)){};
                    index = linear_search_optm(&arr1,x);
                    printf("O índice do elemento é: %d\n",index);
                    break;
            case 4: printf("A soma dos elementos é %d\n",sum(arr1));
                    break;
            case 5: display_array(arr1);
        }
    } while(choice < 6);
}