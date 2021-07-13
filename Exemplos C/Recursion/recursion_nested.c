#include <stdio.h>

int func(int n)
{
    if(n > 100)
        return n-10;
    else
        return func(func(n+15));
}

int main()
{
    int r;
    r = func(120);
    printf("%d\n",r);
}