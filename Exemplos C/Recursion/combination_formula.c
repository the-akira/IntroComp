#include <stdio.h>

/*
Funções que computam a fórmula de combinações
NCR retorna o número de permutações
n é o número total de objetos no conjunto
r é o número de objetos a serem escolhidos do conjunto
*/

int fact(int n)
{
	if(n==0)
		return 1;
	return fact(n-1)*n;
}

int ncr(int n, int r)
{
	int num, den;
	num = fact(n);
	den = fact(r)*fact(n-r);
	return num/den;
}

int ncr_recursive(int n, int r)
{
	if(n==r || r==0)
		return 1;
	return ncr_recursive(n-1,r-1)+ncr_recursive(n-1,r);
}

/*
Luís está pedindo uma pizza e vai pedir com dois sabores.
Se a pizzaria que ele está pedindo tem 12 tipos de sabores diferentes
Quantas combinações de dois sabores ele poderá escolher?
*/

int main()
{
	printf("%d\n",ncr(12,2));
	printf("%d\n",ncr_recursive(12,2));
}