#include <stdio.h>

int main(void)
{
	int num;
	unsigned long long factorial = 1;

	do
	{
		printf("Entre um inteiro positivo: ");
		scanf("%d",&num);
	}
	while(num < 0);

	for(int i = 1; i <= num; i++)
		factorial = factorial * i;
	printf("%d! = %llu\n",num,factorial);
}