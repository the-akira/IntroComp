#include <stdio.h>

// Exemplo de programa iterativo que executa
// um bloco de código até o usuário digitar um
// número negativo

int main(void)
{
	int num;
	do
	{
		printf("Digite um número negativo: ");
		scanf("%d",&num);
	}
	while(num >= 0);

	printf("Número digitado = %d\n",num);
}