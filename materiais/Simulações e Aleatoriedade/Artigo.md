# Simulações e Aleatoriedade

## Problemas de Otimização

Modelos Computacionais: Como podemos utilizar a computação para compreender o mundo no qual vivemos?

O que é um modelo?

É um dispositivo experimental que pode nos ajudar a entender algo que aconteceu de forma a construir um modelo que explica fenômenos que vemos todos os dias ou até mesmo um modelo que nos permita prever o futuro, algo que ainda não ocorreu.

Podemos citar por exemplo um modelo de mudança climática, é possível criar modelos que explicam como o clima mudou ao longo dos milênios e então criar um modelo um pouco diferente que possivelmente possa prever como será o tempo no futuro.

Nesse caso, o que essencialmente está acontecendo é que a ciência está saindo dos laboratórios e movendo-se para os computadores, está ocorrendo um aumento da dependência da computação ao invés de experimentos tradicionais, não que estas deixem de ser importantes, mas hoje há realmente uma necessidade do apoio computacional.

### Modelos de Otimização: 

Um modelo de otimização é muito simples, iniciamos com uma **[função objetiva](https://www.courses.psu.edu/for/for466w_mem14/Ch11/HTML/Sec1/ch11sec1_ObjFn.htm)** que será ou **maximizada** ou **minimizada**. Por exemplo: Se estamos indo de São Paulo para Florianópolis, é possível que queiramos encontrar uma rota de carro ou avião que minimiza o tempo total de viagem, sendo assim, nossa função objetiva seria o número de minutos gastos in trânsito indo de cidade **A** para **B**, nós então temos de incorporar nessa função objetiva um conjunto de restrições que temos de obedecer. Por exemplo: Talvez a forma mais fácil e rápida de ir de São Paulo para Florianópolis seja através de um avião, mas nesse caso temos apenas R$60,00 em disposição, sendo assim, esta opção é descartada, sendo assim, há uma restrição na quantidade de dinheiro que podemos gastar.

Um problema muito famoso de otimização é o [Knapsack problem](https://en.wikipedia.org/wiki/Knapsack_problem)

![img](https://i.ibb.co/5c9sQ1V/knapsack.png)

É um problema que normalmente é explicado em termos de um ladrão que invade uma residência e deseja roubar diversos objetos, mas ele tem apenas uma mochila que pode guardar uma quantidade finita de objetos, sendo assim, esse ladrão tem de resolver um problema de otimização de roubar objetos com o maior valor possível e ao mesmo tempo obedecer a restrição de que todos esses objetos devem caber na mochila.

Nós então temos uma **função objetiva**: tirar o máximo de proveito coletando objetos valiosos e uma **restrição**: os objetos devem caber na mochila.

Formalizando o *Knapsack problem*:

- Cade item é representado por um par: (**value**, **weight**), respectivamente representando seu **valor** e seu **peso**
- A mochila pode acomodar itens com um peso total não maior do que **w**
- Um vetor **I** de comprimento **n** representa o conjunto de itens disponíveis. Cada elemento do vetor é um item.
- Um vetor **V** de comprimento **n** é usado para indicar se os itens foram ou não coletados. Se `V[i] = 1`, o item `I[i]` foi coletado. Se `V[i] = 0`, o item `I[i]`não foi coletado.

Desejamos então buscar um **V** que maximize:

![img](https://i.ibb.co/zsTMCWL/F1.png)

Sujeito à restrição

![img](https://i.ibb.co/d6JJ5yx/F2.png)

A soma dos **weights** não pode ser maior do que **w**.

Uma vez que o problema foi formalizado, surge então a questão: Como resolvê-lo?

Uma opção seria um [Algoritmo de Força Bruta](https://www.freecodecamp.org/news/brute-force-algorithms-explained/):

1. Enumerar todas as possíveis combinações de itens, ou seja, gerar todos os subconjuntos do conjunto de itens. Isso é conhecido como [Power Set](https://en.wikipedia.org/wiki/Power_set)

2. Remover todas as combinações no qual o total de itens excede o peso máximo permitido.

3. Das combinações restantes, escolher aquela que o valor for maior.

Infelizmente essa solução é em muitos casos pouco viável pelo tempo computacional elevado, por exemplo, se houver 100 diferentes itens para o ladrão escolher, o tamanho do **Power Set** será: `1.267.650.600.228.229.401.496.703.205.376` tornando o problema muito difícil de resolver.

O que podemos fazer então? Será que existe um algoritmo melhor que possa solucionar esse problema?

A resposta é **não** para o *Knapsack problem*, e de fato, para muitos problemas de otimização, pois eles são são inerentemente exponenciais, isso significa que não há algoritmo que seja capaz de prover uma solução exata para esse problema no qual o **[Pior Caso](https://en.wikipedia.org/wiki/Worst-case_complexity)** de tempo de execução não seja exponencial em relação ao número de itens. É um problema de **dificuldade exponencial**, não há realmente uma boa e efetiva solução.

Entretanto, mesmo não tem uma perfeita e efetiva solução, existem boas soluções, no qual veremos a seguir, começando pelo [Greedy Algorithm](https://en.wikipedia.org/wiki/Greedy_algorithm).

A ideia do *Greedy Algorithm* em pseudo-código seria:

```
enquanto mochila não está vazia:
	colocar o "melhor" item disponível na mochila
```

Consideramos então a tabela a seguir de itens:

| Item  | Computador  | Tablet  | Relógio  | HD | Pendrive  | Webcam | Mouse  | Teclado  |
|---|---|---|---|---|---|---|---|---|
| Valor  | 1000  | 500  | 300  | 200  | 50  | 60  | 40  | 80  |
| Peso  | 700  | 200  | 50  | 200  | 20  | 30  | 20  | 120  |

Vejamos então um programa que podemos usar para decidir o que coletar.

```python
class Item(object):
	"""
	Define um item com os atributos:
	name/nome = n
	value/valor = v
	weight/peso = w
	"""
	def __init__(self, n, v, w):
		self.name = n
		self.value = v 
		self.weight = w

	def get_value(self):
		return self.value 

	def get_cost(self):
		return self.weight

	def density(self):
		return self.get_value()/self.get_cost()

	def __str__(self):
		return f'{self.name} : ({str(self.value),str(self.weight)})'

def construir_lista(names, values, weights):
	"""
	Constrói uma lista de objetos Item com os atributos (nome, valor, peso)
	"""
	itens = []
	for i in range(len(values)):
		itens.append(Item(names[i],values[i],weights[i]))
	return itens

def greedy(itens, max_cost, key_function):
	"""
	Assume que itens é uma lista e que max_cost >= 0
	key_function mapeia elementos itens para números
	"""
	itens_copy = sorted(itens, key=key_function, reverse=True)
	result = []
	total_value, total_cost = 0.0, 0.0

	for i in range(len(itens_copy)):
		if (total_cost + itens_copy[i].get_cost()) <= max_cost:
			result.append(itens_copy[i])
			total_cost += itens_copy[i].get_cost()
			total_value += itens_copy[i].get_value()

	return (result, total_value)

def test_greedy(itens, constraint, key_function):
	"""
	Função que testa o Greedy Algorithm
	"""
	taken, val = greedy(itens, constraint, key_function)
	print(f'Valor total de itens = {val}')
	for item in taken:
		print(item)

def test_greedys(itens, max_units):
	print(f'Utiliza greedy por valor para alocar {max_units} de peso')
	test_greedy(itens, max_units, Item.get_value)
	print(f'\nUtiliza greedy por peso para alocar {max_units} de peso')
	test_greedy(itens, max_units, lambda x: 1/Item.get_cost(x))
	print(f'\nUtiliza greedy por densidade para alocar {max_units} de peso')
	test_greedy(itens, max_units, Item.density)

nomes = ['computador','tablet','relógio','hd','pendrive','webcam','mouse','teclado']
valores = [1000,500,300,200,50,60,40,80]
pesos = [700,200,50,200,20,30,20,120]
itens = construir_lista(nomes, valores, pesos)
test_greedys(itens,750)
```

Que nos traz os diferentes resultados

```
Utiliza greedy por valor para alocar 750 de peso
Valor total de itens = 1300.0
computador : (('1000', '700'))
relógio : (('300', '50'))

Utiliza greedy por peso para alocar 750 de peso
Valor total de itens = 1230.0
pendrive : (('50', '20'))
mouse : (('40', '20'))
webcam : (('60', '30'))
relógio : (('300', '50'))
teclado : (('80', '120'))
tablet : (('500', '200'))
hd : (('200', '200'))

Utiliza greedy por densidade para alocar 750 de peso
Valor total de itens = 1230.0
relógio : (('300', '50'))
tablet : (('500', '200'))
pendrive : (('50', '20'))
webcam : (('60', '30'))
mouse : (('40', '20'))
hd : (('200', '200'))
teclado : (('80', '120'))
```

Através desse experimento podemos ver um ponto importante em *Greedy Algorithms*, em que usamos o algoritmo e obtivemos diferentes respostas, a questão é, por que temos respostas diferentes?

O problema é que o *Greedy Algorithm* faz uma sequência de otimizações locais, escolhe a **resposta local otimizada** em cada ponto e isso não necessariamente traz uma **resposta global otimizada**

**Prós e Contras de Algoritmos Greedy**

Prós:

- Implementação relativamente simples
- Eficiência computacional

Contras:

- Nem sempre traz a solução mais otimizada
- Muitas vezes nem mesmo temos uma aproximação de quão boa a solução é

**Melhorando a Solução do Knapsack problem através de uma Search Tree**

Uma [Search Tree](https://en.wikipedia.org/wiki/Search_tree) é uma estrutura de dados de árvore usada para localizar chaves específicas de dentro de um conjunto. Para que uma árvore funcione como uma *Search Tree*, a chave para cada nó deve ser maior que qualquer chave nas subárvores à esquerda e menor que qualquer chave nas subárvores à direita.

Definimos então a função **max_val()** que resolverá o problema utilizando uma Search Tree:

```python
def max_val(to_consider, avail):
	"""
	Assume to_consider uma lista de itens, avail um peso
	Retorna uma tupla do valor total de uma solução para
	o problema knapsack e os itens dessa solução
	"""
	if to_consider == [] or avail == 0:
		result = (0,())
	elif to_consider[0].get_cost() > avail:
		# Explora apenas o ramo da direita
		result = max_val(to_consider[1:],avail)
	else:
		next_item = to_consider[0]
		# Explora o ramo da esquerda
		with_val, with_to_take = max_val(to_consider[1:],
										avail - next_item.get_cost())
		with_val += next_item.get_value()
		without_val, without_to_take = max_val(to_consider[1:], avail)
		# Escolhe o melhor ramo
		if with_val > without_val:
			result = (with_val, with_to_take + (next_item,))
		else:
			result = (without_val, without_to_take)
	return result
```

Definimos uma função para testar a função **max_val()**:

```python
def test_max_val(itens, max_units, print_items=True):
	print(f'Usando uma Search Tree para alocar {max_units} de peso')
	val, taken = max_val(itens, max_units)
	print(f'Total de valor de itens coletado = {val}')
	if print_items:
		for item in taken:
			print(item)
```

Finalmente testamos a função:

```python
test_max_val(itens,850)
```

Ela nos trará como resultado apenas a solução mais otimizada:

```
Usando uma Search Tree para alocar 750 de peso
Total de valor de itens coletado = 1300
relógio : (('300', '50'))
computador : (('1000', '700'))
```

Tente experimentar outros valores para verificar as diversas soluções que podemos obter com os diferentes algoritmos.

## Pensamento Estocástico

Por muitos anos as pessoas acreditavam na [Mecânica Newtoniana](https://en.wikipedia.org/wiki/Classical_mechanics) em que:

- Todo efeito tem uma causa
- O mundo pode ser entendido causalmente

![img](https://i.ibb.co/ZfGwFdf/newton.jpg)

"Uma maçã cai de uma árvore por causa da gravidade e podemos saber onde ela irá cair".

Por um longo tempo esse paradigma foi tido como a verdade, até o início do século XX, quando a [Interpretação de Copenhagen](https://en.wikipedia.org/wiki/Copenhagen_interpretation) foi apresentada.

[Niels Bohr](https://en.wikipedia.org/wiki/Niels_Bohr) e [Werner Heisenberg](https://en.wikipedia.org/wiki/Werner_Heisenberg) chamaram de **causal nondeterminism**, em que:

- No seu nível mais fundamental, o comportamento do mundo físico não pode ser previsto.
- É possível fazer afirmações na forma de: "É muito possível que X irá ocorrer", porém não "É certo que X irá ocorrer".

Essa mudança de paradigma trouxe muitos debates e críticas, especialmente de grandes cientistas como [Erwin Schrödinger](https://en.wikipedia.org/wiki/Erwin_Schr%C3%B6dinger) e [Albert Einstein](https://en.wikipedia.org/wiki/Albert_Einstein), que eventualmente culminou com a seguinte famosa frase:

<figure>
    <blockquote>
        <p>"Deus não joga dados."</p>
        <footer>
            <cite>— Albert Einstein</cite>
        </footer>
    </blockquote>
</figure>

### Processos Estocásticos

Em relação à computação, quando pensamos sobre **não-determinismo**, normalmente utilizamos a expressão [Processo Estocástico](https://en.wikipedia.org/wiki/Stochastic_process), que seria qualquer processo em andamento em que o novo estado pode depender dos estados anteriores e **algum elemento aleatório**.

Vejamos por exemplo como podemos implementar Processos Estocásticos em Python.

Primeiramente devemos importar a biblioteca `random`:

```python
import random
```

Gerando 10 números no intervalo [0,1):

```python
for _ in range(10):
	print(random.random())
```

Gerando 10 números no intervalo [3,7):

```python
for _ in range(10):
	print(random.uniform(3,7))
```

Simulando 10 escolhas de Pedra, Papel e Tesoura:

```python
itens = ['pedra','papel','tesoura']
for _ in range(10):
	print(random.choice(itens))
```

Simulando 5 rolagens de um dado de 6 lados:

```python
for _ in range(5):
	print(random.randint(1,6))
```

- Probabilidade é sobre **contar**
- Contamos o número de eventos possíveis
- Contamos o número de eventos que tem a propriedade de nosso interesse
- Dividimos um pelo outro

Nessa simulação dos dados, qual seria a probabilidade de obtermos **11111**

Enumeramos todas as possibilidades: 11111, 11112, 11113, ..., 11121, 11122, ..., 66666

Sendo assim, o número de possibilidades é = `6*6*6*6*6 = 6^5 = 7776`

Só existe um evento que 11111 ocorre, então para calcularmos a probabilidade dividimos `1/7776` que nos resultado **0.0001286**, uma possibilidade muito remota.

**Três Fatos Básicos sobre Probabilidade**

- Probabilidades estão sempre no intervalo de **0 a 1**. 0 se impossível, 1 se garantido.
- Se a probabilidade de um evento ocorrer é **p**, a probabilidade de ele não ocorrer deve ser `1 - p`.
- Quando eventos são **independentes** um do outro, a probabilidade de todos os eventos ocorrerem é igual ao **produto** das probabilidades de cada um dos eventos que ocorrem.

Sendo assim, se a probabilidade de `A = 0.5` e `B = 0.4`, então `A & B = 0.2`, a assim chamada de [Lei Multiplicativa](https://www.statisticshowto.com/multiplication-rule-probability/)

Porém temos que ficar atentos, pois ela é apenas válida se os eventos forem realmente **independentes**:

- Dois eventos são independentes se o resultado de um evento não tiver influência no resultado do outro

Vejamos agora um exemplo em Python de como podemos computar a probabilidade de um vento através de uma simulação, para este exemplo vamos usar a rolagem de dados:

```python
import random

def rolar_dado():
	return random.choice([1,2,3,4,5,6])

def simulacao(objetivo, tentativas, txt):
	total = 0
	for i in range(tentativas):
		resultado = ''
		for j in range(len(objetivo)):
			resultado += str(rolar_dado())
		if resultado == objetivo:
			total += 1
	print(f"Probabilidade real de {txt} = {round(1/(6**len(objetivo)),8)}")
	probabilidade = round(total/tentativas,8)
	print(f"Probabilidade estimada de {txt} = {round(probabilidade,8)}")

simulacao('11111',1000,'11111')	
```

Que nos traz como resultado:

```
Probabilidade real de 11111 = 0.0001286
Probabilidade estimada de 11111 = 0.0
```

Como já sabíamos que esse seria o valor que seria impresso no console?

Temos que lembrar que esses eventos são supostamente [aleatórios](https://en.wikipedia.org/wiki/Randomness).

Porém, é importante entendermos que a função **random.choice()** não é realmente **aleatória**, de fato nada que possamos fazer em um computador é realmente aleatório, o que acontece na verdade é que os computadores geram números chamados de [pseudo-random](https://en.wikipedia.org/wiki/Pseudorandom_number_generator), mas como eles fazem isso?

Existe um algoritmo que dado um determinamo número, ele gera um próximo número em uma sequência, e esse algoritmo é iniciado com uma **[seed](https://en.wikipedia.org/wiki/Random_seed)**, que normalmente é obtida lendo o relógio do computador.

Em Python, caso queíramos repetir um experimento ou debuggar o código, podemos **definir uma seed** ao invés de escolher aleatoriamente, para isso podemos executar o seguinte comando:

```python
random.seed(0)
```

Neste caso específico o número **0** foi escolhido.

Outra questão muito importante é: Por que a simulação nos forneceu uma resposta errada para a probabilidade estimada?

Para isso temos que entender a diferença entre a probabilidade real e o que os estatísticos chamam de [sample probability](https://en.wikipedia.org/wiki/Sampling_probability). Nesse caso, das **1000** tentativas, nenhuma obteve o resultado desejado de `11111`, o que nos resultou a `probabilidade estimada = 0`, sendo assim, para aumentar a confiança de nossa probabilidade estimada, teríamos que aumentar o número de tentativas, quando maior ele for, melhor sera a aproximação.

### Random Walk

Em matemática, uma *random walk*(caminhada aleatória), é um objeto matemático, conhecido como processo estocástico ou aleatório, que descreve um caminho que consiste em uma sucessão de etapas aleatórias em algum espaço matemático, como os números inteiros.

Um exemplo elementar de uma caminhada aleatória é a caminhada aleatória na linha de número inteiro, que começa em 0 e a cada passo move +1 ou -1 com igual probabilidade. Outros exemplos incluem o caminho traçado por uma molécula enquanto viaja em um líquido ou gás, o caminho de busca de um animal e a situação financeira de um apostador: tudo pode ser aproximado por modelos de passeio aleatório, mesmo que na realidade não sejam realmente aleatórios.

Vejamos como podemos fazer uma simulação de um *Random Walk* em Python. Imagine que estamos em nossa casa, localizada na origem (0,0) e vamos nos mover aleatoriamente para o norte, sul, leste ou oeste e veremos o quão longe podemos chegar.

![img](https://i.ibb.co/L6SR5rm/Random-Walk.png)

```python
import random

# Caminhada Aĺeatória
def random_walk(n):
	"""
	Retorna as coordenadas depois de
	caminhar 'n' blocos aleatoriamente
	"""
	x, y = 0, 0
	for _ in range(n):
		step = random.choice(['N','S','L','O'])
		if step == 'N':
			y = y + 1
		elif step == 'S':
			y = y - 1
		elif step == 'L':
			x = x + 1
		else:
			x = x - 1
	return (x, y)

for _ in range(25):
	walk = random_walk(10)
	print(f'{walk} Distância de casa = {abs(walk[0] + abs(walk[1]))} blocos')
```

No meu resultado, com **25** experimentos, caminhando **10** blocos aleatórios, o mais longe que chegamos foram 6 blocos:

```
(0, 2) Distância de casa = 2 blocos
(1, 1) Distância de casa = 2 blocos
(5, -1) Distância de casa = 6 blocos
(-4, 0) Distância de casa = 4 blocos
(-1, -5) Distância de casa = 4 blocos
(-1, -5) Distância de casa = 4 blocos
(2, 2) Distância de casa = 4 blocos
(0, 2) Distância de casa = 2 blocos
(0, -2) Distância de casa = 2 blocos
(-2, 0) Distância de casa = 2 blocos
(-3, 1) Distância de casa = 2 blocos
(-3, 3) Distância de casa = 0 blocos
(0, -4) Distância de casa = 4 blocos
(-3, -1) Distância de casa = 2 blocos
(1, -1) Distância de casa = 2 blocos
(-3, 1) Distância de casa = 2 blocos
(-3, -3) Distância de casa = 0 blocos
(5, -1) Distância de casa = 6 blocos
(0, 0) Distância de casa = 0 blocos
(-1, -3) Distância de casa = 2 blocos
(1, 1) Distância de casa = 2 blocos
(0, 2) Distância de casa = 2 blocos
(-2, 0) Distância de casa = 2 blocos
(0, -4) Distância de casa = 4 blocos
(2, -2) Distância de casa = 4 blocos
```

Agora vamos utilizar a Simulação de Monte Carlo(mais detalhes em breve), para sabermos qual é o mais longo random walk que podemos tomar de forma que em média finalizemos 4 blocos ou menos de nossa casa?

Caso finalizemos 4 blocos ou menos não pegaremos o transporte de retorno para nossa casa, mas sim voltaremos caminhando.

```python
number_of_walks = 10000

for walk_length in range(1,31):
	no_transport = 0
	for _ in range(number_of_walks):
		(x, y) = random_walk(walk_length)
		distance = abs(x) + abs(y)
		if distance <= 4:
			no_transport += 1
	no_transport_percentage = (float(no_transport) / number_of_walks) * 100
	print(f'Tamanho da caminhada = {walk_length} \
		% de não pegar transporte = {no_transport_percentage}')
```

Com **10.000** caminhadas, de tamanhos variando de **1** a **30** blocos, somos capazes de obter o seguinte resultado, que pode variar devido a aleatoriedade:

```
Tamanho da caminhada = 1 		% de não pegar transporte = 100.0
Tamanho da caminhada = 2 		% de não pegar transporte = 100.0
Tamanho da caminhada = 3 		% de não pegar transporte = 100.0
Tamanho da caminhada = 4 		% de não pegar transporte = 100.0
Tamanho da caminhada = 5 		% de não pegar transporte = 88.09
Tamanho da caminhada = 6 		% de não pegar transporte = 93.74
Tamanho da caminhada = 7 		% de não pegar transporte = 76.69
Tamanho da caminhada = 8 		% de não pegar transporte = 86.5
Tamanho da caminhada = 9 		% de não pegar transporte = 67.74
Tamanho da caminhada = 10 		% de não pegar transporte = 78.75
Tamanho da caminhada = 11 		% de não pegar transporte = 59.34
Tamanho da caminhada = 12 		% de não pegar transporte = 73.17
Tamanho da caminhada = 13 		% de não pegar transporte = 53.71
Tamanho da caminhada = 14 		% de não pegar transporte = 66.93
Tamanho da caminhada = 15 		% de não pegar transporte = 48.480000000000004
Tamanho da caminhada = 16 		% de não pegar transporte = 61.47
Tamanho da caminhada = 17 		% de não pegar transporte = 44.43
Tamanho da caminhada = 18 		% de não pegar transporte = 57.63
Tamanho da caminhada = 19 		% de não pegar transporte = 41.46
Tamanho da caminhada = 20 		% de não pegar transporte = 54.58
Tamanho da caminhada = 21 		% de não pegar transporte = 38.67
Tamanho da caminhada = 22 		% de não pegar transporte = 52.05
Tamanho da caminhada = 23 		% de não pegar transporte = 36.5
Tamanho da caminhada = 24 		% de não pegar transporte = 48.63
Tamanho da caminhada = 25 		% de não pegar transporte = 33.0
Tamanho da caminhada = 26 		% de não pegar transporte = 44.330000000000005
Tamanho da caminhada = 27 		% de não pegar transporte = 30.740000000000002
Tamanho da caminhada = 28 		% de não pegar transporte = 42.75
Tamanho da caminhada = 29 		% de não pegar transporte = 29.959999999999997
Tamanho da caminhada = 30 		% de não pegar transporte = 40.660000000000004
```

Observe que o mais longo *random walk* foi **22**, você pode aumentar a quantidade de caminhadas para aumentar a confiança no experimento.

## Simulação de Monte Carlo

O conceito foi inventado pelo matemático polonês-americano **[Stanislaw Ulam](https://en.wikipedia.org/wiki/Stanislaw_Ulam)**, muito conhecido pelo seu trabalho em armamentos termo-nucleares.

Em uma determinada época de sua vida ele estava doente, se recuperando em sua casa e para passar o seu tempo, jogava jogos de paciência, e como um matemático, considerou qual seria a probabilidade de vencer esses jogos, sendo assim, investiu um certo tempo trabalhando a [combinatória](https://en.wikipedia.org/wiki/Combinatorics), de forma que ele pudesse computar a probabilidade de vencer os jogos e apesar de ser um grande matemático, ele falhou nessa questão: as combinatórias eram muito complicadas, foi então que ele pensou:

Supondo que eu jogue diversas mãos e conte o número de mãos que eu venci e divida pelo número total de mãos que eu joguei, mas logo em seguida ele ponderou que já havia jogado diversas mãos e até então não havia ganhado, então provavelmente muito tempo seria tomado para jogar mãos o suficiente para que se possa ter uma boa estimativa, imediatamente ele descartou essa possibilidade, foi então que ele considerou:

Bem, ao invés de eu jogar os jogos, eu posso simular os jogos no computador, e apesar de não ter ideia de como usar um computador na época, ele tinha amigos que possuiam esse conhecimento, foi então que ele conversou com **[John Von Neumann](https://en.wikipedia.org/wiki/John_von_Neumann)**, cientista muito conhecido pela invenção do [Computador de Programa Armazenado](https://en.wikipedia.org/wiki/Stored-program_computer) e pediu a ele para executar as computações no [ENIAC](https://en.wikipedia.org/wiki/ENIAC), que levariam algumas horas para serem concluídas devido as limitações da época.

Foi então que nasceu a [Simulação de Monte Carlo](https://en.wikipedia.org/wiki/Monte_Carlo_method).

Esse método, inclusive foi utilizado no design da [bomba de hidrogênio](https://en.wikipedia.org/wiki/Thermonuclear_weapon).

O que então seria a **Simulação de Monte Carlo**?

É um método de estimativa do valor de uma quantidade desconhecida usando princípios de estatística inferencial

### Estatística Inferencial

- **População**: Um conjunto de exemplos
- **Amostra**: Um subconjunto adequado de uma população
- **Fato chave**: Uma **amostra aleatória** tende a exibir as mesmas propriedades da população da qual é extraída

Muito similar ao **[Random Walk](https://en.wikipedia.org/wiki/Random_walk)**, onde há números muito grande de diferentes "caminhadas aleatórias", onde podemos tomar por exemplos `10.000` passos, em que nós não olhamos todas as possibilidades de passos diferentes de `10.000` passos, mas coletamos uma amostra pequena de por exemplo `100` caminhadas de `10.000` passos, computamos a **média** dessas `100` caminhadas e assumimos que ela é uma boa expectativa do que seria a média de todas as caminhadas possíveis de `10.000` de passos, que é um número muito muito grande.

**Consideramos agora um exemplo**:

Dada uma única moeda, calcule a fração de "caras" que você obteria se jogasse a moeda um número infinito de vezes.

Jogamos ela então uma vez e obtemos "cara".

Jogamos ela então duas vezes e obtemos "cara" em ambas as tentativas.

É então que surge um questionamento importante: Se jogarmos a mesma moeda infinitas vezes, quão confiantes podemos ficar em responder que todas as infinitas jogadas seriam "cara"?

Com apenas duas jogadas é um pouco difícil determinar, porém imagine que joguemos `100` vezes essa mesma moeda, e todas elas resultem em "cara", nesse caso, é possível que haja uma suspeita de que a moeda tem "cara" em ambos os lados, ou existe algum truque que faça sempre resultar em "cara".

Agora considere uma outra simulação de `100` jogadas, que resultaram em `52` "caras" e `48` "coroas" com o seguinte questionamento: Você acha que a probabilidade de o próximo lançamento aparecer caras é `52/100`?

Com os dados que temos disponíveis, é nossa melhor estimativa, baseado na evidência disponível, essa é a melhor hipótese que podemos provavelmente fazer, sendo assim, tipicamente a nossa melhor hipótese é o que vimos, porém nós realmente não devemos ter muita confiança nessa hipótese, porque pode muito bem ser um acidente ou a moeda pode ser tendenciosa.

Sendo assim, a questão é: Por que quando vimos `100` amostras e todas elas resultam em "cara" nos sentimos melhor em escolher "cara" como resultado da possível jogada `101` do que escolher "cara" como resultado da jogada `3` quando vimos apenas `2` amostras que resultaram em "cara"? E também, por que não nos sentimos bem em escolher `52/100` quando vimos `100` jogadas que resultaram como `52` "caras" e `48` "coroas"?

A resposta é chamada de [Variância](https://en.wikipedia.org/wiki/Variance).

Por que existe a diferença em **Confiança**?

A confiança em nossa estimativa depende de duas coisas:

- Tamanho da **amostra** (Nesse caso temos `2` jogadas vs `100` jogadas)
- Variância da amostra (Todos os resultados "caras" vs `52` "caras")
- Conforme a variância cresce, nós precisamos de amostras maiores para que possamos ter o mesmo grau de confiança

Quando o resultado é `100` "caras" não há variabilidade em nossa resposta e quando o resultado é `52` caras e `48` "coroas" há uma grande variabilidade em nossa resposta.

Vamos agora considerar um exemplo de uma roleta, muito utilizada em casinos, para isso vamos utilizar a linguagem Python.

![img](https://i.ibb.co/2PW5t6G/roleta.png)

```python
import random

class Roleta():
    def __init__(self):
        self.numeros = []
        for i in range(1,37):
            self.numeros.append(i)
        self.bola = None
        self.possibilidades = len(self.numeros) - 1
    def girar(self):
        self.bola = random.choice(self.numeros)
    def apostar(self, numero, quantidade):
        if str(numero) == str(self.bola):
            return quantidade * self.possibilidades
        else: 
            return -quantidade
    def __str__(self):
        return 'Roleta'
```

A classe **Roleta()** define uma roleta com `36` números diferentes que podemos apostar (**1** até **36**), uma bola que inicialmente é definida como `None`, e a variável possibilidade que define as possibilidades diferentes de jogo, que nesse caso são `36`.

O método **girar()** fará uma escolha aleatória diante dos `36` diferentes números.

E o método **apostar()** em que você escolhe o número que você vai apostar e respectiva quantidade a ser apostada.

Em seguida definimos uma função chamada **jogar_roleta()**, que nos possibilita girar a roleta diversas vezes para fazermos simulações:

```python
def jogar_roleta(jogo, numero_giros, numero, aposta, imprimir):
    ganhos = 0
    for i in range(numero_giros):
        jogo.girar()
        ganhos += jogo.apostar(numero, aposta)
    if imprimir:
        print(f'{numero_giros} giros de {jogo}')
        print('Retorno esperado da aposta', numero, '=',\
              str(100*ganhos/numero_giros) + '%\n')
    return (ganhos/numero_giros)
```

Ela recebe como parâmetro:

- **jogo**: Nesse caso estamos usando uma roleta simples
- **numero_giros**: Quantidade de vezes que iremos girar a roleta
- **numero**: O número que iremos apostar
- **aposta**: A quantidade que será apostada
- **imprimir**: Se for setada como `True` imprimiremos os resultados no console

O nosso número de **vitorias** começa com `0` e será incrementado se ganharmos ou nada acontecerá se perdermos. Os resultados então serão impressos no console caso a variável imprimir esteja setada como `True`.

Para executarmos as simulações é muito simples:

```python
jogo = Roleta()
for giros in [100, 1000000]:
    for i in range(3):
        jogar_roleta(jogo, giros, 2, 1, True)
```

Nesse caso estamos fazendo `3` giros de **100** e `3` de **1.000.000**.

Um dos possíveis outputs que nos é trazido:

```
100 giros de Roleta
Retorno esperado da aposta 2 = 8.0%

100 giros de Roleta
Retorno esperado da aposta 2 = 8.0%

100 giros de Roleta
Retorno esperado da aposta 2 = -64.0%

1000000 giros de Roleta
Retorno esperado da aposta 2 = 0.656%

1000000 giros de Roleta
Retorno esperado da aposta 2 = -1.09%

1000000 giros de Roleta
Retorno esperado da aposta 2 = 0.2888%
```

Podemos ver que com `100` giros há uma grande variância, e isso que faz apostas serem atrativas para as pessoas, **100** giros seria talvez uma noite inteira no casino e você poderia ganhar por exemplo **44%** e se sentir vitorioso.

Porém quando estamos falando de 1 milhão de giros, as pessoas normalmente não se interessam por um valor tão grande de apostas, mas os casinos certamente estão interessados nesses números altos de apostas, e é nesse caso que vimos muito menos **variância**, não chega a ser **0**, mas é próximo de **0** e todos os resultados estão próximos, pois há baixa variância.

O que está ocorrendo nesse caso é o que se chama de [Lei dos Grandes Números](https://en.wikipedia.org/wiki/Law_of_large_numbers) ou as vezes chamada de **Lei de Bernoulli**, que é um dos dois mais importantes teoremas em toda a Estatística.

"Em testes independentes repetidos com a mesma probabilidade real **p** de um resultado específico em cada teste, a chance de a fração de vezes que esse resultado ocorrer diferir de **p** converge para zero quando o número de tentativas chega ao infinito"

Então quer dizer que se girarmos essa roleta infinitas vezes o retorno esperado sérá **0**.

O que nos leva à **[Falácia do Apostador](https://en.wikipedia.org/wiki/Gambler%27s_fallacy)**:

"No dia 18 de Agosto de 1913, no casino de Monte Carlo, havia uma roleta em que as pessoas apostavam em duas cores apenas: **preto** ou **vermelho** e houve uma situação em que a cor preto ocorreu 26 vezes consecutivas, foi então que houve um pânico e todos correram para apostar no vermelho, não acreditando que a cor preta pudesse continuar ocorrendo."

A probabilidade de ocorrer 26 pretos consecutivos é: `1/67,108,865`

A probabilidade de ocorrer 26 consecutivos pretos quando o giro anterior foi preto é: `1/2`

Que nos leva à **[Regressão à Média](https://en.wikipedia.org/wiki/Regression_toward_the_mean)**, termo inventado por [Francis Galton](https://en.wikipedia.org/wiki/Sir_Francis_Galton), em que a conclusão básica que ele obteve foi que se os pais de uma pessoa são ambos com altura acima da média, é provável que a criança será menor que os pais e se os pais forem menores do que a média, é provável que a criança será mais alta do que a média.

Diferente da **Falácia do Apostador**, que acredita que os eventos poderão se equilibrar, a **Regressão à Média** diz que seguindo um evento extremo (ambos os pais da criança serem altos acima da média) o próximo evento aleatório é muito provável que seja menos extremo (criança nascendo menor).

Agora considerando novamente a roleta:

- Se girarmos uma roleta 10 vezes e obter 100% vermelho, isso é um evento extremo (probabilidade = `1/1024`)
- É então provável que nos próximos 10 giros, teremos menos de 10 vermelhos, em outras palavras, teremos um evento menos extremo
- Sendo assim, se olharmos para a média de 20 giros, ela será próxima da média esperada de 50% vermelhos do que 100% dos primeiros 10 giros.
- Por esse motivo chamamos de **Regressão à Média**, quando mais amostras tomamos, maior a chance de chegarmos à média.