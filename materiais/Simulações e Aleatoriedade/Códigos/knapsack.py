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

def test_greedy(itens, constraint, key_function):
	"""
	Função que testa o Greedy Algorithm
	"""
	taken, val = greedy(itens, constraint, key_function)
	print(f'Valor total de itens = {val}')
	for item in taken:
		print(item)

def test_max_val(itens, max_units, print_items=True):
	print(f'Usando uma Search Tree para alocar {max_units} de peso')
	val, taken = max_val(itens, max_units)
	print(f'Total de valor de itens coletado = {val}')
	if print_items:
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
test_greedys(itens,850)
test_max_val(itens,750)