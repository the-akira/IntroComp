#include <stdio.h>

// Função que cálcula o expoente de um número

/* Complexidade O(n) */
int power(int m, int n)
{	
	if(n==0)
		return 1;
	return power(m,n-1) * m; 
}

/* Número reduzido de multiplicações */
int exponent(int m, int n)
{
	if(n==0)
		return 1;
	if(n%2==0)
		return exponent(m*m,n/2);
	else
		return m*exponent(m*m,(n-1)/2);
}

int main()
{
	int x = 5;
	int z = 2;
	printf("%d elevado %d = %d\n",x,z,power(x,z));
	printf("%d elevado %d = %d\n",z,x,exponent(z,x));
}