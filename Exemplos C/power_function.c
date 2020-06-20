#include <stdio.h>

int power(int m, int n);

// testando a função power()
int main(void)
{
	int i;

	for(i = 0; i <= 10; ++i)
		printf("%d %d %d\n", i, power(2,i), power(3,i));
}

// função power: eleva a base para a potência n-th; n >= 0
int power(int base, int n)
{
	int i, p;
	p = 1;

	for(i = 1; i <= n; ++i)
		p = p * base;
	return p;
}