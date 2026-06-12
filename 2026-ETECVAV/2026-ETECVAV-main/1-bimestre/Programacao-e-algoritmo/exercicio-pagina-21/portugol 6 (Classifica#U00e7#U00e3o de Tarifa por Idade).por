programa
{
    funcao inicio()
    {
        inteiro idade

        escreva("Digite a idade do passageiro: ")
        leia(idade)

        se (idade <= 2)
        {
            escreva("Gratuita")
        }
        senao se (idade <= 12)
        {
            escreva("Meia tarifa")
        }
        senao
        {
            escreva("Tarifa completa")
        }
    }
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 184; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */