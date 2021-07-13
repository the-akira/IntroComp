class Queue:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if len(self.items) < 1:
            return None
        return self.items.pop(0)

    def size(self):
        return len(self.items)

    def front(self):
        return self.items[0]

    def rear(self):
        return self.items[-1]

    def clear(self):
        self.items = []

    def display(self):
        for item in self.items:
            print(item)

q = Queue()

for item in range(1,8):
    q.enqueue(item)

print(f"Elemento removido da fila: {q.dequeue()}")
print(f"Elemento removido da fila: {q.dequeue()}")
print(f"Primeiro elemento da fila: {q.front()}")
print(f"Último elemento da fila: {q.rear()}") 
print(f"Tamanho da fila: {q.size()}")
print(f"Fila está vazia? {q.is_empty()}")
q.display()