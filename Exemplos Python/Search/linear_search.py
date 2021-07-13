def linear_search(array,key):
    """
    Função que implementa Linear Search
    Recebe um array & key
    Retorna a posição & key
    """
    array_len = len(array)
    for i in range(0,array_len):
        if key == array[i]:
            return True, i, key
    i += 1
    return False

arr = [1,15,18,25,13,2,5]
elemento = linear_search(arr,1)
print(elemento)