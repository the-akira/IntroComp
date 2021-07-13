# Função recursiva que retorna o maior elemento de uma lista
def largest(lst):
    if len(lst) == 1:
        return lst[0]
    if lst[1] > lst[0]:
        lst.pop(0)
    else:
        lst.pop(1)
    return largest(lst)

lst = [27.8,1.7,2,3,40.33,6,11,13]
print(largest(lst))