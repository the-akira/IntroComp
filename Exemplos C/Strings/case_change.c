#include <stdio.h>

// Programa que troca o case de uma string

int main()
{
    char L[] = "JAVASCRIPT";
    char M[] = "haskell";
    char N[] = "rUsT";
    int i;
    // Transforma em lowercase
    for(i=0;L[i]!='\0';i++)
    {
        L[i] += 32;
    }
    // Transforma em uppercase
    for(i=0;M[i]!='\0';i++)
    {
        M[i] -= 32;
    }
    // Toggle case (Upper -> Lower) (Lower -> Upper)
    for(i=0;N[i]!='\0';i++)
    {
        if(N[i] >= 65 && N[i] <= 90)
            N[i] += 32;
        else if(N[i] >= 'a' && N[i] <= 122)
            N[i] -= 32;
    }
    printf("%s\n",L);
    printf("%s\n",M);
    printf("%s\n",N);
}