# Algoritmos de Busca e Ordenação

## Algoritmos de Busca

Na ciência da computação, um algoritmo de busca é qualquer algoritmo que resolva o [problema de busca](https://en.wikipedia.org/wiki/Search_problem), ou seja, para recuperar informações armazenadas em alguma estrutura de dados ou calculadas no [espaço de busca](https://en.wikipedia.org/wiki/Feasible_region) de um domínio do problema, com [valores discretos ou contínuos](https://en.wikipedia.org/wiki/Continuous_or_discrete_variable). 

Aplicações específicas dos algoritmos de busca incluem:

- Problemas na [otimização combinatória](https://en.wikipedia.org/wiki/Combinatorial_optimization), como:
	- O [problema de roteamento do veículo](https://en.wikipedia.org/wiki/Vehicle_routing_problem), uma forma de [problema de caminho mais curto](https://en.wikipedia.org/wiki/Shortest_path_problem).
	- O [problema da mochila](https://en.wikipedia.org/wiki/Knapsack_problem): Dado um conjunto de itens, cada um com um peso e um valor, determine o número de cada item a ser incluído em uma coleção, para que o peso total seja menor ou igual a um determinado limite e o valor total seja o máximo possível.
	- O problema de [agendamento da enfermeira](https://en.wikipedia.org/wiki/Nurse_scheduling_problem).
- Problemas na [satisfação de restrições](https://en.wikipedia.org/wiki/Constraint_satisfaction), como:
	- O [problema de coloração de mapas](https://en.wikipedia.org/wiki/Map_coloring_problem).
	- Preenchimento de um [sudoku](https://en.wikipedia.org/wiki/Sudoku) ou [palavras cruzadas](https://en.wikipedia.org/wiki/Crossword_puzzle).
- Na [teoria dos jogos](https://en.wikipedia.org/wiki/Game_theory) e, especialmente, na [teoria combinatória dos jogos](https://en.wikipedia.org/wiki/Combinatorial_game_theory), escolher a melhor jogada a seguir (como no algoritmo [minmax](https://en.wikipedia.org/wiki/Minmax)).
- Fatorar um número inteiro (um problema importante em criptografia).
- Otimizar um processo industrial, como uma reação química, alterando os parâmetros do processo (como temperatura, pressão e pH).
- Recuperando um Registro de um Banco de Dados.
- Localizando o valor máximo ou mínimo em uma lista ou array.
- Verificando se um determinado valor está presente em um conjunto de valores.

Resumidamente, um algoritmo de busca é uma maneira de encontrar um item ou um grupo de itens de uma coleção, essa coleção pode ser implícita ou explícita.

**Implícita**: Um algoritmo que encontra a raíz quadrada através de enumeração exaustiva, ou seja, considera todas as possibilidades.
**Explícita**: Por exemplo, considerando que temos dados de registros de estudantes e queremos encontrar um estudante específico para alterar sua nota.

Neste artigo veremos especificamente os algoritmos de busca explícita: Linear Search & Binary Search.

## Linear Search & Binary Search

- Linear Search (Lista não precisa estar ordenada) - Complexidade: `O(n)`

![img](https://i.ibb.co/rGBV0LZ/Linear-Search.png)

```python
def linear_search(L,e):
	found = False
	for i in range(len(L)):
		if e == L[i]:
			found = True
	return found

L = [4,2,3,1,5]
print(linear_search(L,5)) # True
print(linear_search(L,6)) # False
```

- Binary Search (Lista precisa estar ordenada) - Complexidade: `O(log n)`

![img](https://i.ibb.co/2tk7SSq/Binary-Search.png)

```python
def binary_search(L,e):
	def binary_search_helper(L,e,low,high):
		if high == low:
			return L[low] == e
		mid = (low + high)//2
		if L[mid] == e:
			return True
		elif L[mid] > e:
			if low == mid:
				return False
			else:
				return binary_search_helper(L,e,low,mid-1)
		else:
			return binary_search_helper(L,e,mid+1,high)
	if len(L) == 0:
		return False
	else:
		return binary_search_helper(L,e,0,len(L)-1)

L = [1,2,3,4,5,6,7,8,9,10]
print(binary_search(L,6)) # True
print(binary_search(L,11)) # False
```

## Custo Amortizado

Na ciência da computação, a análise amortizada é um método para analisar a complexidade de um determinado algoritmo, ou quanto de um recurso (especialmente tempo ou memória) é necessário para executá-lo. A motivação para a análise amortizada é que observar o pior tempo de execução por operação, e não por algoritmo, pode ser muito pessimista.

Embora certas operações para um determinado algoritmo possam ter um custo significativo em recursos, outras operações podem não ser tão caras. A análise amortizada considera as operações custosas e menos custosas juntas em toda a série de operações do algoritmo. Isso pode incluir a contabilização de diferentes tipos de entrada, comprimento da entrada e outros fatores que afetam seu desempenho.

Considerando que é necessário ordenarmos uma lista `L` para podermos executar o algoritmo Binary Search:

É válido em termos de desempenho ordenar a lista e depois fazer buscas?

- Em alguns casos, vamos ordenar ela apenas uma vez e executar diversas buscas
- Custo da ordenação é AMORTIZADO sob muitas buscas

`SORT + K * O(log n) < K * O(n)`

- Para valores grandes de **K**, o tempo de ordenação se torna irrelevante, caso o custo de ordenação seja baixo.

A questão é: Como ordenar de maneira eficiente?

## Algoritmos de Ordenação

Na ciência da computação, um algoritmo de ordenação é um algoritmo que coloca os elementos de uma lista em uma determinada ordem. As ordens mais usadas são ordem numérica e ordem lexicográfica. A ordenação eficiente é importante para otimizar a eficiência de outros algoritmos (como algoritmos de busca e união) que exigem que os dados de entrada estejam em listas ordenadas. A ordenação também é frequentemente útil para canonizar dados e para produzir resultados legíveis por humanos. Mais formalmente, o *output* de qualquer algoritmo de ordenação deve atender a duas condições:

1. O *output* deve estar em ordem não decrescente (cada elemento não é menor que o elemento anterior, de acordo com a ordem total desejada).
2. O *output* é uma permutação (uma reordenação, mas mantendo todos os elementos originais) do *input*.

### Breve Histórico

Desde o início da computação, o problema de ordenação atraiu muita pesquisa, talvez devido à complexidade de resolvê-lo com eficiência, apesar de sua declaração simples e familiar. Entre os autores dos primeiros algoritmos de ordenação, por volta de 1951, estava [Betty Holberton](https://en.wikipedia.org/wiki/Betty_Holberton), que trabalhou no [ENIAC](https://en.wikipedia.org/wiki/ENIAC) e no [UNIVAC](https://en.wikipedia.org/wiki/UNIVAC).

Os algoritmos de ordenação são predominantes nas aulas introdutórias de Ciência da Computação, onde a abundância de algoritmos para o problema fornece uma introdução gentil a uma variedade de conceitos básicos de algoritmos, como: 

- [Notação Big O](https://en.wikipedia.org/wiki/Big_O_notation) 
- [Algoritmos de Dividir para Conquistar](https://en.wikipedia.org/wiki/Divide_and_conquer_algorithm)
- [Estruturas de Dados](https://en.wikipedia.org/wiki/Data_structure) como [Heaps](https://en.wikipedia.org/wiki/Heap_(data_structure)) e [Árvores Binárias](https://en.wikipedia.org/wiki/Binary_tree) 
- [Algoritmos Aleatórios](https://en.wikipedia.org/wiki/Randomized_algorithm) 
- Análise de [Casos Melhores, Piores e Médios](https://en.wikipedia.org/wiki/Best,_worst_and_average_case)
- [Tradeoffs entre Espaço e Tempo](https://en.wikipedia.org/wiki/Time%E2%80%93space_tradeoff) 
- [Limites Superior e Inferior](https://en.wikipedia.org/wiki/Upper_and_lower_bounds)

### Classificação

Algoritmos de Ordenação normalmente são classificados por:

- Complexidade computacional (pior, média e melhor comportamento) em termos do tamanho da lista **n**. Para algoritmos típicos de ordenação serial, o bom comportamento é `O(n log n)`, com ordenação paralela em `O(log n)`, e o mau comportamento é `O(n²)`. O comportamento ideal para uma ordenação serial é `O(n)`, mas isso não é possível no caso médio. A ordenação paralela ideal é `O(log n)`. Os algoritmos de ordenação com base em comparação precisam de pelo menos `Ω(n log n)` comparações para a maioria dos *inputs*.
- Complexidade computacional dos swaps(trocas) (para algoritmos "in-place").
- Uso de memória (e uso de outros recursos computacionais). Em particular, alguns algoritmos de ordenação estão "in-place". Estritamente, uma ordenação *in-place* precisa apenas de memória `O(1)` além dos itens que estão sendo ordenados; às vezes, memória adicional `O(log n)` é considerada "in-place".
- Recursão. Alguns algoritmos são recursivos ou não recursivos, enquanto outros podem ser ambos.
- Estabilidade: [algoritmos de ordenação estáveis](https://en.wikipedia.org/wiki/Sorting_algorithm#Stability) mantêm a ordem relativa dos registros com chaves iguais.
- Se eles são ou não de ordenação comparativa. Uma ordenação de comparação examina os dados apenas comparando dois elementos com um operador de comparação.
- Adaptabilidade: Se a pré-classificação da entrada afeta ou não o tempo de execução. Os algoritmos que levam isso em consideração são conhecidos por serem [adaptativos](https://en.wikipedia.org/wiki/Adaptive_sort).

### Bubble Sort

- Comparar pares consecutivos de elementos
- Trocar os elementos em pares de forma que o elemento menor seja primeiro
- Quando alcançar o fim da lista, começar novamente
- Parar quando mais nenhuma troca seja feita
- O maior elemento desordenado termina sempre no fim da lista após a primeira iteração, sendo assim, temos no máximo *n* iterações

```python
def bubble_sort(L):
	swap = False
	while not swap:
		swap = True 
		for j in range(1,len(L)):
			if L[j-1] > L[j]:
				swap = False
				temp = L[j]
				L[j] = L[j-1]
				L[j-1] = temp
	return L 

L = [5,4,3,2,1]
print(bubble_sort(L))
```

- Loop **for** interior é para executar as comparações
- Loop **while** exterior é para executar múltiplas iterações até que não haja mais trocas
- `O(n²)` onde **n** é o tamanho da lista `len(L)`, para executar `len(L) - 1` comparações e `len(L) - 1` iterações

### Selection Sort

Primeiro Passo:

- Extrair o **elemento mínimo**
- **Trocá-lo** com o elemento no **índice 0**

Passos Subsequentes:

- Na sublista remanescente, extrair o elemento mínimo
- Trocá-lo com o elemento no índice 1

Manter a porção esquerda da lista ordenada

- No passo **n**: primeiros **i** elementos na lista estão ordenados
- Todos os outros elementos são maiores do que os primeiros **i** elementos

```python
def selection_sort(L):
	suffix = 0
	while suffix != len(L):
		for i in range(suffix,len(L)):
			if L[i] < L[suffix]:
				L[suffix], L[i] = L[i], L[suffix]
		suffix += 1
	return L 

L = [5,4,3,2,1]
print(selection_sort(L))
```

- Loop exterior executa `len(L)` vezes
- Loop interior executa `len(L) - i` vezes
- Complexidade de Selection Sort é `O(n²)` onde **n** é `len(L)`

### Merge Sort

- Dividir para Conquistar
- Dividimos a lista pela metade até que tenhamos sublistas de 1 elemento
- Unir as sublistas de tal forma que elas estarão ordenadas após a união
- Continuar unindo as sublistas ordenadas até finalmente termos uma lista única ordenada

**Dividir** é fragmentar a lista em fatias menores e **Conquistar** é uní-las 

```python
def merge(left, right):
	result = []
	i, j = 0, 0
	while i < len(left) and j < len(right):
		if left[i] < right[j]:
			result.append(left[i])
			i += 1
		else:
			result.append(right[j])
			j += 1
	while i < len(left):
		result.append(left[i])
		i += 1
	while j < len(right):
		result.append(right[j])
		j += 1
	return result

def merge_sort(L):
	if len(L) < 2:
		return L[:]
	else:
		middle = len(L)//2
		left = merge_sort(L[:middle])
		right = merge_sort(L[middle:])
		return merge(left, right)
	return L 

L = [5,4,3,2,1]
print(merge_sort(L))
```

- Dividir a lista sucessivamente em metades
- Conquistar fazendo a união das listas

Complexidade do algoritmo Merge Sort

No primeiro nível de recursão

- n/2 elementos em cada lista
- `O(n) + O(n) = O(n)` onde **n** é `len(L)`

No segundo nível de recursão

- n/4 elementos em cada lista
- duas uniões -> `O(n)` onde **n** é `len(L)`

Cada nível de recursão é `O(n)` onde **n** é `len(L)`

Dividir a lista pela metade em cada chamada recursiva

- `O(log n)` onde **n** é `len(L)`

Complexidade final é `O(n log n)` onde **n** é `len(L)`

Outros algoritmos de ordenação importantes que podemos considerar: [Insertion Sort](https://akiradev.netlify.app/posts/algoritmo-insertion-sort/), [Heap Sort](https://akiradev.netlify.app/posts/algoritmo-heap-sort/), [Quick Sort](https://akiradev.netlify.app/posts/algoritmo-quick-sort/).

Python também nos oferece um método de ordenação nativo que utiliza o algoritmo [TimSort](https://en.wikipedia.org/wiki/Timsort), muito popular por sua eficiência.

```python
lista = [5,4,3,2,1]
lista.sort()
print(lista) # [1, 2, 3, 4, 5]
```

Para mais detalhes você pode acessar o excelente livro: [Algorithms, 4th Edition](https://algs4.cs.princeton.edu/home/) ou visitar o curso [Algorithms and Data Structures Fall 2007](https://www.cs.princeton.edu/~rs/AlgsDS07/)