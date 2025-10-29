programa
{
	
	funcao inicio()
	{
		real n1, n2, area

		escreva("Vamos calcular a área de um paralelogramo. \nInsira os dados em metros.\nBase: ")
		leia(n1)
		escreva("Altura: ")
		leia(n2)

		area=n1*n2

		se(n1==n2)
		{
			escreva("A área do quadrado é: ", area, " m2")
		}
		senao
		{
			escreva("A área do retângulo é: ", area, " m2")
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 198; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */