from swap import swap

def insertion_sort(array):
    for i in range(1, len(array)):
        j = i
        while j > 0 and array[j - 1] > array[j]:
            swap(array, j, j - 1)
            j -= 1
    return array

array = [3,4,5,6,1,2]
sorted_array = insertion_sort(array)
print(sorted_array)