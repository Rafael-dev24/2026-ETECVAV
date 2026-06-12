programa
{
    funcao inicio()
    {
        inteiro n1, n2, n3, maior

        escreva("Digite o primeiro número: ")
        leia(n1)

        escreva("Digite o segundo número: ")
        leia(n2)

        escreva("Digite o terceiro número: ")
        leia(n3)

        maior = n1

        se (n2 > maior)
        {
            maior = n2
        }

        se (n3 > maior)
        {
            maior = n3
        }

        escreva("Maior valor: ", maior)
    }
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 260; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */