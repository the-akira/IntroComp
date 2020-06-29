from swap import swap

def bubble_sort(array):
	flag = False
	array_len = len(array)
	for i in range(0,array_len-1):
		flag = False
		for j in range(0,array_len-i-1):
			if(array[j] > array[j+1]):
				swap(array,j,j+1)
				flag = True
		if flag == False:
			break
	return array 

arr = [1,30,33,20,14,4,3,5,2]
sorted_arr = bubble_sort(arr)
print(sorted_arr)