#include <stdio.h>

// Buscar elemento faltante em um array ordenado

int main()
{
	int low, high, total, diff;
	int arr[] = {1,2,3,4,5,6,7,8,10};
	low = 1;
	high = 10;
	total = 9;
	diff = low - 0;
	for(int i=0;i<total;i++)
	{
		if(arr[i]-i != diff)
		{
			printf("elemento faltante: %d\n",i+diff);
			break;
		}
	}
}