programa
{
    funcao inicio()
    {
        inteiro classificacao

        escreva("Digite a idade: ")
        leia(classificacao)

        se (classi ficacao <= 10) {
           escreva("Infantil")
        }
        senao se (classificacao <= 14) {
           escreva("Infantojuvenil")
        }
        senao se (classificacao <= 17) {
           escreva("Juvenil")
        }
        senao {
           escreva("Adulto")
        }
    }
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 152; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */