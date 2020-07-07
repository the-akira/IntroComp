#include <stdio.h>

// Exemplo de programa que avalia se
// um número digitado é par ou ímpar

int main(void)
{
	int num;
	printf("Digite um número: ");
	scanf("%d",&num);

	if(num % 2 == 0)
		printf("%d é um número par\n",num);
	else
		printf("%d é um número ímpar\n",num);
}