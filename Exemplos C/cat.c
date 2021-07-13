#include <stdio.h>
#include <stdlib.h>

// cat: programa clássico que concatena arquivos
int main(int argc, char *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0];

    if(argc == 1)
        filecopy(stdin, stdout);
    else
        while(--argc > 0)
            if((fp = fopen(*++argv, "r")) == NULL){
                fprintf(stderr, "%s: não é possível abrir %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                printf("\n");
                fclose(fp);
            }
    if(ferror(stdout)){
        fprintf(stderr, "%s: erro ao escrever stdout\n", prog);
        exit(2);
    }
    exit(0);
}

// filecopy: copia o arquivo ifp para o arquivo ofp
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while((c = getc(ifp)) != EOF)
        putc(c, ofp);
}