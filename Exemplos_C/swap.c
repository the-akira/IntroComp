#include <stdio.h>

// Chamando uma função por endereço

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a, b;
	a = 10;
	b = 20;
	printf("Valor de a: %d\n",a);
	printf("Valor de b: %d\n",b);
	swap(&a,&b);
	printf("Valor swaped de a: %d\n",a);
	printf("Valor swaped de b: %d\n",b);
}