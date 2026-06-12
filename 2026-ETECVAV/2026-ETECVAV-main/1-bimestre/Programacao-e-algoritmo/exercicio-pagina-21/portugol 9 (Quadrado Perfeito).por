programa
{
    inclua biblioteca Matematica

    funcao inicio()
    {
        real numero, raiz
        inteiro r

        escreva("Digite um número: ")
        leia(numero)

        raiz = Matematica.raiz(numero, 2)
        r = raiz

        se (r * r == numero)
        {
            escreva(numero, " é quadrado perfeito")
        }
        senao
        {
            escreva(numero, " não é quadrado perfeito")
        }
    }
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 434; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */