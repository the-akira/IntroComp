#include <stdio.h>

// Problema da Torre de Hanói

// Complexidade: O(2^n)
// n -> número de discos
// A -> número da torre
// B -> número da torre
// C -> número da torre
void TOH(int n, int A, int B, int C)
{
	if(n>0)
	{
		TOH(n-1,A,C,B);
		printf("Move o disco da Torre ||%d|| para Torre ||%d||\n",A,C);
		TOH(n-1,B,A,C);
	}
}

int main()
{
	TOH(3,1,2,3);
}