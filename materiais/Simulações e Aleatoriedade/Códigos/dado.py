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

simulacao('11111',10000,'11111')