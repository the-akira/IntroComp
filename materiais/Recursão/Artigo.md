# Recursão

<h1 align="center">
    <img alt="Recursion" src="https://i.ibb.co/ky1Wj9Y/mise.jpg">
</h1>

<figure>
    <blockquote>
        <p>Na história da arte ocidental, Mise en abyme é uma técnica formal de colocar uma cópia de uma imagem dentro de si mesma, geralmente de uma maneira que sugere uma sequência infinitamente recorrente.</p>
    </blockquote>
</figure>

Na ciência da computação, a **recursão** é um método de resolver um problema em que a solução depende de soluções para instâncias menores do mesmo problema. Esses problemas geralmente podem ser resolvidos por iteração, mas para isso é necessário identificar e indexar as instâncias menores no momento da programação. Ao contrário, a recursão resolve esses problemas recursivos usando funções que chamam a si mesmas de dentro de seu próprio código. A abordagem pode ser aplicada a muitos tipos de problemas, e a recursão é uma das idéias centrais da ciência da computação.

<figure>
    <blockquote>
        <p>"O poder da recursão está evidente na possibilidade de definir um conjunto infinito de objetos por uma declaração finita. Da mesma maneira, um número infinito de cálculos pode ser descrito por um programa recursivo finito, mesmo que esse programa não contenha repetições explícitas."</p>
        <footer>
            <cite>— Niklaus Wirth, Algorithms + Data Structures = Programs, 1976</cite>
        </footer>
    </blockquote>
</figure>

A maioria das linguagens de programação de computador oferece suporte à recursão, permitindo que uma função se chame de dentro de seu próprio código. Algumas linguagens de programação funcionais não definem nenhuma construção de loop, mas dependem apenas da recursão para chamar o código repetidamente. Está provado na teoria da computabilidade que essas linguagens apenas recursivas são *Turing complete*; isso significa que eles são tão poderosos (podem ser usados para resolver os mesmos problemas) quanto linguagens imperativas baseadas em estruturas de controle, como **while** e **for**.

A chamada repetida de uma função a partir de si mesma pode fazer com que a [Stack de chamadas](https://en.wikipedia.org/wiki/Call_stack) tenha um tamanho igual à soma dos tamanhos de entrada de todas as chamadas envolvidas. Conclui-se que, para problemas que podem ser resolvidos facilmente por iteração, a recursão geralmente é menos eficiente e, para grandes problemas, é fundamental o uso de técnicas de otimização, como otimização de [tail call](https://en.wikipedia.org/wiki/Tail_call).

A recursão é então um método de solução de problemas que envolve a decomposição de um problema em sub-problemas cada vez menores até chegar a um problema pequeno o suficiente para que possa ser resolvido trivialmente. Normalmente, a recursão envolve uma função que chama a si mesma. Embora possa parecer um pouco superficial, a recursão nos permite escrever soluções elegantes para problemas que, de outra forma, seriam muito difíceis de programar.

"*Imagine uma impressora 3D que pode imprimir impressoras 3D que podem imprimir impressoras 3D*"

Definindo Recursão em termos de **Algoritmos** e **Semântica**:

Algoritmicamente: É uma maneira de desenvolver soluções para problemas através de **divisão e conquista** ou **diminuição e conquista**, em outras palavras, reduzir o problema em versões simples do mesmo problema.

Semanticamente: Uma técnica de programação em que uma função chama a si mesma. É importante ressaltar que em programação o objetivo é que não haja recursão infinita, para isso é necessário definir **1 ou mais base cases** que sejam fáceis de resolver.

## Solução Iterativa

Através do uso de constructos de Looping (**while** e **for** loops) somos capazes de criar algoritmos iterativos.

Nos possibilitando capturar um conjunto de **state variáveis** que podem ser atualizadas em cada iteração através do loop.

Podemos por exemplo implementar uma solução que calcule a soma de uma lista de números como: `[1,2,3,4,5]`

```python
def somalistaiter(lista):
    resultado = 0
    for item in lista:
        resultado += item
    return resultado

lst = [1,2,3,4,5]
print(somalistaiter(lst)) # 15
```

A função **somalistaiter()** usa uma variável acumuladora (**resultado**) para calcular o total de todos os números na lista, iniciando com **0** e adicionando cada número da lista.

Agora imagine que não tenhamos acesso aos constructos **for** ou **while**, como poderíamos computar a soma desses itens da lista?

Se você for um matemático, poderia começar lembrando que a adição é uma função definida para dois parâmetros, um par de números. Para redefinir o problema de adicionar uma lista a adicionar pares de números, poderíamos reescrever a lista como uma expressão totalmente entre parênteses. Essa expressão ficaria assim:

`((((1+2)+3)+4)+5)`

Também podemos colocar parênteses a expressão ao contrário:

`(1+(2+(3+(4+5))))`

Observe que o conjunto mais interno de parênteses, `(4 + 5)`, é um problema que podemos resolver sem um loop ou qualquer constructo especial. De fato, podemos usar a seguinte sequência de simplificações para calcular uma soma final.

```
resultado = (1+(2+(3+(4+5))))
	resultado = (1+(2+(3+9)))
		resultado = (1+(2+12))
			resultado = (1+14)
				resultado = 15
```

## Solução Recursiva

Como podemos capturar essa idéia e transformá-la em um programa Python? Primeiro, vamos reafirmar o problema da soma em termos de listas Python. Podemos dizer que a soma da lista `lista` é a soma do primeiro elemento da lista (`lista[0]`) e a soma dos números no restante da lista (`lista[1:]`). Para indicá-lo de forma funcional:

`somalista(lista) = primeiro(lista) + somalista(resto(lista))`

Nesta equação `primeiro(lista)` retorna o primeiro elemento da lista e `resto(lista)` retorna uma lista com todos os elementos, exceto o primeiro, podemos então expressar com Python da seguinte forma:

```python
def somalista(lista):
    if len(lista) == 1:
        return lista[0]
    else:
        return lista[0] + somalista(lista[1:])

lista = [1,2,3,4,5]
print(somalista(lista)) # 15
```

Existem algumas idéias importantes neste código para analisarmos. Primeiro, na linha 2, estamos verificando se a lista possui um elemento. Essa verificação é crucial e é nossa cláusula de escape da função (*base case*). A soma de uma lista de comprimento 1 é trivial; é apenas o número da lista. Segundo, na linha 5, nossa função se autodenomina! Esta é a razão pela qual chamamos o algoritmo **somalista()** de recursivo. Uma função recursiva é uma função que chama a si mesma.

A **Figura 1** mostra a série de chamadas recursivas necessárias para somar a lista `[1,2,3,4,5]`. Você deve pensar nessa série de chamadas como uma série de simplificações. Cada vez que fazemos uma chamada recursiva, estamos resolvendo um problema menor, até chegarmos ao ponto em que o problema não pode ficar menor.

![img](https://i.ibb.co/qFpSZGN/Recursive-Calls.png)

<figure>
    <blockquote>
        <p>Figura 1: Série de chamadas recursivas para adicionar uma lista de números.</p>
    </blockquote>
</figure>

Quando chegamos ao ponto em que o problema é o mais simples possível, começamos a reunir as soluções de cada um dos pequenos problemas até que o problema inicial seja resolvido. A **Figura 2** mostra as adições que são executadas como **somalista()**, que retrocedem na série de chamadas. Quando a **somalista()** retorna do problema principal, temos a solução para o problema como um todo.

![img](https://i.ibb.co/DwKPQdP/Recursive-Returns.png)

<figure>
    <blockquote>
        <p>Figura 2: Série de retornos recursivos para adicionar uma lista de números.</p>
    </blockquote>
</figure>

## As Três Leis da Recursão

Existem três leis muito importantes que os algoritmos recursivos devem obedecer, são elas:

- Um algoritmo recursivo deve ter um *base case*.
- Um algoritmo recursivo deve alterar seu estado e avançar em direção ao *base case*.
- Um algoritmo recursivo deve se chamar, recursivamente.

Vamos analisar cada uma dessas leis em mais detalhes e ver como ela foi usada no algoritmo de **somalista()**. Primeiro, um *base case* é a condição que permite que o algoritmo pare de se repetir. Um *base case* geralmente é um problema pequeno o suficiente para ser resolvido diretamente. No algoritmo de **somalista()**, o *base case* é uma lista de `length` 1.

Para obedecer à segunda lei, precisamos providenciar uma mudança de estado que mova o algoritmo em direção ao *base case*. Uma mudança de estado significa que alguns dados que o algoritmo está usando são modificados. Geralmente, os dados que representam nosso problema diminuem de alguma forma. No algoritmo **somalista()**, nossa estrutura de dados primária é uma lista; portanto, devemos concentrar nossos esforços de mudança de estado da lista. Como o *base case* é uma lista de tamanho 1, uma progressão natural em direção ao *base case* é encurtar a lista. É exatamente o que acontece na linha 5 de nosso código quando chamamos **somalista()** com uma lista mais curta.

A lei final é que o algoritmo deve se chamar. Essa é a própria definição de recursão. Como vimos antes, as funções são boas porque você pode pegar um grande problema e dividi-lo em problemas menores. Os problemas menores podem ser resolvidos escrevendo uma função para resolver cada problema. Quando falamos de recursão, pode parecer que estamos falando em círculos: Temos um problema para resolver com uma função, mas essa função resolve o problema chamando a si mesma! Mas a lógica não é circular; a lógica da recursão é uma expressão elegante de resolver um problema, dividindo-o em problemas menores e mais fáceis, ou seja, Dividindo para Conquistar!

## Programação Dinâmica

Uma tática comum de programação de computadores que vimos até então é dividir um problema em sub-problemas do mesmo tipo que o original, resolver esses sub-problemas e combinar os resultados. Isso geralmente é chamado de método de dividir e conquistar, quando combinado este método com uma tabela de pesquisa que armazena os resultados da solução de sub-problemas (para evitar resolvê-los repetidamente e incorrer em tempo de computação extra), ela pode ser chamada de [programação dinâmica](https://en.wikipedia.org/wiki/Dynamic_programming) ou [memoization](https://en.wikipedia.org/wiki/Memoization).

Para exemplificarmos essa ideia, vamos então considerar a computação da Sequência de Fibonacci, que é representada por:

`1, 1, 2, 3, 5, 8, 13, 21, 34, 55...`

Como podemos observar, os números de Fibonacci são uma sequência de números em que o número atual é o resultado da soma dos dois números anteriores, por exemplo: `Fibonacci(6)` deve retornar **8**, uma vez que a soma de `5 + 3 = 8`.

Vejamos algumas diferentes possíveis soluções para Fibonacci

1. Utilizando Recursão

```python
def fib(n):
    if n == 1 or n == 2:
        return 1
    else:
        return fib(n-1) + fib(n-2)
```

Observe que esta implementação é concisa e de fácil compreensão, definimos um *base case* quando `n == 1 or n == 2` e executamos chamadas recursivas em `n - 1` & `n - 2`.

O problema com esta solução é que 1 chamada se torna 2 chamadas, 2 chamadas se tornam 4 chamadas, etc, o crescimento é exponencial.

A complexidade temporal é `O(2^n)` e a complexidade espacial também é `O(2^n)` para todas as chamadas de Stack.

2. Utilizando Programação Dinâmica + Memoization

De forma a tornarmos nosso algoritmo mais eficiente, podemos utilizar um mecanismo de cache para guardar os valores que já computamos, sem a necessidade de realizar esses cálculos novamente, economizando assim recursos computacionais.

```python
cache = {}
def fibonacci(n):
    if n in cache:
        return cache[n]
	if n == 1 or n == 2:
        resposta = 1
    elif n > 2:
        resposta = fibonacci(n-1) + fibonacci(n-2)
    cache[n] = resposta
    return resposta

for n in range(1,201):
    print(f"{n} = {fibonacci(n)}")
```

Essa implementação utiliza um dicionário `cache` para guardar os valores já computados, isso fará com que as chamadas de Stack sejam drasticamente reduzidas e as computação duplicadas eliminadas, como podemos ver na seguinte figura ilustrativa:

![img](https://i.ibb.co/MS3cn6S/Fibonacci.png)

Com essa estratégia conseguimos melhorar a complexidade temporal e espacial de nosso algoritmo para `O(n)`

3. Utilizando Iteração

Esta implementação se chamada **Bottom Up**, pois construímos as soluções de baixo para cima através de sucessivas iterações.

```python
def fib_bottom_up(n):
    if n == 1 or n == 2:
        return 1
    bottom_up = [None] * (n+1)
    bottom_up[1] = 1
    bottom_up[2] = 1
    for i in range(3,n+1):
        bottom_up[i] = bottom_up[i-1] + bottom_up[i-2]
    return bottom_up[n]

for n in range(1,201):
    print(f"{n} = {fib_bottom_up(n)}")
```

Observe que estamos utilizando uma lista chamada **bottom_up** para armazenar as soluções.

Esta implementação é muito eficiente, pois não há nenhuma chamada recursiva na Stack de chamadas.

## Visualizando Recursão (Árvore Fractal)

Uma Árvore Fractal é conhecida como uma árvore que pode ser criada por ramificação recursivamente simétrica.

A ideia básica para construirmos ela é a seguinte:

1. Desenhamos o tronco
2. No final do tronco, dividimos ele por um ângulo e desenhamos dois galhos
3. Repetimos até o fim de cada galho até que um nível suficiente de ramificações seja atingido

A imagem seguinte apresenta uma árvore com 8 níveis de ramificações

![img](https://i.ibb.co/M99yLZx/fractaltree.png)

A seguir temos o código responsável por desenhar a árvore, observe que estamos utilizando o módulo [turtle](https://docs.python.org/3/library/turtle.html) para nos auxiliar na tarefa de desenhos.

```python
import turtle

WIDTH = 11
BRANCH_LENGTH = 145
ROTATION_LENGTH = 26

class FractalTree(turtle.Turtle):
    def __init__(self, level):
        super(FractalTree, self).__init__()
        self.level = level
        self.hideturtle()
        self.speed('fastest')
        self.color('#3d2506')
        self.left(90)
        self.width(WIDTH)
        self.penup()
        self.back(BRANCH_LENGTH * 1.5)
        self.pendown()
        self.forward(BRANCH_LENGTH)
        self.draw_tree(BRANCH_LENGTH, level)

    def draw_tree(self, branch_length, level):
        self.color('green')
        width = self.width()
        self.width(width * 3.0 / 3.6)
        branch_length *= 3.0 / 3.6
        self.left(ROTATION_LENGTH)
        self.forward(branch_length)

        if level > 0:
            self.draw_tree(branch_length, level - 1)
        self.back(branch_length)
        self.right(2 * ROTATION_LENGTH)
        self.forward(branch_length)

        if level > 0:
            self.draw_tree(branch_length, level - 1)
        self.back(branch_length)
        self.left(ROTATION_LENGTH)

        self.width(width)

if __name__ == '__main__':
    tree_level = 8
    tree = FractalTree(tree_level)
    turtle.done()
```

O parâmetro `WIDTH` define a largura da árvore, `BRANCH_LENGTH` define o comprimento de cada galho, `ROTATION_LENGTH` define o comprimento da rotação e `tree_level` define os níveis de ramificações da árvore, através da alteração desses parâmetros podemos definir infinitas diferentes árvores fractais.

## Aplicações de Recursão

Como podemos ver neste artigo, a técnica de Recursão pode ser utilizada para resolver diversos problemas.

- Solução de problemas envolvendo Arrays e Linked Lists
- Solução de problemas envolvendo Trees
- Solução de problemas envolvendo Graphs
- Solução de problemas através de Dividir para Conquistar
- Solução de problemas através de Programação Dinâmica
- Solução de problemas através de buscas exaustivas
- Desenvolver algoritmos de aproximação