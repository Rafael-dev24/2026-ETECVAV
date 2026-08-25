numero1 = int(input("digite primero número: "))
numero2 = int(input("digite o segundo número: "))

if numero1 > numero2:
    print(f"{numero1} é maior que {numero2}!")
elif numero2 > numero1:
    print(f"{numero2} é maior que {numero1}")
elif numero1 == numero2:
    print(f"{numero1} e {numero2} são iguais!")