programa
{
    funcao inicio()
    {
        real etanol, gasolina, limite

        escreva("Digite o preço do etanol: ")
        leia(etanol)

        escreva("Digite o preço da gasolina: ")
        leia(gasolina)

        limite = gasolina * 70 / 100

        se (etanol <= limite)
        {
            escreva("Abastecer com Etanol")
        }
        senao
        {
            escreva("Abastecer com Gasolina")
        }
    }
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 435; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */