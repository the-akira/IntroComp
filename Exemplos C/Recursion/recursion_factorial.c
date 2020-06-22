#include <stdio.h>

double factorial(int n)
{	
	if(n == 0)
		return 1;
	else
		return factorial(n-1) * n;
}

int main()
{
	int x = 6;
	printf("Fatorial de %d = %lg\n",x,factorial(x));
}