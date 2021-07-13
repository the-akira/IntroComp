#include <stdio.h>

// Funções que computam a soma
// dos n primeiros números naturais

/* Fórmula: Complexidade O(1) */
int sumA(int n)
{
    return n*(n+1)/2;
}

/* Iterações: Complexidade O(n) */
int sumB(int n)
{
    int i, s=0;
    for(i=1; i<=n; i++)
        s = s + i;
    return s;
}

/* Recursão: Complexidade O(n) */
int sumC(int n)
{
    if(n==0)
        return 0;
    else
        return sumC(n-1)+n;
}

int main()
{
    int a, b, c, x=10, y=15, z=20;
    a = sumA(x);
    b = sumB(y);
    c = sumC(z);
    printf("sumA=%d\nsumB=%d\nsumC=%d\n",a,b,c);
}