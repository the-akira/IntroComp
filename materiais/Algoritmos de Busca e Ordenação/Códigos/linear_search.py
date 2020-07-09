def linear_search(L,e):
	found = False
	for i in range(len(L)):
		if e == L[i]:
			found = True
	return found

L = [4,2,3,1,5]
print(linear_search(L,5)) # True
print(linear_search(L,6)) # False