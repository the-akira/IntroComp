#include <stdio.h>

// Complexidade: O(2^n)
int fib_rec(int n)
{
	if(n<=1)
		return n;
	return fib_rec(n-2) + fib_rec(n-1);
}

// Complexidade: O(n)
int f[15];
int fib_memo(int n)
{
	if(n<=1){
		f[n]=n;
		return n;
	}
	else{
		if(f[n-2]==-1)
			f[n-2]=fib_memo(n-2);
		if(f[n-1]==-1)
			f[n-1]=fib_memo(n-1);
		return f[n-2]+f[n-1];
	}
}

// Complexidade: O(n)
int fib_iterative(int n)
{
	int a = 0, b = 1, c, i;
	if(n==0) 
		return a;
	for(i=2;i<=n;i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

int main()
{
	int i;
	for(i=0;i<15;i++)
		f[i]=-1;
	printf("%d\n",fib_rec(7));
	printf("%d\n",fib_memo(15));
	printf("%d\n",fib_iterative(9));
}