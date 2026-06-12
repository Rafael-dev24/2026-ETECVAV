programa
{
    funcao inicio()
    {
        real valor, desconto, valor_final

        escreva("Digite o valor da compra: ")
        leia(valor)

        se (valor < 100)
        {
            desconto = 0
        }
        senao se (valor <= 500)
        {
            desconto = valor * 10 / 100
        }
        senao
        {
            desconto = valor * 20 / 100
        }

        valor_final = valor - desconto

        escreva("Valor da compra: R$ ", valor)
        escreva(" Desconto aplicado: R$ ", desconto )
        escreva(" Valor final com desconto: R$ ", valor_final )
    }
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 543; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */