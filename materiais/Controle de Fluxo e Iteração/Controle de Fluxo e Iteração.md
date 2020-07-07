# Controle de Fluxo e Iteração

Na ciência da computação, o fluxo de controle é a ordem em que [statements](https://en.wikipedia.org/wiki/Statement_(computer_science)), [instruções](https://en.wikipedia.org/wiki/Instruction_(computer_science)) ou [chamadas de funções](https://en.wikipedia.org/wiki/Function_call) individuais de um programa imperativo são executadas ou avaliadas. A ênfase no fluxo de controle explícito distingue uma linguagem de programação [imperativa](https://en.wikipedia.org/wiki/Imperative_programming) de uma linguagem de programação [declarativa](https://en.wikipedia.org/wiki/Declarative_programming).

Dentro de uma linguagem de programação imperativa, uma declaração de fluxo de controle é uma declaração que resulta na escolha de qual dos dois ou mais caminhos a seguir. Para linguagens funcionais [non-strict](https://en.wikipedia.org/wiki/Strict_programming_language), funções e construções de linguagem existem para alcançar o mesmo resultado, mas geralmente não são denominadas declarações de fluxo de controle.

Um conjunto de instruções, por sua vez, geralmente é estruturado como um [bloco](https://en.wikipedia.org/wiki/Block_(programming)) que, além de agrupar, também define um [escopo léxico](https://en.wikipedia.org/wiki/Lexical_scope).

No nível da linguagem de máquina ou linguagem assembly, as instruções de fluxo de controle geralmente funcionam alterando o contador do programa. Para algumas unidades de processamento central (CPUs), as únicas instruções de fluxo de controle disponíveis são instruções de [ramificação](https://en.wikipedia.org/wiki/Branch_(computer_science)) condicionais ou incondicionais, também denominadas saltos.

## Categorias

Os tipos de instruções de fluxo de controle suportados por linguagens diferentes variam, mas podem ser categorizados por seus efeitos:

- Continuação em uma declaração diferente ([ramificação](https://en.wikipedia.org/wiki/Branch_(computer_science)) ou salto incondicional)
- Executando um conjunto de instruções apenas se uma determinada condição for atendida(escolha - ou seja, [ramificação condicional](https://en.wikipedia.org/wiki/Conditional_branch))
- Executar um conjunto de instruções zero ou mais vezes, até que alguma condição seja atendida (ou seja, loop - o mesmo que [ramificação condicional](https://en.wikipedia.org/wiki/Conditional_branch))
- Executando um conjunto de instruções distantes, após o qual o fluxo de controle geralmente retorna ([sub-rotinas](https://en.wikipedia.org/wiki/Subroutine), [corotinas](https://en.wikipedia.org/wiki/Coroutine) e [continuações](https://en.wikipedia.org/wiki/Continuation))

## Sumarizando

Podemos então considerar que o **fluxo de controle de um programa** é a ordem ao qual o programa é executado. Programadores podem controlar a ordem de execução do seu programa ao utilizarem **estruturas de controle**.

Uma estrutura de controle é um bloco de código que contém instruções e stataments que determinam a ordem de outras instruções e statements.

Programadores usam fluxogramas para representar estruturas de controle de fluxo.

Existem basicamente **três** diferentes **estruturas de controle** que muitas linguagens de programação são capazes de suportar, são elas: **sequência**, **seleção/condição/decisão** e **loops/iterações**.

### Sequência

Uma sequência é uma série de instruções ao qual cada instrução é processada após a anterior ter sido executada.

Fluxograma

![img](https://i.ibb.co/7bhykwq/Sequential.png)

Exemplo de Código em C

```c
#include <stdio.h>

// Exemplo de programa sequencial que soma dois números

int main(void)
{
	int x; 
	float y, z;
	x = 10;
	y = 150.7;
	z = x + y;
	printf("A soma de %d + %f = %f\n",x,y,z);
}
```

Exemplo de Código em Python

```python
# Exemplo de um programa sequencial
x = 10
y = 13
print(x)
print(y)
z = x + y
print(f"{x} + {y} = {z}")
```

### Seleção / Condição / Decisão

Uma Seleção ou Condição ou Decisão é necessária quando uma instrução depende em uma condição ser **Verdadeira/True** ou **Falsa/False** para que possa ser processada.

Fluxograma

![img](https://i.ibb.co/r61FThM/Condicional.png)

Exemplo de Código em C

```c
#include <stdio.h>

// Exemplo de programa que avalia se
// um número digitado é par ou ímpar

int main(void)
{
	int num;
	printf("Digite um número: ");
	scanf("%d",&num);

	if(num % 2 == 0)
		printf("%d é um número par\n",num);
	else
		printf("%d é um número ímpar\n",num);
}
```

Exemplo de Código em Python

```python
# Exemplo de programa com controle de fluxo if...else
num = int(input("Digite um número: "))

if num > 0:
	print(f"{num} é positivo")
elif num == 0:
	print(f"Número é {num}")
else:
	print(f"{num} é negativo")
```

É **importante** lembrarmos que algumas linguagens implementam o [switch statement](https://en.wikipedia.org/wiki/Switch_statement) que é um tipo de mecanismo de controle de seleção usado para permitir que o valor de uma variável ou expressão mude o fluxo de controle da execução do programa por meio de pesquisa e mapa. 

Ele pode ser encontrado em linguagens como: [C](https://en.wikipedia.org/wiki/C_(programming_language))/[C++](https://en.wikipedia.org/wiki/C%2B%2B), [Javascript](https://www.w3schools.com/js/js_switch.asp), [Java](https://www.w3schools.com/java/java_switch.asp), [PHP](https://www.w3schools.com/php/php_switch.asp) e muitas outras.

Fluxograma

![img](https://i.imgur.com/4uzZh01.png)

Exemplo de Código em C

```c
#include <stdio.h>

// Programa que define uma simples calculadora

int main() 
{
    char operador;
    double n1, n2;

    printf("Entre um operador (+, -, *, /): ");
    scanf("%c",&operador);
    printf("Entre dois operandos:\n");
    scanf("%lf %lf",&n1, &n2);

    switch(operador)
    {
        case '+':
            printf("%.1lf + %.1lf = %.1lf\n",n1, n2, n1+n2);
            break;

        case '-':
            printf("%.1lf - %.1lf = %.1lf\n",n1, n2, n1-n2);
            break;

        case '*':
            printf("%.1lf * %.1lf = %.1lf\n",n1, n2, n1*n2);
            break;

        case '/':
            printf("%.1lf / %.1lf = %.1lf\n",n1, n2, n1/n2);
            break;

        default:
            printf("Erro! Operador digitado é incorreto!");
    }
}
```

### Loops / Iteração

Um Loop ou Iteração é necessário quando uma série de instruções precisam ser repetidas até que uma resposta desejada seja obtida. Um conjunto de instruções que é repetidamente executada é conhecido como Loop.

O Loop no diagrama abaixo continuará a ser repetido até que o `False statement` seja atingido.

![img](https://i.ibb.co/0sW17yb/Iteration.png)

Os constructos de Loop mais conhecidos são o [For loop](https://en.wikipedia.org/wiki/For_loop) e o [While loop](https://en.wikipedia.org/wiki/While_loop)

Exemplo de Códigos em C

For Loop:

```c
#include <stdio.h>

// Exemplo de um programa iterativo que itera sob um array

int main(void)
{
	int array[] = {10,20,30,40,50};
	int len = sizeof(array) / sizeof(array[0]);

	for(int i = 0; i < len; i++)
		printf("Valor no índice %d = %d\n",i,array[i]);
}
```

While Loop:

```c
#include <stdio.h>

// Exemplo de programa iterativo que executa
// um bloco de código até o usuário digitar um
// número negativo

int main(void)
{
	int num;
	do
	{
		printf("Digite um número negativo: ");
		scanf("%d",&num);
	}
	while(num >= 0);

	printf("Número digitado = %d\n",num);
}
```

Exemplo de Códigos em Python

For Loop:

```python
# Exemplo de programa com iteração for loop
numeros = list(range(6))

for numero in numeros:
	if numero > 3:
		print(numero)
```

While Loop:

```python
# Exemplo de programa com iteração while loop
num = int(input("Digite um número positivo: "))

while num > 0:
	print(num)
	num -= 1
```

### Vantagens de Utilizar Estruturas de Controle de Fluxo

- Estruturas de controle tornam claro a ordem de execução do programa de maneira transparente
- Utilizando seções menores de código permite que diversos programadores trabalharem em um programa ao mesmo tempo, aumentando assim a produtividade
- Estas estruturas auxiliam os programadores a encontrarem erros antes do programa ser executado
- Ao dividir grandes quantidades de código em seções menores os programadores podem atualizar os programas de forma fácil ao editarem seções individuais de texto
- Estruturas de controle dividem o programa em seções menores e gerenciáveis