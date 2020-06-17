def palindromo(string):
	"""
	Retorna True se a string for palíndromo
	Caso contrário retorna False
	"""
	if len(string) <= 1:
		return True
	else:
		return string[0] == string[-1] and palindromo(string[1:-1])

abba = palindromo('abba')
python = palindromo('python')

print(abba,python)