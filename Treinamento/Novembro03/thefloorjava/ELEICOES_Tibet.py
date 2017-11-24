num = int(input())
votos = 0
vencedor = 0
candidatos = {}

# Armazena no dicionario
for i in range(num):
	candidato = int(input())
	if(candidato in candidatos.keys()):
		candidatos[candidato] += 1
	else:
		candidatos[candidato] = 1

# Verifica quem recebeu mais votos
for key in candidatos:
	if(candidatos[key] > votos):
		vencedor = key
		votos = candidatos[key]
print(vencedor)
