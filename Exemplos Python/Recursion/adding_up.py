"""
Função recursiva que computa
a soma dos elementos de uma lista
até um determinado índice
"""
def adding_up(lst,index):
    soma = lst[index]
    if index == 0:
        return soma
    return soma + adding_up(lst,index-1)

lista = [1,2,3,10,15,50]
print(adding_up(lista,0))
print(adding_up(lista,3))
print(adding_up(lista,5))