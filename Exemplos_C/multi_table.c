#include <stdio.h>

// Programa que imprime: 
// Tabela de multiplicação
int main()
{
	int i, j;

	for(i = 1; i <= 10; i++)
		for(j = 1; j <= 10; j++)
			printf("%5d",i * j);

	printf("\n");
}