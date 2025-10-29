programa
{
	inteiro n, maior, menor, na, soma
	real media
//"na" é o número de alturas
	funcao inicio()
	{
		escreva("Intorduz as alturas das colegas da tua turma em cm para calcular os dados das alturas da tua turma.\nEnquanto queres terminar a introdução, introduz 0.\n")
		leia(n)
		maior=0
		menor=1000
		soma=0
		na=0

		enquanto(n==0)
		{
			escreva("Não podes introduzir 0 no início da conta, introduz a altura outra vez.\n")
			leia(n)
		}

		enquanto(n!=0)
		{
			na=na+1
			se(n>maior)
			{
				maior=n
			}
			se(n<menor)
			{
				se (n!=0)
				{
					menor=n
				}
			}
			soma=n+soma
			leia(n)
		}
		se(n==0)
		media=(n+soma)/na
		escreva("A média das alturas é ", media, " cm, a pessoa mais alta tem ", maior, " cm e a menor tem ", menor, " cm")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 86; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */