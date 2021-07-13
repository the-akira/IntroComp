def somalista(lista):
    if len(lista) == 1:
        return lista[0]
    else:
        return lista[0] + somalista(lista[1:])

lista = [1,2,3,4,5]
print(somalista(lista))