# Função recursiva que busca por um elemento em uma lista
def find(lst, item):
	if len(lst) == 0:
		return False
	if lst[0] == item:
		return True
	else:
		return find(lst[1:],item)

lista = [1,12,15,27,33,43]
print(find(lista,27))