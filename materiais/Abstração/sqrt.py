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

sqrt(16)
sqrt(-3)
sqrt(7)