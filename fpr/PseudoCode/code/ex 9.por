programa
{
	
	funcao inicio()
	{
		real A, B, C, n

		escreva("Introduz 3 valores, para A, B, e C\nA = ")
		leia(A)
		escreva("B = ")
		leia(B)
		escreva("C = ")
		leia(C)

		n=A+B

		se(n==C)
		{
			escreva("A + B = C, ou seja, ", A, " + ", B, " = ", C)
		}
		senao
		{
			se(n<C)
			{
				escreva("A + B < C, ou seja, ", A, " + ", B, " < ", C)
			}
			senao
			{
				escreva("A + B > C, ou seja, ", A, " + ", B, " > ", C)
			}
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 128; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */