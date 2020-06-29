from swap import swap

def shell_sort(array):
	array_len = len(array)
	gap = array_len//2
	while gap > 0:
		for i in range(gap,array_len):
			if i < array_len:
				j = i - gap
				while(j >= 0 and array[j] > array[j+gap]):
					swap(array,j,j+gap)
					j -= gap
		gap //= 2
	return array

arr = [1,30,33,20,14,4,3,5,2,13,39,22]
sorted_arr = shell_sort(arr)
print(sorted_arr)