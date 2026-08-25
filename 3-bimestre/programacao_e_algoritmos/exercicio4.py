numero = int(input("digite um número:"))
contador = 1
soma = 0

while contador <= numero:
    if contador % 2 != 0:
        contador += 1
        soma = soma + contador
        print("A soma dos números ímpares é:", soma)
    elif contador % 2 == 0:
        contador += 1
        soma = soma + contador
        print("A soma dos números pares é:", soma)
        
    
        