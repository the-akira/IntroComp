#include <stdio.h>

// programa que conta linhas, palavras e letras

#define IN 1 /* inside word */
#define OUT 0 /* outside word */

int main(void)
{
	int c, n1, nw, nc, state;

	state = OUT;
	n1 = nw = nc = 0;
	while((c = getchar()) != EOF){
		++nc;
		if(c == '\n')
			++n1;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if(state == OUT){
			state = IN;
			++nw;
		}
	}
	printf("Linhas: %d Palavras: %d Letras: %d\n", n1, nw, nc);
}