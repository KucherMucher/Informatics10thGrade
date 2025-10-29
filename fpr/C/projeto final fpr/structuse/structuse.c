#include <stdio.h>

struct Pessoa{
	char nome[50];
	int idade;
	float altura;
};

int main(){
	int vez;
	struct Pessoa pessoa[2];
	for(vez=0; vez<2; vez++){
        printf("Insira o nome %d: ", vez+1);
		scanf("%s", pessoa[vez].nome);
		printf("Insira a idade %d: ", vez+1);
		scanf("%d", &pessoa[vez].idade);
		printf("Insira a altura %d: ", vez+1);
		scanf("%f", &pessoa[vez].altura);
	}
	for(vez=0; vez<2; vez++){
		printf("\nO/A %s tem %d anos e tem %.2f metros de altura", pessoa[vez].nome, pessoa[vez].idade, pessoa[vez].altura);
	}
	return 0;
}

