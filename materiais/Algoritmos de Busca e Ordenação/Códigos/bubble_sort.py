def bubble_sort(L):
	swap = False
	while not swap:
		swap = True 
		for j in range(1,len(L)):
			if L[j-1] > L[j]:
				swap = False
				temp = L[j]
				L[j] = L[j-1]
				L[j-1] = temp
	return L 

L = [5,4,3,2,1]
print(bubble_sort(L))