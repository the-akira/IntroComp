import math

"""
Função que converte um número
decimal para binário usando uma Stack
"""

def decimal_to_binary(num):
	stack = []
	binary_string = ''

	while num > 0:
		rem = math.floor(num%2)
		stack.append(rem)
		num = math.floor(num/2)

	while len(stack) != 0:
		binary_string += str(stack.pop())

	return int(binary_string)

print(decimal_to_binary(41))
print(decimal_to_binary(2))
print(decimal_to_binary(8))

"""
Nesse algoritmo, enquanto o resultado da divisão não é zero, 
obtemos o restante da divisão (modulo - mod) e o empurramos 
para a Stack e atualizamos o número que será dividido por 2. 
Em seguida, eliminamos os elementos da Stack até ficar vazia, 
concatenando os elementos que foram removidos da Stack em uma 
String.
"""