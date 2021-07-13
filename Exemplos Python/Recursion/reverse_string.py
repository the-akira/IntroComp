# Invertendo uma string de maneira recursiva
def reverse_string(string):
    if string == '':
        return ''
    else:
        return string[len(string)-1] + reverse_string(string[0:len(string)-1])

string = 'gabriel'
string_invertida = reverse_string(string)
print(string_invertida)