# Estruturas de Dados

Na ciência da computação, uma **estrutura de dados** é um formato de organização, gerenciamento e armazenamento de dados que permite acesso e modificação eficientes. Mais precisamente, uma estrutura de dados é uma coleção de valores de dados, os relacionamentos entre eles e as funções ou operações que podem ser aplicadas aos dados.

Niklaus Wirth, um cientista da computação suíço, escreveu um livro em 1976 intitulado **Algoritmos + Estruturas de Dados = Programas**, o que nos leva ao entendimento da importância do conhecimento dessas estruturas para a construção de Programas eficientes.

Simplificando, uma estrutura de dados é um contêiner que armazena dados em um layout específico. Esse "layout" permite que uma estrutura de dados seja eficiente em algumas operações e ineficiente em outras. Nosso objetivo é entender as estruturas de dados para que possamos escolher a melhor estrutura de dados para a resolução de um determinado problema.

## Por que precisamos das Estruturas de Dados?

Como as estruturas de dados são usadas para armazenar dados de forma organizada, e como os dados são a entidade mais crucial na ciência da computação, o valor real das estruturas de dados é claro.

Independentemente de qual problema você esteja resolvendo, de uma forma ou de outra, você precisará lidar com dados - seja o nome e nascimento de um trabalhador, preços de ações, uma lista de jogos de vídeo-game ou até mesmo uma lista de filmes simples.

Com base em diferentes cenários, os dados precisam ser armazenados em um formato específico. Temos várias estruturas de dados que cobrem nossa necessidade de armazenar dados em diferentes formatos, para este artigo iremos considerar as mais comuns.

## Estruturas de Dados Comumente Usadas

- Arrays
- Stacks
- Queues
- Linked Lists
- Trees
- Heaps
- Graphs
- Hash Tables

### Array

O array, é uma estrutura de dados que consiste em uma coleção de elementos (valores ou variáveis), cada um identificado por pelo menos um índice ou chave de array. Um array é armazenado de modo que a posição de cada elemento possa ser calculada a partir de sua tupla de índice por uma fórmula matemática. O tipo mais simples de estrutura de dados é um array linear, também chamada de array unidimensional.

Um array é uma estrutura de tamanho fixo, que pode conter itens do mesmo tipo de dados. Pode ser um array de números inteiros, um array de números de ponto flutuante, um array de seqüências de caracteres ou mesmo um array de arrays (como arrays bidimensionais). Os arrays são indexados, o que significa que o acesso aleatório é possível.

![img](https://i.ibb.co/rtGmNnK/Array.png)

Na imagem acima temos um array de tamanho 7, contendo os elementos {22,33,7,88,1,4,13}, com os respectivos índices [0,1,2,3,4,5,6].

Cada elemento de dados recebe um valor numérico positivo chamado Índice, que corresponde à posição desse item no array. A maioria dos idiomas define o índice inicial do array como 0.

#### Operações em Arrays

Consideramos algumas operações essenciais dos arrays:

- **Traverse**: Percorra os elementos e imprima-os.
- **Inserção & Remoção**: A inserção de elementos em um array e a remoção de elementos de um array não podem ser feitos imediatamente, pois os arrays têm tamanho fixo. Se você deseja inserir um elemento em um array, primeiro será necessário criar um novo array com tamanho aumentado (tamanho atual + 1), copiar os elementos existentes e adicionar o novo elemento. O mesmo vale para a exclusão com um novo array de tamanho reduzido.
- **Busca**: Procure um elemento no array. Você pode pesquisar o elemento por seu valor ou índice.
- **Tamanho**: Obtém o número total de elementos em um array.
- **Atualização**: Atualize o valor de um elemento existente em um determinado índice.

#### Aplicações de Arrays

- Usado como blocos de construção para criar outras estruturas de dados, como listas de arrays, heaps, hash tables, vetores e matrizes.
- Usado para diferentes algoritmos de ordenação como Insertion Sort, Quick Sort, Bubble Sort e Merge Sort.

#### Exemplos de Arrays em C

No exemplo a seguir inicializaremos os arrays:

- **A**: Com capacidade de 5 elementos.
- **B**: Com capacidade de 5 elementos, inicializado com os elementos {1,2,3,4,5}
- **C**: Com capacidade de 10 elementos, inicializado com os elementos {2,8,10}
- **D**: Com capacidade de 7 elementos, todos inicializados com 0
- **E**: Com capacidade não informada, inicializado com os elementos {1,3,5,7,9,11}

Todos eles serão alocados em [Stack](https://gribblelab.org/CBootCamp/7_Memory_Stack_vs_Heap.html) da Memória.

```c
#include <stdio.h>

int main()
{
	// Criando arrays em Stack
	int A[5];
	int B[5]={1,2,3,4,5};
	int C[10]={2,8,10};
	int D[7]={0};
	int E[]={1,3,5,7,9,11};	
}
```

Dentro da função **main()**, vamos agora imprimir os elementos dos arrays. Especificamente do array **E** iremos imprimir o endereço em memória do elemento, o elemento respectivo e o seu tamanho em bytes:

```c
	printf("%d\n",A[1]);
	printf("%d\n",B[0]);
	printf("%d\n",C[2]);
	printf("%d\n",D[4]);

	printf("---\n");

	for(int i=0; i<5; i++)
	{
		printf("Endereço=%p\n",&E[i]);
		printf("Valor=%d\n",E[i]);
		printf("Tamanho em bytes=%lu\n",sizeof(E[i]));
	}	
```

**Importante**: Veja que ao imprimirmos o segundo elemento do array **A**, nos será trazido um valor "estranho", isso porque não há nenhum valor atribuído a este Array, logo será impresso o que chamamos de [garbage value](https://www.quora.com/What-do-you-mean-by-a-garbage-value-in-a-variable)

Vejamos agora um exemplo de como podemos alocar um array em [Heap](https://gribblelab.org/CBootCamp/7_Memory_Stack_vs_Heap.html), para isso contaremos com a biblioteca **stdlib** e a função **malloc()**:

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// Criando um array em Heap
	int *p;
	p = (int *)malloc(2*sizeof(int));
	p[0]=13;
	p[1]=17;
	for(int i=0; i<2; i++)
		printf("%d\n",p[i]);
	free(p);
}
```

Declaramos um ponteiro `*p` e utilizamos a função **malloc()** e multiplicamos por **2** a função **sizeof()** passando um **int** como argumento, nos fornecendo assim a capacidade de dois elementos. Essa é uma maneira de alocação dinâmica em memória.

Enfim declaramos o primeiro elemento do array como **13** e o segundo como **17** e posteriormente usamos um **for loop** para imprimirmos os valores no console.

Finalmente usamos a função **free()** para desalocar memória, isso é importante pois evita problemas de vazamento de memória([memory leak](https://en.wikipedia.org/wiki/Memory_leak)).

Caso tenha dúvida de como compilar os programas, confira este [Link](https://github.com/the-akira/IntroComp/blob/master/Exemplos%20C/Compilar.md).

### Stack

Uma stack é um contêiner de objetos que são inseridos e removidos de acordo com o princípio **LIFO**(*last in in first-out*). As principais operações de uma stack são respectivamente **push** e **pop**. 

Uma stack é uma estrutura de dados de acesso limitado - os elementos podem ser adicionados e removidos da stack apenas na parte **superior**, **push** adiciona um item ao topo da stack, **pop** remove o item do topo. 

Uma analogia útil é pensar em uma pilha de livros; você pode remover apenas o livro superior e também adicionar um novo livro na parte superior.

![img](https://i.ibb.co/2gVKvYx/Stack.png)

A imagem acima nos apresenta uma Stack em 4 situações diferentes:

1. Ela está vazia, sem nenhum elemento
2. Executamos a função push() e adicionamos o elemento 1 no topo
3. Executamos a função push() e adicionamos o elemento 2 no topo
4. Executamos a função pop() e removemos o elemento 2 do topo

#### Operações em Stacks

Algumas operações básicas das stacks são:

- **Push**: Insere um elemento no topo da stack.
- **Pop**: Retorna o elemento do topo depois de removê-lo da stack.
- **isEmpty**: Retorna `True` se a stack estiver vazia.
- **Peek**: Retorna o elemento do topo da stack sem removê-lo.

#### Aplicações de Stacks

- Usado para implementar chamadas de função na programação de recursão
- Verificar parênteses balanceados em uma expressão

#### Exemplo de uma Stack em Python

Vejamos um exemplo de uma simples Stack implementada com a linguagem Python

```python
class Stack:
	def __init__(self):
		self.items = []

	def is_empty(self):
		return self.items == []

	def push(self, item):
		self.items.append(item)

	def pop(self):
		return self.items.pop()

	def peek(self):
		return self.items[len(self.items)-1]

	def size(self):
		return len(self.items)

	def clear(self):
		self.items = []

	def display(self):
		for item in self.items:
			print(item)
```

Inicializando a Stack:

```python
s = Stack()
```

Inserindo elementos na Stack:

```python
for item in range(1,8):
	s.push(item)
```

Executando operações de Remoção, Verificando o Tamanho, Verificando se ela está Vazia, Verificando o elemento do Topo e apresentando todos os elementos:

```python
print(f"Elemento removido da Stack: {s.pop()}")
print(f"Elemento removido da Stack: {s.pop()}")
print(f"Tamanho da Stack: {s.size()}")
print(f"Stack está vazia: {s.is_empty()}")
print(f"Elemento do topo da Stack: {s.peek()}")
s.display()
```

### Queue

Uma Queue é um contêiner de objetos (uma coleção linear) que são inseridos e removidos de acordo com o princípio **FIFO**(*first-in first-out*).

![img](https://i.ibb.co/0X9vdXq/FIFO.png)

A figura acima nos apresenta uma Queue em 4 situações diferentes:

1. A Queue está vazia, sem nenhum elemento.
2. Utilizamos a operação enqueue() e inserimos o elemento 1 nela.
3. Usamos a operação enqueue() e inserimos o elemento 2 nela.
4. Executamos a operação dequeue() e removemos o elemento 1 dela.

Um grande exemplo de uma Queue é uma fila de estudantes aguardando para o atendimento de um restaurante universitário.

As operações mais comuns de uma Queue são respectivamente: **enqueue** que significa inserir um item na parte de trás da fila e **dequeue** que significa remover o item da frente da Queue.

![img](https://i.ibb.co/9qcVjqm/Queue.png)

A diferença entre **Stacks** e **Queues** está na remoção. Em uma stack, removemos o item adicionado mais recentemente; em uma queue, removemos o item adicionado menos recentemente.

#### Operações em Queues

As principais operações que podemos executar em uma Queue são:

- **Enqueue**: Insere um elemento no final da Queue
- **Dequeue**: Remove um elemento do começo da Queue
- **isEmpty**: Retorna `True` se a Queue estiver vazia
- **Rear**: Retorna o último elemento da Queue
- **Front**: Retorna o primeiro elemento da Queue

#### Aplicações de Queues

- Utilizadas para gerenciar threads em multithreading.
- Usadas para implementar sistemas de queuing, como por exemplo [priority queues](https://en.wikipedia.org/wiki/Priority_queue)

#### Exemplo de uma Queue em Python

Vejamos um exemplo de uma simples Queue implementada com a linguagem Python

```python
class Queue:
	def __init__(self):
		self.items = []

	def is_empty(self):
		return self.items == []

	def enqueue(self, item):
		self.items.append(item)

	def dequeue(self):
		if len(self.items) < 1:
			return None
		return self.items.pop(0)

	def size(self):
		return len(self.items)

	def front(self):
		return self.items[0]

	def rear(self):
		return self.items[-1]

	def clear(self):
		self.items = []

	def display(self):
		for item in self.items:
			print(item)
```

Inicializando a Queue:

```python
q = Queue()
```

Inserindo elementos na Queue:

```python
for item in range(1,8):
	q.enqueue(item)
```

Realizando operações como Remoção, Verificando o elemento da Frente e o Último, Verificando o Tamanho, Verificando se ela está Vazia e por fim Apresentando todos os elementos presentes nela:

```python
print(f"Elemento removido da fila: {q.dequeue()}")
print(f"Elemento removido da fila: {q.dequeue()}")
print(f"Primeiro elemento da fila: {q.front()}")
print(f"Último elemento da fila: {q.rear()}") 
print(f"Tamanho da fila: {q.size()}")
print(f"Fila está vazia? {q.is_empty()}")
q.display()
```

### Linked Lists

Uma Linked List é uma coleção linear de elementos de dados, cuja ordem não é dada por seu posicionamento físico na memória. Em vez disso, cada elemento aponta para o próximo. É uma estrutura de dados que consiste em uma coleção de *nodes* que juntos representam uma sequência. 

![img](https://i.ibb.co/nRbjdC6/Linked-List.png)

Na sua forma mais básica, cada *node* contém: dados e uma referência (em outras palavras, um link) para o próximo *node* na sequência. Essa estrutura permite a inserção ou remoção eficiente de elementos de qualquer posição na sequência durante a iteração. Variantes mais complexas adicionam links adicionais, permitindo a inserção ou remoção mais eficiente de *nodes* em posições arbitrárias.

Há também um ponteiro de *head*, que aponta para o primeiro elemento da Linked List e, se a lista estiver vazia, simplesmente aponta para *NULL* ou nada.

Sumarizando temos então que:

- Elementos de uma Linked List são conhecidos como **nodes**.
- Cada **node** contém uma **key/data** e um **ponteiro/endereço/link** para o **node** sucessor, conhecido como **next**.
- O atributo de nome **head** é um ponteiro para o primeiro elemento da Linked List.
- O último elemento da Linked List é conhecido como **tail**.

Existem diferentes tipos/variações de Linked Lists:

- **Singly Linked List**: A travessia de itens pode ser feita somente na direção direta.
- **Doubly Linked List**: A travessia de itens pode ser feita nas direções para frente e para trás. Os *nodes* consistem em um ponteiro adicional conhecido como **prev**, apontando para o *node* anterior.
- **Circular Linked List**: Linked Lists em que o ponteiro **prev** da *head* aponta para o *tail*(último elemento) e o próximo ponteiro da *tail* aponta para a *head*, formando assim uma estrutura circular.

#### Operações em Linked Lists

As operações comuns em Linked Lists são:

- **Search**: Encontre o primeiro elemento com uma **key K** na Linked List fornecida por uma busca linear simples e retorne um ponteiro para esse elemento.
- **Insert**: Insere uma **key** na Linked List. Uma inserção pode ser feita de três maneiras diferentes: insira no início da lista, insira no final da lista ou insira no meio da lista.
- **Delete**: Remove um elemento x de uma determinada Linked List. Não é possível excluir um *node* em uma única etapa. Uma exclusão pode ser feita de três maneiras diferentes: exclua do início da lista, exclua do final da lista ou exclua do meio da lista.
- **isEmpty**: Retorna `True` se a Linked List estiver vazia.

#### Aplicações de Linked Lists

- Usado para [gerenciamento de tabela de símbolos](http://jcsites.juniata.edu/faculty/rhodes/lt/sytbmgmt.htm) no design de compiladores.
- Utilizado na alternância de programas usando `Alt + Tab` (implementado usando Circular Linked List).

### Trees

Uma [Tree](https://en.wikipedia.org/wiki/Tree_(data_structure)) é uma estrutura hierárquica ao qual os dados são organizados hierarquicamente e são vinculados. Essa estrutura é diferente de uma Linked List, enquanto que, em uma Linked List, os itens são vinculados em uma ordem linear.

A figura a seguir apresenta uma Tree com as terminologias básicas indicadas:

![img](https://i.ibb.co/8gTDNpj/Tree.png)

Consistindo de vértices(*nodes*) e *edges* que os conectam. As Trees são semelhantes aos grafos, mas o ponto principal que diferencia uma Tree do Grafo é que um ciclo não pode existir em uma Tree.

Vários tipos de Trees foram desenvolvidos ao longo das últimas décadas, para atender a determinadas aplicações e atender a certas restrições. Alguns exemplos são:

- N-ary Tree
- Balanced Tree
- Binary Tree
- Binary Search Tree
- AVL Tree
- Red Black Tree
- 2-3 Tree

Sendo a Binary Tree e Binary Search Tree mais comumente utilizadas.

#### Aplicações de Trees

- **Binary Trees**: Usadas para implementar analisadores de expressão e solucionadores de expressão.
- **Binary Search Tree**: Usada em muitos aplicativos de pesquisa em que os dados estão constantemente entrando e saindo
- **Decision Trees**: Utilizadas para tomadas de decisão em problemas de Machine Learning
- **Abstract Syntax Tree**: Amplamente utilizada em compiladores para representar a estrutura do código do programa.

### Heaps

Um **Heap** é um caso especial de uma árvore binária em que os *parent nodes* são comparados aos *child nodes* com seus valores e são organizados de acordo.

Existem dois tipos de Heaps:

1. **Min Heap**: A *key* do *parent* é menor ou igual à de seus *childs*. Isso é chamado de propriedade min-heap. A *root* conterá o valor mínimo da pilha.

![img](https://i.ibb.co/JRrmNWN/MinHeap.png)

2. **Max Heap**: A *key* do *parent* é maior ou igual à de seus *childs*. Isso é chamado de propriedade max-heap. A *root* conterá o valor máximo da pilha.

![img](https://i.ibb.co/KcPhDQc/MaxHeap.png)

#### Operações em Heaps

As operações mais comuns em Heaps são:

- **find-max** (ou **find-min**): Localiza um item máximo de um heap máximo ou um item mínimo de um heap mínimo, respectivamente (também conhecido como peek).
- **insert**: Adiciona uma nova *key* a heap (também conhecido como push).
- **extract-max** (ou **extract-min**): Retorna o *node* de valor máximo de uma heap máxima [ou valor mínimo de uma heap mínima] após removê-lo da heap (também conhecido como pop).
- **create-heap**: Cria uma heap vazia.
- **heapify**: Crie uma heap a partir de um determinado conjunto de elementos.
- **size**: Retorna o número de itens na pilha.
- **is-empty**: Retorne `False` se a heap estiver vazia; caso contrário, `False`.

#### Aplicações da Heap

- Utilizada no algoritmo **Heap Sort**.
- Usado para implementar filas de prioridade, pois os valores de prioridade podem ser ordenados de acordo com a propriedade heap em que o heap pode ser implementado usando uma array.
- As funções de Queue podem ser implementadas usando Heaps dentro do tempo **O(log n)**.
- Usado para encontrar o valor menor(ou maior) de **kᵗʰ** em uma determinado array.
- Algoritmos de Grafos: Usando heaps como estruturas internas de dados transversais, o tempo de execução será reduzido por ordem polinomial. Exemplos de tais problemas são [o algoritmo de árvore de abrangência mínima de Prim](https://en.wikipedia.org/wiki/Prim%27s_algorithm) e o [algoritmo de caminho mais curto de Dijkstra](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm).

### Graphs

Um **Graph** consiste em um conjunto finito de **vertices** ou **nodes** e um conjunto de **edges** conectando esses **vertices**.

A ordem de um Graph é o número de vertices no graph. O tamanho de um graph é o número de edges no graph.

Diz-se que dois **nodes** são adjacentes se estiverem conectados um ao outro pela mesma edge.

Os dois tipos principais de Graphs são respectivamente **Direcionados** e **Não-Direcionados**.

#### Graphs Direcionados

Diz-se que um graph G é um graph direcionado se todas as suas edges tiverem uma direção indicando qual é o vertice inicial e qual é o vertice final.

![img](https://i.ibb.co/wLYXKtC/Directed-Graph.png)

Denotamos que **(u,v)** é incidente de ou parte de um vertice **u** e é incidente em ou entra em um vertice **v**.

Então de acordo com a imagem temos que:

```
[(0,0),(0,4),(4,2),(2,3),(2,1),(1,0)]
```

**Auto-Loops**: Edges de um vertice para ele mesmo.

#### Graphs Não-Direcionados

Diz-se que um graph G é um graph não-direcionado se todas as suas edges não tiverem direção. Podem ocorrer nos dois sentidos entre os dois vértices.

![img](https://i.ibb.co/XJVbdrM/Graph.png)

Se um vertice não está conectado a nenhum node do graph, ele é dito ser **isolado**.

Em linguagens de programação, graphs podem ser representados normalmente de duas formas: **Adjacency Matrix** e **Adjacency List**.

Algoritmos comuns de deslocamento de graphs são: **Breadth First Search** e **Depth First Search**.

#### Aplicações de Graphs

- Usado para representar redes de mídia social. Cada usuário é um vértice e, quando os usuários se conectam, criam uma edge.
- Usado para representar páginas da web e links pelos mecanismos de pesquisa. As páginas da Internet na Internet são vinculadas entre si por hiperlinks. Cada página é um vértice e o hiperlink entre duas páginas é uma edge. Usado para a rankeamento de páginas por algoritmos do Google.
- Usado para representar locais e rotas no GPS. Locais são vértices e as rotas que conectam locais são edges. Usado para calcular a rota mais curta entre dois locais.

### Hash Table

Na computação, uma **Hash Table**(também conhecida como **Hash Map**) é uma estrutura de dados que implementa um tipo de dados abstratos de array associativo, uma estrutura que pode mapear **chaves** para **valores**. 

Uma **Hash Table** usa uma [função de hash](https://en.wikipedia.org/wiki/Hash_function) para calcular um **índice**, também chamado de **código de hash**, em uma array de *buckets* ou *slots*, a partir dos quais o valor desejado pode ser encontrado. Durante a pesquisa, a chave é "hashed" e o hash resultante indica onde o valor correspondente é armazenado.

![img](https://i.ibb.co/bH1FJ5X/Hash-Table.png)

O **endereçamento direto** usa o mapeamento individual entre os valores e as chaves ao armazenar em uma tabela. No entanto, há um problema com essa abordagem quando há um grande número de pares de valores-chave. A tabela será enorme com tantos registros e poderá ser impraticável ou até impossível de ser armazenada, dada a memória disponível em um computador típico. Para evitar esse problema, usamos tabelas de hash.

#### Desempenho

O desempenho da estrutura de dados de hash depende de três fatores importantes:

1. Função Hash: Uma função especial denominada função de hash(**h**) é usada para superar o problema mencionado no endereçamento direto.

No acesso direto, um valor com a **chave k** é armazenado no **slot k**. Usando a função hash, calculamos o índice da tabela (**slot**) para a qual cada valor vai. O valor calculado usando a função hash para uma determinada chave é chamado de valor hash, que indica o índice da tabela para a qual o valor está mapeado.

```
h(x) = x % m
```

**h**: Função hash, **x**: Chave no qual o valor hash deve ser determinado, **m**: Tamanho da tabela hash(número de slots disponíveis)

2. Tamanho da Hash Table

3. Método de Manuseio de Colisão

Podemos resolver colisões selecionando uma função de hash adequada **h** e usar técnicas como **chaining** e **open addressing**.

Em muitas situações, as Hash Tables acabam sendo, em média, mais eficientes do que as search trees ou qualquer outra estrutura de pesquisa de tabela. Por esse motivo, eles são amplamente utilizados em muitos tipos de software, principalmente para arrays associativos, indexação de bancos de dados, caches e conjuntos.

A principal vantagem das Hash Tables sobre outras estruturas de dados de tabela é a velocidade. Essa vantagem é mais aparente quando o número de entradas é grande. As tabelas de hash são particularmente eficientes quando o número máximo de entradas pode ser previsto com antecedência, para que o bucket array possa ser alocada uma vez com o tamanho ideal e nunca redimensionado.

Se o conjunto de pares de valores-chave for fixo e conhecido com antecedência(portanto, inserções e exclusões não são permitidas), é possível reduzir o custo médio de pesquisa por uma escolha cuidadosa da função hash, tamanho da tabela de bucket e estruturas de dados internas. Em particular, é possível conceber uma função de hash isenta de colisões ou mesmo perfeita. Nesse caso, as chaves não precisam ser armazenadas na tabela.

Muitas linguagens de programação fornecem funcionalidade de tabela de hash, como matrizes associativas internas ou como módulos de biblioteca padrão.

#### Aplicações de Hash Tables

- Usadas para implementar índices de banco de dados.
- Usadas para implementar arrays associativos.
- Usadas para implementar a estrutura de dados "conjunto".