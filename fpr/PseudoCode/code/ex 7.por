programa
{
	
	funcao inicio()
	{
		inteiro n, soma


		escreva("Vamos somar números. Quando queres terminar a soma, introduza o número 0")
		escreva("\nIntroduz o número: \n")
		leia(n)

		soma=0

		enquanto(n!=0)
		{
			soma=soma+n
			leia(n)
		}
		escreva("A soma é ", soma)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 50; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */