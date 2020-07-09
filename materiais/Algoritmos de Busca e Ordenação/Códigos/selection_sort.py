def selection_sort(L):
	suffix = 0
	while suffix != len(L):
		for i in range(suffix,len(L)):
			if L[i] < L[suffix]:
				L[suffix], L[i] = L[i], L[suffix]
		suffix += 1
	return L 

L = [5,4,3,2,1]
print(selection_sort(L))