contador = 1 
fatorial = 1

n = int(input('digite um número inteiro positivo: '))


if n >= 0:
    while contador <= n:
          fatorial = fatorial * contador
          contador +=1
    print(f'Fatorial: {fatorial}')
else:
     print('Número invalido! ')