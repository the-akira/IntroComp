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
- Heap
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

- **Push**: Insere um elemento no topo da stack
- **Pop**: Retorna o elemento do topo depois de removê-lo da stack
- **isEmpty**: Retorna `True` se a stack estiver vazia
- **Peek**: Retorna o elemento do topo da stack sem removê-lo

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