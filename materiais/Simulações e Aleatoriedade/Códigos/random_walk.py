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

# Simulação de Monte Carlo
"""
Qual é o mais longo random walk que podemos tomar
de forma que em média finalizemos 4 blocos ou menos
de nossa casa?

Caso finalizemos 4 blocos ou menos não pegaremos o 
transporte de retorno para nossa casa, mas sim
voltaremos caminhando.
"""
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