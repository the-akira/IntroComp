# Função recursiva que computa permutações de uma string
def permutations(string):
	lst = []
	str_len = len(string)

	if str_len < 2:
		lst.append(string)
		return lst

	for i in range(str_len):
		current_char = string[i]
		remaining_str = string[0:i] + string[i+1:str_len]
		remaining_perm = permutations(remaining_str)

		if string.index(current_char) != i:
			continue
		for substring in remaining_perm:
			lst.append(current_char + substring)
			
	return lst

p1 = permutations('abc')
p2 = permutations('abcd')
p3 = permutations('abcde')
print(p1,len(p1))
print(p2,len(p2))
print(p3,len(p3))