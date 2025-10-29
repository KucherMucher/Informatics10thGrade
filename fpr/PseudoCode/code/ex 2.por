programa
{
	
	funcao inicio()
	{
		real n1, n2

		escreva("Insira dois números inteiros diferentes: \n")
		leia(n1)
		leia(n2)

		se(n1==n2)
		{
			escreva("Os números são iguais")
		}
		senao
		{
			se(n1<n2)
			{
				escreva(n1, " é menor que ", n2)
			}
			senao
			{
				escreva(n1, " é maior que ", n2)
			}
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 289; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */