programa
{
    funcao inicio()
    {
        real tempo, preco

        escreva("Digite o tempo de permanência (em horas): ")
        leia(tempo)

        se (tempo <= 2)
        {
            preco = tempo * 2
        }
        senao
        {
            preco = (2 * 2) + ((tempo - 2) * 1)
        }

        escreva("Tempo: ", tempo, " horas")
        escreva(" Valor a pagar: R$ ", preco)
    }
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 366; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */