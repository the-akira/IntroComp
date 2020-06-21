#include <stdio.h>
#include <stdlib.h>

// Criando arrays de 2 Dimensões
// Diferentes métodos

int main()
{
	/* 1 */
	// Criando um array em Stack
	int A[3][4]={{1,2,3,4},{2,4,6,8},{5,7,9,4}};

	/* 2 */
	// Criando um array em Stack
	int *B[3];
	// Criando arrays em Heap
	B[0] = (int *)malloc(4*sizeof(int));
	B[1] = (int *)malloc(4*sizeof(int));
	B[2] = (int *)malloc(4*sizeof(int));

	/* 3 */
	// Criando um array de ponteiros
	int **C;
	C=(int **)malloc(3*sizeof(int *));
	C[0]=(int *)malloc(4*sizeof(int));
	C[1]=(int *)malloc(4*sizeof(int));
	C[2]=(int *)malloc(4*sizeof(int));
	free(C);

	int i, j;
	// Imprimindo o array A
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			printf("%2d",A[i][j]);
		printf("\n");
	}
}