programa
{
	real altura, media, maiorAltura, menorAltura, somaAlturas, nAlturas
	funcao inicio()
	{
		somaAlturas=0.0
		nAlturas=0.0
		altura=1.0

		enquanto(altura!=0)
		{
			escreva("Insira\n")
			leia(altura)

			se(altura!=0)
			{
				se(nAlturas==0)
				{
					menorAltura=altura
					maiorAltura=altura
				}
				senao
				{
					se(menorAltura>altura)
					{
						menorAltura=altura
					}
					se(maiorAltura<altura)
					{
						maiorAltura=altura
					}
				}
			}
			nAlturas=nAlturas+1
			somaAlturas=somaAlturas+altura
			
		}
		nAlturas=nAlturas-1
		media=somaAlturas/nAlturas

		escreva(altura, " altura\n", media, " media\n", maiorAltura, " maiorAltura\n", menorAltura, " menorAltura\n", somaAlturas, " somaAlturas\n", nAlturas, " nAlturas")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 258; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */