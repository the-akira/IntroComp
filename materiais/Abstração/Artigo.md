# Abstração

Abstração é o ato de representar recursos essenciais sem incluir os detalhes ou explicações do plano de fundo. No domínio da ciência da computação e engenharia de software, o princípio de abstração é usado para reduzir a complexidade e permitir o design e a implementação eficiente de sistemas de software complexos.

Abstração é um processo, uma estratégia e o resultado da redução de detalhes de forma a focar em conceitos relevantes para o entendimento e solução de problemas.

A abstração é um dos princípios mais importantes na engenharia de software orientada a objetos e está intimamente relacionada a vários outros conceitos importantes, incluindo encapsulamento, herança e polimorfismo.

A abstração é aplicada no processo de identificação de [artefatos de software (objetos)](https://en.wikipedia.org/wiki/Object_(computer_science)) para modelar o domínio do problema. É o processo de reduzir esses objetos à sua essência, de modo que apenas os elementos necessários sejam representados. 

Abstração define um objeto em termos de suas propriedades, funcionalidade e interface (meios de comunicação com outros objetos).

O processo de abstração também pode ser chamado de modelagem e está intimamente relacionado aos conceitos de teoria e design. Os modelos também podem ser considerados tipos de abstrações por sua generalização de aspectos da realidade.

<figure>
    <blockquote>
        <p>"A essência das abstrações é preservar informações relevantes em um determinado contexto e esquecer informações irrelevantes nesse contexto."</p>
        <footer>
            <cite>— John V. Guttag</cite>
        </footer>
    </blockquote>
</figure>

Uma forma central de abstração na computação é a abstração de linguagem: novas linguagens artificiais são desenvolvidas para expressar aspectos específicos de um sistema. [Linguagens de modelagem](https://en.wikipedia.org/wiki/Modeling_languages) ajudam no planejamento de um Software por exemplo.

Um exemplo desse processo de abstração é o desenvolvimento geracional de linguagens de programação: da **linguagem de máquina** para a **linguagem assembly** e a **linguagem de alto nível**. Cada estágio pode ser usado como uma escadaria para o próximo estágio. A abstração da linguagem continua, por exemplo, nas [linguagens de script](https://en.wikipedia.org/wiki/Scripting_language) e nas [linguagens de programação específicas de domínio](https://en.wikipedia.org/wiki/Domain-specific_language).

A computação opera principalmente independentemente do mundo concreto. O hardware implementa um [modelo de computação](https://en.wikipedia.org/wiki/Model_of_computation) que é intercambiável com outros. O software é estruturado em arquiteturas para permitir que os humanos criem sistemas enormes, concentrando-se em alguns problemas de cada vez. Essas arquiteturas são feitas de escolhas específicas de abstrações.

![img](https://i.ibb.co/Sy2CcRd/Camadas-Abstra-o.png)

<figure>
    <blockquote>
        <p>A figura acima representa as camadas de abstração existentes em um Computador (Software + Hardware)</p>
    </blockquote>
</figure>

Dentro de uma linguagem de programação, alguns recursos permitem ao programador criar novas abstrações. Isso inclui [sub-rotinas](https://en.wikipedia.org/wiki/Subroutine), [módulos](https://en.wikipedia.org/wiki/Module_(programming)), [polimorfismo](https://en.wikipedia.org/wiki/Polymorphism_(computer_science)) e [componentes de software](https://en.wikipedia.org/wiki/Software_component). Algumas outras abstrações, como padrões de design de software e estilos arquitetônicos operam no design de um sistema.

Algumas abstrações são projetadas para interagir com outras abstrações - por exemplo, uma linguagem de programação pode conter uma [interface de função externa](https://en.wikipedia.org/wiki/Foreign_function_interface) para fazer chamadas para uma linguagem de nível inferior.

## Abstração e Decomposição através de Funções

**Decomposição:** É uma maneira de estruturar o código, colocá-lo em módulos que fazem sentido por si próprios. Módulos que possam ser utilizados em múltiplos casos, que são capazes de isolar componentes do processo.

**Abstração:** Nos permite suprimir detalhes. Nos permite esconder as especificações de um determinado cálculo e tratá-las como uma "caixa-preta"

A "caixa-preta" é capaz de receber **inputs** e através de um "contrato" obtemos um **output**, sem necessariamente precisarmos saber o que há dentro dessa "caixa misteriosa".

Um mecanismo muito importante que nos permite atingir Abstração e Decomposição são as **Funções**.

As Funções permitem:

- Dividir nosso código em **módulos**
- Suprimir detalhes
- Criar novos "primitivos" que podem ser reaproveitados

### Computando Raíz Quadrada

Vejamos um exemplo de como podemos definir uma função em Python capaz de computar a raíz quadrada.

```python
def sqrt(x):
	"""
	Retorna a raíz quadrada de x, se x for um quadrado perfeito
	Caso contrário imprime um erro e retorna None
	"""
	resposta = 0
	if x >= 0:
		while resposta * resposta < x: 
			resposta += 1
		if resposta * resposta != x:
			print(f'{x} não é um quadrado perfeito')
			return None
		else:
			print(f'Raiz quadrade de {x} = {resposta}')
			return resposta
	else:
		print(f'{x} é um número negativo')
		return None
```

Definimos uma função chamada de **[sqrt()](https://github.com/the-akira/IntroComp/blob/master/materiais/Abstra%C3%A7%C3%A3o/sqrt.py)** que recebe um parâmetro **x**. Para que possamos utilizar essa função, em outras palavras, invocá-la, precisamos chamá-la pelo seu nome e passar a ela um argumento, nesse caso, um número que desejamos computar a raíz quadrada. Vejamos exemplos.

```python
sqrt(16)
sqrt(-3)
sqrt(7)
```

Imediatamente nos será retornado:

```
Raiz quadrade de 16 = 4
-3 é um número negativo
7 não é um quadrado perfeito
```

Essa invocação conecta **x** ao valores **16**, **-3** e **7**. Essa "conexão" é local, em outras palavras, só existe nos confinamentos desse procedimento(Função), assim como a variável que definimos como o nome **resposta**, ela também é local.

Essas "conexões locais" não afetam as variáveis globais na linguagem Python.

De forma a compreendermos essa ideia, consideremos a função **[f()](https://github.com/the-akira/IntroComp/blob/master/materiais/Abstra%C3%A7%C3%A3o/f.py)**:

```python
def f(x):
	x += 2
	return x
```

Vamos então definir uma variável **x** e invocar a função **f()** para testarmos:

```python
x = 3
print(f(x))
print(x)
```

Nos será retornado:

``` 
5
3
```

Veja que a função nos retornou o resultado **5** e o valor **3** foi preservado. Também é possível armazenarmos o resultado em uma variável:

```python
z = f(x)
print(z)
```

O código acima irá nos trazer como **output** o valor **5**.

### Determinando se uma palavra é Palíndromo

![img](https://i.ibb.co/4pftv9D/Ambigram-palindrome-Wash-your-sins-not-only-your-face-in-Greek.jpg)

Definindo uma função **Recursiva** para sabermos se uma palavra é **palíndromo**: 

Um palíndromo é uma palavra, frase ou qualquer outra sequência de unidades (como uma cadeia de ADN; Enzima de restrição) que tenha a propriedade de poder ser lida tanto da direita para a esquerda como da esquerda para a direita. Num palíndromo, normalmente são desconsiderados os sinais ortográficos (diacríticos ou de pontuação), assim como o espaços entre palavras

A palavra "palíndromo" vem das palavras gregas palin (πάλιν (πάλι, no grego moderno) "para trás, novamente") e dromos (δρόμος, "caminho, rua") - que corre em sentido inverso.

```python
def palindromo(string):
	"""
	Retorna True se a string for palíndromo
	Caso contrário retorna False
	"""
	if len(string) <= 1:
		return True
	else:
		return string[0] == string[-1] and palindromo(string[1:-1])
```

Vamos então testar se a função **[palindromo()](https://github.com/the-akira/IntroComp/blob/master/materiais/Abstra%C3%A7%C3%A3o/palindromo.py)** é capaz de operar corretamente

```python
abba = palindromo('abba')
python = palindromo('python')

print(abba,python)
```

Nos será retornado `True` para a palavra **abba** (que é palíndromo) e `False` para a palavra **Python** (que não é palíndromo). Através de uma simples definição, conseguimos estabelecer o cálculo para descobrir se uma palavra é ou não palíndromo, sem necessariamente termos que nos preocuparmos com os detalhes computacionais internos da Função/Procedimento.
