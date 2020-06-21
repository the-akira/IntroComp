#include <stdio.h>
#include <stdlib.h>

// Inicializando arrays em C

int main()
{
	// Criando arrays em Stack
	int A[5];
	int B[5]={1,2,3,4,5};
	int C[10]={2,8,10};
	int D[7]={0};
	int E[]={1,3,5,7,9,11};

	printf("%d\n",A[1]);
	printf("%d\n",B[0]);
	printf("%d\n",C[2]);
	printf("%d\n",D[4]);

	printf("---\n");

	for(int i=0; i<5; i++)
	{
		printf("Endereço=%p\n",&E[i]);
		printf("Valor=%d\n",E[i]);
		printf("Tamanho em bytes=%lu\n",sizeof(E[i]));
	}

	// Criando um array em Heap
	int *p;
	p = (int *)malloc(2*sizeof(int));
	p[0]=13;
	p[1]=17;
	for(int i=0; i<2; i++)
		printf("%d\n",p[i]);
	free(p);
}