tentativas = 1
limitedetentativas = 3
senhacorreta = 6767676767

senha = int(input('digite sua senha (somente números por favor): '))


while senha != senhacorreta and tentativas < limitedetentativas:
    senha = int(input('tente novamente: '))
    tentativas +=1
if senha == senhacorreta:
    print('A senha está correta! ')
else:
    print('acesso bloqueado! ')