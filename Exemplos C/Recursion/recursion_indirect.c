#include <stdio.h>

void funcB(float n);

void funcA(float n)
{
	if(n > 0)
	{
		printf("%f\n",n);
		funcB(n-1);
	}
}

void funcB(float n)
{
	if(n > 1)
	{
		printf("%f\n",n);
		funcA(n/2);
	}
}

int main()
{
	int x = 20;
	funcA(x);
}