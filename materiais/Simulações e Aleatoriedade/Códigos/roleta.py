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

jogo = Roleta()
for giros in [100, 1000000]:
    for i in range(3):
        jogar_roleta(jogo, giros, 2, 1, True)