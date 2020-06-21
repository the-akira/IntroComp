#include <stdio.h>
#include <stdlib.h>

// Criando uma Estrutura de Dados Array

// Estrutura que define o Array
struct Array
{
	int *A;
	int size;
	int length;
};

// Função que imprime os valores do Array
void display_array(struct Array arr)
{
	int i;
	printf("Elementos do array são\n");
	for(i=0;i<arr.length;i++)
		printf("%d \n",arr.A[i]);
}

int main()
{
	int n, i;
	// Inicializando o array em Heap
	struct Array arr;
	printf("Informe o tamanho do Array: ");
	if(scanf("%d",&arr.size)){};
	arr.A=(int *)malloc(arr.size*sizeof(int));
	arr.length=0;

	printf("Informe a quantidade de números: ");
	if(scanf("%d",&n)){};

	printf("Entre todos os elementos do array\n");
	for(i=0;i<n;i++)
		if(scanf("%d",&arr.A[i])){};
	arr.length = n;
	display_array(arr);
}