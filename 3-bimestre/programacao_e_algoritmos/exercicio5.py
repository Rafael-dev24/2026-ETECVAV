n = int(input("Digite um número: "))
contador = 0

while n < 1 or n > 10:
    print('número inválido, digite novamente!')
    n = int(input("Digite um número novamente: "))

while contador <= 10:
    resultado = n * contador
    print(f"{n} x {contador} = {resultado}")
    contador += 1

