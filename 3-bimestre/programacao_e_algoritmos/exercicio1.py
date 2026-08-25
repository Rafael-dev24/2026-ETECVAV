numero = int(input("digite um número: "))

if numero < 0:
    print(f"{numero} é negativo!")
elif numero > 0:
    print(f"{numero} é positivo!")
else:
    print(f"{numero} é invalido!")