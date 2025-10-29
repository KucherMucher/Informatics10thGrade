#include <stdio.h>

int main() {
    int vezes;
    int vezesflow = 0;

    printf("Quantas vezes escrever o nome");
    scanf("%d", &vezes);

    while (vezesflow < vezes){
        printf("Nome\n");
        vezesflow++;
    }

    return 0;
}
