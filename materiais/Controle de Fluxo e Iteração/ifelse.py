# Exemplo de programa com controle de fluxo if...else
num = int(input("Digite um número: "))

if num > 0:
	print(f"{num} é positivo")
elif num == 0:
	print(f"Número é {num}")
else:
	print(f"{num} é negativo")