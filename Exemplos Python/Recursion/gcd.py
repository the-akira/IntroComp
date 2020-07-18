"""
O algoritmo euclidiano, 
que calcula o maior divisor comum de dois números inteiros, 
pode ser escrito recursivamente.
"""
def gcd(x,y):
	if y == 0:
		return x
	else:
		return gcd(y,x%y)

print(gcd(27,9))
print(gcd(100,10))
print(gcd(111,259))