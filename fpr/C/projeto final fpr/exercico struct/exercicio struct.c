#include <stdio.h>

struct Aluno{
	char nome[50];
	int idade;
	float notaFinal;

};

int main(){
	int vez;
	struct Aluno aluno[5];
	for(vez=0; vez<2; vez++){
        printf("Insira o nome do aluno %d: ", vez+1);
		scanf("%s", aluno[vez].nome);
		printf("Insira a idade do aluno %d: ", vez+1);
		scanf("%d", &aluno[vez].idade);
		printf("Insira a nota final do aluno %d: ",vez+1);
		scanf("%f", &aluno[vez].notaFinal);
	}
	for(vez=0; vez<5; vez++){
		printf("\nO/A %s tem %d anos e a nota final e %.1f", aluno[vez].nome, aluno[vez].idade, aluno[vez].notaFinal);
		if(aluno[vez].notaFinal<10){
            printf("\nChumbou.");
		}
		else{
            printf("\nPassou.");
		}
	}
	return 0;
}
