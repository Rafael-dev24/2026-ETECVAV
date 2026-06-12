programa
{
    funcao inicio()
    {
        real a, b, c

        escreva("o ponto a, b e c Triângulo Equilátero")
        leia(a)
        leia(b)
        leia(c)

        se (a < b + c e b < a + c e c < a + b) {
            se (a == b e b == c) {
                escreva("Triângulo Equilátero")
            }
            senao se (a == b ou a == c ou b == c) {
                escreva("Triângulo Isósceles")
            }
            senao {
                escreva("Triângulo Escaleno")
            }
        }
        senao {
            escreva("Não forma triângulo")
        }
    }
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 310; 
 * @PONTOS-DE-PARADA = 5;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */