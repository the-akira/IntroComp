#include <stdio.h>

// Buscando o número de caracteres em uma string

int main()
{
	int i;
	char *string = "python";
	for(i=0;string[i]!='\0';i++){}
	printf("O tamanho da string é: %d\n",i);
}