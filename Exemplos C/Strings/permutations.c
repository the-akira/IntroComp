#include <stdio.h>
#include <string.h>

// Programa em C que:
// Imprime todas as permutações de uma string

// Função que troca o valor de dois ponteiros
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Função permute: Executa a permutação
// Recebe uma string, o índice inicial e o índice final da string
void permute(char *str, int low, int high)
{
    int i;
    if(low == high)
        printf("%s\n",str);
    else
    {
        for(i=low;i<=high;i++)
        {
            swap((str + low),(str + i));
            permute(str,low+1,high);
            swap((str + low),(str + i)); // backtrack
        }
    }
}

int main()
{
    char string[] = "GABR";
    int len = strlen(string);
    permute(string, 0, len-1);
}