#include <stdio.h>

// Contando strings (vogais, consoantes e palavras)

int main()
{
    char str[] = "Qual o seu nome?";
    int i, vcount=0, ccount=0, word=1;

    // Contando vogais
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
         || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            vcount++;
        }
        else if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
        {
            ccount++;
        }
    }
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ' && str[i-1]!=' ')
            word++;
    }
    
    printf("A quantidade de vogais é: %d\n",vcount);
    printf("A consoantes de vogais é: %d\n",ccount);
    printf("O número de palavras é: %d\n",word);
}