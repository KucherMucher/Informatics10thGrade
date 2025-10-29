#include <stdio.h>
int main(){
int variavel;
scanf("%d", &variavel);
switch(variavel){
case 1:
    printf("Variavel = 1");
    break;
case 2:
    printf("Variavel = 2");
    break;
case 3:
    printf("Variavel = 3");
    break;
case 4:
    printf("Variavel = 4");
    break;
default:
    printf("Variavel > 4");
}
return 0;
}
