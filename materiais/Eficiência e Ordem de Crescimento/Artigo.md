# Eficiência e Ordem de Crescimento

A eficiência de um algoritmo depende da quantidade de tempo, armazenamento e outros recursos necessários para executar o algoritmo. A eficiência é medida com a ajuda de **notações assintóticas**.

Um algoritmo pode não ter o mesmo desempenho para diferentes tipos de *inputs*. Com o aumento do tamanho do *input*, o desempenho mudará.

O estudo da mudança no desempenho do algoritmo com a mudança na ordem do tamanho do *input* é definido como **análise assintótica**.

## Notações Assintóticas

As Notações assintóticas são as notações matemáticas usadas para descrever o tempo de execução de um algoritmo quando o *input* tende a um valor específico ou um valor limite.

**Por exemplo**: Na ordenação através do algoritmo [Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort), quando o array de *input* já está ordenado, o tempo gasto pelo algoritmo é linear, ou seja, o melhor caso.

Porém, quando o array de *input* está em condição reversa, o algoritmo leva o tempo máximo (quadrático) para ordenar os elementos, ou seja, o pior caso possível.

Quando o array de *input* não está ordenado e nem está na ordem inversa, leva um tempo médio. Essas durações são indicadas usando notações assintóticas.

Existem principalmente três notações assintóticas: **notação Theta**, **notação Omega** e [notação Big-O](https://en.wikipedia.org/wiki/Big_O_notation).

A notação de uso mais comum para medir a eficiência de um algoritmo é a Big O, por este motivo focaremos em estudá-la com maiores detalhes.

### Notação Big O

A **notação Big O** é uma notação matemática que descreve o comportamento limitador de uma função quando o argumento tende a um valor específico ou infinito. Big O é um membro de uma família de notações inventadas por [Paul Bachmann](https://en.wikipedia.org/wiki/Paul_Gustav_Heinrich_Bachmann), [Edmund Landau](https://en.wikipedia.org/wiki/Edmund_Landau), e outros, chamada coletivamente de **notação Bachmann–Landau** ou **notação assintótica**.

Na ciência da computação, a notação Big O é usada para classificar algoritmos de acordo com o crescimento dos requisitos de tempo de execução ou espaço à medida que o tamanho do *input* aumenta.

![img](https://i.ibb.co/ZXMGvVd/big-O.png)

<figure>
    <blockquote>
        <p>Gráficos de funções comumente usadas na análise de algoritmos, mostrando o número de operações N versus tamanho de input n para cada função</p>
    </blockquote>
</figure>

A notação Big O caracteriza funções de acordo com suas taxas de crescimento: funções diferentes com a mesma taxa de crescimento podem ser representadas usando a mesma notação O.

A letra **O** é usada porque a taxa de crescimento de uma função também é chamada de ordem da função. Uma descrição de uma função em termos de notação Big O geralmente fornece apenas um [limite superior](https://en.wikipedia.org/wiki/Upper_bound) na taxa de crescimento da função.

A notação Big O possui duas áreas principais de aplicação:

- Em matemática, é comumente usado para descrever até que ponto uma série finita se aproxima de uma determinada função, especialmente no caso de uma [série de Taylor](https://en.wikipedia.org/wiki/Taylor_series) truncada ou [expansão assintótica](https://en.wikipedia.org/wiki/Asymptotic_expansion).
- Em ciência da computação, é útil na [análise de algoritmos](https://en.wikipedia.org/wiki/Big_O_notation#Infinite_asymptotics).

### Questões Importantes

Quão eficiente é meu algoritmo?

Quanto tempo o algoritmo leva para resolver um problema?

Eficiência refere-se à **Espaço** e **Tempo**

Um algoritmo pode ser implementado de diversas maneiras diferentes, como então podemos medir a eficiẽncia de um algoritmo?

**Ordem de Crescimento** ou **Notação Big O** é uma maneira de descrever de forma abstrata o comportamento de um algoritmo e especialmente as equivalências de diferentes algoritmos.

A **Complexidade Temporal** é a complexidade computacional que descreve a quantidade de tempo necessária para executar um algoritmo. Geralmente, a complexidade temporal é estimada contando o número de operações elementares executadas pelo algoritmo, supondo que cada operação elementar leve um tempo fixo para ser executada.

#### Contando Operações

Diz-se que um algoritmo tem um tempo constante quando não depende dos dados de *input* (n). Não importa o tamanho dos dados de *input*, o tempo de execução será sempre o mesmo.

- Assumindo que esses passos levam tempo constante:
	- operações matemáticas
	- comparações
	- atribuições
	- acessar objetos em memória
- Então contamos o número de operações executadas como uma função do tamanho do *input*

A ideia é expressarmos eficiência em termos do tamanho do *input*

*Inputs* diferentes alteram como o programa executa na maioria dos casos

Considere uma função que busca por um elemento em uma lista:

```python
def search_element(lst,e):
	for i in lst:
		if i == e:
			return True
	return False
```

Usualmente quando falamos de Complexidade, focamos no comportamento de pior caso.

#### Melhor, Médio & Pior Caso

Imagine que nos é fornecido uma lista `L` de tamanho `len(L)`

```python
L = [1,2,3,4,5,6]
tamanho = len(L)
print(search_element(L,6)) # True
print(search_element(L,7)) # False
```

- Melhor caso: Menor tempo de execução sob todos os possíveis inputs de um determinado tamanho, `len(L)`
	- constante para `search_element`
	- primeiro elemento da lista

- Médio caso: Médio tempo de execução sob todos os possíveis inputs de um determinado tamanho, `len(L)`

- Pior caso: Máximo tempo de execução sob todos os possíveis inputs de um determinado tamanho, `len(L)`
	- linear no tamanho da lista para `search_element`
	- deve-se buscar a lista inteira e não encontrar o elemento

Vamos agora considerar uma função que computa fatoriais:

```python
def fatorial_iter(n):
	resposta = 1
	while n > 1:
		resposta *= n 
		n -= 1
	return resposta
```

- Função que computa fatorial iterativamente
- Pior caso de complexidade assintótico: O(n)
	- Ignorar constantes aditivas
	- Ignorar constantes multiplicativas

#### Exemplos de Simplificações

- Ignorar fatores constantes e multiplicativos
- Focar nos termos dominantes

```
n² + 2n + 2 = O(n²)
n² + 100000n + 3^1000 = O(n²)
log(n) + n + 4 = O(n)
0.0001 * n * log(n) + 300n = O(nlogn)
2n^30 + 3^n = O(3^n)
```

#### Analisando Programas e sua Complexidade

Combinar classes de complexidade

- Analisar os *statements* dentro das funções
- Aplicar regras, focar nos termos dominantes

##### Lei da Adição para O()

- Utilizar com *statements* sequenciais
- `O(f(n)) + O(g(n)) é O(f(n) + g(n))`

Por exemplo:

```python
for i in range(n):
	print('a')

for j in range(n*n):
	print('b')
```

É `O(n) + O(n*n) = O(n+n²) = O(n²)` por causa do termo dominante

##### Lei da Multiplicação para O()

- Usado para *statements*/loops aninhados
- `O(f(n)) * O(g(n)) é O(f(n) * g(n))`

Por exemplo:

```python
for i in range(n):
	for j in range(n):
		print('a')
```

É `O(n) * O(n) = O(n*n) = O(n²)` por causa do loop exterior executa **n** vezes o loop interior executa **n** vezes para cada iteração do loop exterior

#### Classes de Complexidade

- `O(1)`: denota tempo de execução constante
- `O(log n)`: denota tempo de execução logarítmico
- `O(n)`: denota tempo de execução linear
- `O(nlogn)`: denota tempo de execução log-linear
- `O(n^c)`: denota tempo de execução polinomial (c é uma constante)
- `O(c^n)`: denota tempo de execução exponencial (c é uma constante elevada à potência baseado no tamanho do input)

---------------------------------------

- `O(1)` - Código não depende no tamanho do problema
- `O(log n)` - Reduz o problema pela metade cada vez pelo processo
- `O(n)` - Programas iterativos simples ou recursivos
- `O(nlog n)` - Algoritmos específicos como Merge Sort
- `O(n^c)` - Loops aninhados ou chamadas recursivas
- `O(c^n)` - Múltiplas chamadas recursivas em cada nível

##### Complexidade Constante

- Complexidade é independente do *input*
- Poucos algoritmos interessantes nessa classe, porém normalmente existem partes que pertencem a esta classe
- É possível ter loops ou chamadas recursivas, mas apenas se o número de iterações ou chamadas for independente do tamanho do *input*

##### Complexidade Logarítmica

- Complexidade cresce como log do tamanho de um dos *inputs*
- Exemplos: Bisection Search, Binary Search de uma lista

##### Complexidade Linear

- Buscar em uma lista em sequência para checar se um elemento está presente
- Loops Iterativos

##### Complexidade Log-Linear

- Muitos algoritmos práticos são Log-Linear
- Um algoritmo muito comum e utilizado é o Merge Sort

##### Complexidade Polinomial

- Os algoritmo polinomiais mais comuns são quadráticos, em outras palavras, a complexidade cresce com o tamanho do *input* ao quadrado
- É muito comum ocorrer quando temos loops aninhados ou chamadas recursivas de funções

##### Complexidade Exponencial

- Funções recursivas em que ocorre mais de uma chamada recursiva para cada tamanho do problema
- Exemplo: Torre de Hanoi

#### Sumário Big O

Ideias centrais

- Comparar a Eficiência de Algoritmos
	- Notação que descreve crescimento
	- Baixa ordem de crescimento é melhor!
	- Independente de máquina ou implementação específica

- Uso de Big O
	- Descrever ordem de crescimento
	- Notação assintótica
	- Análise do pior caso

Complexidade das Funções Python mais comuns

Listas: `n` é `len(L)`

- index - `O(1)`
- length - `O(1)`
- append - `O(1)`
- == - `O(n)`
- remove - `O(n)`
- copy - `O(n)`
- reverse - `O(n)`
- iteration - `O(n)`
- in L - `O(n)`

Dicionários: `n` é `len(D)`

- index - `O(n)`
- length - `O(n)`
- delete - `O(n)`
- iteration - `O(n)`

##### Exemplos Python

Definimos uma lista para utilizarmos em nossas funções

```python
lst = [1,2,3,4,5]
```

**O(1)**:

```python
def print_element(lista):
	print(lista[0])

print_element(lst)
```

**O(n)**:

```python
def print_elements(lista):
	for item in lista:
		print(item)

print_elements(lst)
```

**O(n²)**:

```python
def print_ordered_pairs(lista):
	for i in lista:
		for j in lista:
			print(i,j)

print_ordered_pairs(lst)
```

**O(2^n)**:

```python
def fibonacci(n):
	if n <= 1:
		return n
	return fibonacci(n-2) + fibonacci(n-1)

print(fibonacci(7))
```

Eliminando constantes **O(2n) = O(n)**:

```python
def print_elements_twice(lista):
	for i in lista:
		print(i)
	for j in lista:
		print(j)

print_elements_twice(lst)
```

Para mais detalhes consulte: [Big O Cheat Sheet](https://www.bigocheatsheet.com/)