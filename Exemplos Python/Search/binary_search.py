def binary_search(array,key):
	"""
	Função que implementa Binary Search
	Recebe um array & key
	Retorna a posição & key
	"""
	array_len = len(array)
	low = 0
	high = array_len - 1
	while low <= high:
		mid = (low + high)//2
		if key == array[mid]:
			return mid, key
		elif key < array[mid]:
			high = mid - 1
		else:
			low = mid + 1 
	return False

arr = [1,2,3,4,5,6,7,8]
elemento = binary_search(arr,4)
print(elemento)