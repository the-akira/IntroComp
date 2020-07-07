#include <stdio.h>

// Exemplo de um programa iterativo que itera sob um array

int main(void)
{
	int array[] = {10,20,30,40,50};
	int len = sizeof(array) / sizeof(array[0]);

	for(int i = 0; i < len; i++)
		printf("Valor no índice %d = %d\n",i,array[i]);
}