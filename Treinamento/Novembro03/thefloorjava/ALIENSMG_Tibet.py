n = 1
while n != 0:
	n = int(input())
	especies = {}
	for i in range(n):
		especie = ''.join(sorted(input()))
		if(especie not in especies.keys()):
			especies[especie] = 0

	if(len(especies.keys()) != 0):
		print(len(especies.keys()))
'''
palavra = input()
palavras_ordenadas = 
print(len(palavras_ordenadas))
'''