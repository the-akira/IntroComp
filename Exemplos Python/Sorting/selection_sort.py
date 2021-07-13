from swap import swap

def selection_sort(array):
    array_len = len(array)
    for i in range(0,array_len-1):
        j = k = i 
        while j < array_len:
            if array[j] < array[k]:
                k = j
            j += 1
        swap(array,i,k)
    return array 

arr = [1,30,33,20,14,4,3,5,2]
sorted_arr = selection_sort(arr)
print(sorted_arr)