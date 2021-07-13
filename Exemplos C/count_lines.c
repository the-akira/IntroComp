#include <stdio.h>

// programa que conta a quantidade de linhas
int main()
{
    int c, n1;
    while((c = getchar()) != EOF){
        if(c == '\n')
            ++n1;
    }
    printf("Total Lines: %d\n",n1);
}
