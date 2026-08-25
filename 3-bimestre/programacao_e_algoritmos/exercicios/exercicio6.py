print('Bem vindo ao programa de calculo de média!')

soma = 0
qtd = 0

nota = float(input('Digite a nota do aluno (ou -1 para sair): '))

while nota >=0 and nota<=10:
    soma = soma + nota
    qtd +=1
    nota = float(input('digite outra nota: '))
if qtd > 0:
    media = soma / qtd
    print(f'média das notas: {media}')
else: 
    print('nota inválida! ')