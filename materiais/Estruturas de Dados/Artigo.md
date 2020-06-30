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