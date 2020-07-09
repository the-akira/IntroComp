def binary_search(L,e):
	def binary_search_helper(L,e,low,high):
		if high == low:
			return L[low] == e
		mid = (low + high)//2
		if L[mid] == e:
			return True
		elif L[mid] > e:
			if low == mid:
				return False
			else:
				return binary_search_helper(L,e,low,mid-1)
		else:
			return binary_search_helper(L,e,mid+1,high)
	if len(L) == 0:
		return False
	else:
		return binary_search_helper(L,e,0,len(L)-1)

L = [1,2,3,4,5,6,7,8,9,10]
print(binary_search(L,6)) # True
print(binary_search(L,11)) # False