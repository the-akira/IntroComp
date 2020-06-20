#include <stdio.h>

void quicksort(int v[], int left, int right);

// Função main(): testa o algoritmo Quick Sort
int main(void)
{
	int array[] = {5,6,7,9,8,10,3,1,2,50,33,45,13,4};
	printf("Primeiro item do array: %d\n", array[0]);
	printf("Último item do array: %d\n", array[13]);
	printf("Array desordenado\n");
	for(int i = 0; i < 14; i++)
		printf("%u\n", array[i]);
	quicksort(array, 0, 13);
	printf("---\n");
	printf("Array ordenado\n");
	for(int i = 0; i < 14; i++)
		printf("%u\n", array[i]);
}

// quicksort(): ordena v[left]...v[right] em ordem crescente
void quicksort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);
	if(left >= right) // Não faz nada se o array 
		return;		  // tiver menos de dois elementos	
	swap(v, left, (left + right)/2); // move o elemento partido para a partição v[0]
	last = left;
	for(i = left + 1; i <= right; i++)
		if(v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last); // restaura o elemento partido
	quicksort(v, left, last - 1);
	quicksort(v, last + 1, right);
}

// Função swap(): troca v[i] e v[j]
void swap(int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}