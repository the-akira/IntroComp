class Stack:
	def __init__(self):
		self.items = []

	def is_empty(self):
		return self.items == []

	def push(self, item):
		self.items.append(item)

	def pop(self):
		return self.items.pop()

	def peek(self):
		return self.items[len(self.items)-1]

	def size(self):
		return len(self.items)

	def clear(self):
		self.items = []

	def display(self):
		for item in self.items:
			print(item)

s = Stack()

for item in range(1,8):
	s.push(item)

print(f"Elemento removido da Stack: {s.pop()}")
print(f"Elemento removido da Stack: {s.pop()}")
print(f"Tamanho da Stack: {s.size()}")
print(f"Stack está vazia: {s.is_empty()}")
print(f"Elemento do topo da Stack: {s.peek()}")
s.display()