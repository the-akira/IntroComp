import random

# Gerando 10 números no intervalo [0,1)
for _ in range(10):
	print(random.random())

# Gerando 10 números no intervalo [3,7)
for _ in range(10):
	print(random.uniform(3,7))

# Simulando 10 rolagens de um dado de 6 lados
for _ in range(10):
	print(random.randint(1,6))

# Simulando 10 escolhas de Pedra, Papel e Tesoura
itens = ['pedra','papel','tesoura']
for _ in range(10):
	print(random.choice(itens))