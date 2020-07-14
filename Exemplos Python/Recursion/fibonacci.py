# Fibonacci: O(2^n) Exponencial
def fib(n):
	if n == 1 or n == 2:
		return 1
	else:
		return fib(n-1) + fib(n-2)

# Fibonacci: O(n) Linear
cache = {}
def fibonacci(n):
	if n in cache:
		return cache[n]
	if n == 1 or n == 2:
		resposta = 1
	elif n > 2:
		resposta = fibonacci(n-1) + fibonacci(n-2)
	cache[n] = resposta
	return resposta

for n in range(1,201):
	print(f"{n} = {fibonacci(n)}")