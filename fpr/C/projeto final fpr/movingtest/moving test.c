#include <stdio.h>
#include <conio.h>  //getch

#define width 101
#define hight 51

void mapCriar (float x, float y){
    int z, r; //alternativas para x e y
    for(r=0; r<hight; r++){
        for(z=0; z<width; z++){
            if(z==(int)x&&r==(int)y){ //usei (int) para curtar a parte decimal, porque eu quero que um quadrado (neste caso ponto) tiha a razão de 10 em 1 entre posição, ou seja, 10 posições num quadrado
                printf("P");          //porque 10 em 1? isto está includio no meu rascunho/relatorio sobre o trabalho
            }
            else{
                switch(r){ //rendering
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                    printf("*"); //Zona final
                    break;
                case 13:
                case 14:
                    printf("#"); //Zona montanhas
                    break;
                case 15:
                    if(z<=30){printf("!");}  //zona dos orcos
                    if(z>30&&z<69){printf("-");} //zona humana
                    if(z>=69){printf("?");}  //zona dos mortos
                    break;
                case 16:
                    if(z<=29){printf("!");}  //zona dos orcos
                    if(z>29&&z<71){printf("-");} //zona humana
                    if(z>=71){printf("?");}  //zona dos morto
                    break;
                case 17:
                    if(z<=28){printf("!");}  //zona dos orcos
                    if(z>28&&z<72){printf("-");} //zona humana
                    if(z>=72){printf("?");}  //zona dos mortos
                    break;
                case 18:
                    if(z<=27){printf("!");}  //zona dos orcos
                    if(z>27&&z<73){printf("-");} //zona humana
                    if(z>=73){printf("?");}  //zona dos mortos
                    break;
                case 19:
                    if(z<=26){printf("!");}  //zona dos orcos
                    if(z>26&&z<74){printf("-");} //zona humana
                    if(z>=74){printf("?");}  //zona dos mortos
                    break;
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                    if(z<=25){printf("!");}  //zona dos orcos
                    if(z>25&&z<75){printf("-");} //zona humana
                    if(z>=75){printf("?");}  //zona dos mortos
                    break;
                case 33:
                    if(z<=26){printf("!");}  //zona dos orcos
                    if(z>26&&z<74){printf("-");} //zona humana
                    if(z>=74){printf("?");}  //zona dos mortos
                    break;
                case 34:
                    if(z<=27){printf("!");}  //zona dos orcos
                    if(z>27&&z<73){printf("-");} //zona humana
                    if(z>=73){printf("?");}  //zona dos mortos
                    break;
                case 35:
                    if(z<=28){printf("!");}  //zona dos orcos
                    if(z>28&&z<72){printf("-");} //zona humana
                    if(z>=72){printf("?");}  //zona dos mortos
                    break;
                case 36:
                    if(z<=29){printf("!");}  //zona dos orcos
                    if(z>29&&z<71){printf("-");} //zona humana
                    if(z>=71){printf("?");}  //zona dos morto
                    break;
                case 37:
                    if(z<=30){printf("!");}  //zona dos orcos
                    if(z>30&&z<69){printf("-");} //zona humana
                    if(z>=69){printf("?");}  //zona dos mortos
                    break;
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                    printf(":");
                    break;
                case 43:
                    if(z>=47&&z<=53){printf(".");}
                    if(z<47||z>53){printf(":");}
                    break;
                case 44:
                    if(z>=44&&z<=56){printf(".");}
                    if(z<44||z>56){printf(":");}
                    break;
                case 45:
                    if(z>=41&&z<=59){printf(".");}
                    if(z<41||z>59){printf(":");}
                    break;
                case 46:
                    if(z>=39&&z<=61){printf(".");}
                    if(z<39||z>61){printf(":");}
                    break;
                case 47:
                    if(z>=36&&z<=64){printf(".");}
                    if(z<36||z>64){printf(":");}
                    break;
                case 48:
                    if(z>=33&&z<=67){printf(".");}
                    if(z<33||z>67){printf(":");}
                    break;
                case 49:
                    if(z>=30&&z<=70){printf(".");}
                    if(z<30||z>70){printf(":");}
                    break;
                case 50:
                    if(z>=28&&z<=72){printf(".");}
                    if(z<28||z>72){printf(":");}
                    break;
                }
            }
        }
        printf("\n");
    }
}

int main(){
    float x=50, y=49, i=1;
    char inpt;

    while(i==1){
        printf("Posicao: %.2f, %.2f\n", x, y);
        inpt = getch();

        switch(inpt){
        case 'S':
        case 's':
            if(y<50){
                y=y+0.01;
            }
        break;
        case 'A':
        case 'a':
            if(x>0){
                x=x-0.01;
            }
        break;
        case 'W':
        case 'w':
            if(y>0){
                y=y-0.01;
            }
        break;
        case 'D':
        case 'd':
            if(x<100){
                x=x+0.01;
            }
        break;
        case 'M':
        case 'm':
            mapCriar(x, y);
        break;
        }
    }
}
















/*
                if(r<13){             // zona 5...nível 4...rendering 1
                    printf("*");
                }
//--------------------------------------------------------------------------------------
                if(r>=13&&r<=14){     //zona 4..."montanhas".nível 2.5...rendering 1
                    printf("#");
                }
//-----------------------------------------------------------------------------------
                if(r>=15&&r<37&&z<=25){  // zona 3.1...nível 3...rendering 1
                    printf("!");
                }
                if(r>=15&&r<37&&z>25&&z<75){ // zona 2...nível 1...rendering 2
                    printf("-");
                }
                if(r>=15&&r<37&&z>=75){  // zona 3.2...nível 3.5...rendering 3
                    printf("?");
                }
//--------------------------------------------------------------------------------------
                if(r>=37&&r<43){              // zona 1...nível 2...rendering 1
                    printf(":");
                }
//-----------------------------------------------------------------

//-----------------------------------------------------------------
*/

