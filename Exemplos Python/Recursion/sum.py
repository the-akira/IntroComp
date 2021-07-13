"""
Função sum()
Soma recursiva dos N primeiros números naturais
"""
def sum(n):
    if n == 0:
        return n
    else:
        return n + sum(n-1)

print(sum(4))

"""
sum(4) -> 1ª chamada com n=4
4 + sum(3) -> 2ª chamada com n=3
4 + 3 + sum(2) -> 3ª chamada com n=2
4 + 3 + 2 + sum(1) -> 4ª chamada com n=1
4 + 3 + 2 + 1 -> retorno da 4 chamada com n=1
4 + 3 + 3 -> retorno da 3 chamada com n=2
4 + 6 -> retorno da 2 chamada com n=3
10 -> retorno da 1 chamada com n=4
"""