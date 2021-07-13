#include <stdio.h>

double e(int x, int n)
{
    static double p=1, f=1;
    double r;
    if(n==0)
        return 1;
    r = e(x,n-1);
    p = p*x;
    f = f*n;
    return r + p/f;
}

double e_interative(int x, int n)
{
    double s;
    for(s=1;n>0;n--)
        s=1+x*s/n;
    return s;
}

double e_recursion(int x, int n)
{
    static double s;
    if(n==0)
        return s;
    s=1+x*s/n;
    return e(x,n-1);
}

int main()
{
    printf("%lf\n",e_interative(1,80));
}