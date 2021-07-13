#include <stdio.h>

// Programa que valida uma String

// Função que retorna se a string é válida ou não
int valid(char *str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(!(str[i] >= 65 && str[i] <= 90) &&
            !(str[i] >= 97 && str[i] <= 122) &&
            !(str[i] >= 48 && str[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char *name="?%$1joaox!";
    char *nome="gabriel";
    printf("String é válida? %d\n",valid(name));
    printf("String é válida? %d\n",valid(nome));
}