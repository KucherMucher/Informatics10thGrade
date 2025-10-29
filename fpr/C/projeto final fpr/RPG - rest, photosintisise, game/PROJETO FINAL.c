//JOGO YEEEEEEEEEEEEE
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define width 101
#define hight 51

FILE *savefile;


//history
long MEHST=1,
    RHST=0,
    MAHST=0,
    MEAHST=1,
    RAHST=0,
    MAAHST=0,
    MHST=0;

int xp_til_lvlup=40;
int xp=0;

int gold=0;

struct P_info{
    int level;
    int defense;
    int vida;
    int classdamage;
    int intelect;
    int add_defense;
    int add_classdamage;
    int add_intelect;
    float move;
    float add_move;
};

struct E_info{
    int HP;
    int attack;
    int level;
    int type_battle;
    int type_specie;
    int rarity;
    int basexp;
};

struct Chance{
    int dodge;
    int counterattack;
    int accuracy;
    int bleeding;
};

struct P_name{ //stirngs for weapons????
    //main
    char nameMellee[20];
    char nameRange[20];
    char nameMage[20];
    char nameArmorMe[20];
    char nameArmorR[20];
    char nameArmorMa[20];
    char name[20];
    //library

    //mellee
    char me1[20];
    char me2[20];
    char me3[20];
    char me4[20];
    char me5[20];

    //ranger
    char r1[20];
    char r2[20];
    char r3[20];
    char r4[20];
    char r5[20];
    char r6[20];

    //mage
    char ma1[20];
    char ma2[20];
    char ma3[20];
    char ma4[20];
    char ma5[20];
    char ma6[20];

    //armor melee
    char mea1[20];
    char mea2[20];
    char mea3[20];
    char mea4[20];
    char mea5[20];

    //armor ranger
    char ra1[20];
    char ra2[20];
    char ra3[20];
    char ra4[20];
    char ra5[20];

    //armor mage
    char maa1[20];
    char maa2[20];
    char maa3[20];
    char maa4[20];
    char maa5[20];

    //armor move
    char m1[20];
    char m2[20];
    char m3[20];
};

struct E_special{
    char name[30];
    char HP;
    int attack;
};

struct P_info playerI;


int digitcheck(int n, int digit) { // tank u google (='v^=)

    char snum[20];
    sprintf(snum, "%d", n); //int -> digit
    char specc = digit + '0'; //specific digit -> char
    char *checkpls = strchr(snum, specc); //check if it has the digit
    if (checkpls != NULL) {
        return 1; //yes
    } else {
        return 0; //no
    }
}


void lvlup(){
    printf("\nYou leveled up! %d -> ", playerI.level);
    playerI.level++;
    gold+=5;
    printf("%d", playerI.level);
    printf("\n5 Gold recieved");
    int def=playerI.defense;
    int inte=playerI.intelect;
    int cd=playerI.classdamage;
    float mv=playerI.move;
    if(playerI.level<50){xp_til_lvlup=(int)(xp_til_lvlup*1.4);}
    if(playerI.level>50){xp_til_lvlup=(int)(xp_til_lvlup*1.6);}
    switch(playerI.level){
        case 10:
        case 20:
        case 30:
        case 40:
        case 60:
        case 70:
        case 80:
        case 90:
            playerI.defense=playerI.defense+3;
            playerI.move=playerI.move+0.01;
            playerI.classdamage=playerI.classdamage+3;
            playerI.intelect=playerI.intelect+4;
            break;
        case 25:
        case 75:
            playerI.defense=playerI.defense+5;
            playerI.move=playerI.move+0.05;
            playerI.classdamage=playerI.classdamage+5;
            playerI.intelect=playerI.intelect+6;
        break;
        case 50:
            playerI.defense=playerI.defense+10;
            playerI.move=playerI.move+0.05;
            playerI.classdamage=playerI.classdamage+10;
            playerI.intelect=playerI.intelect+10;
            break;
        case 100:
            playerI.defense=playerI.defense+10;
            playerI.move=1.0;
            playerI.classdamage=playerI.classdamage+10;
            playerI.intelect=playerI.intelect+10;
            break;
        default:
            playerI.defense=playerI.defense+1;
            playerI.move=playerI.move+0.001;
            playerI.classdamage=playerI.classdamage+1;
            playerI.intelect=playerI.intelect+2;
    }
    printf("\nDefense %d -> %d", def, playerI.defense);
    printf("\nMovement %.3f -> %.3f", mv, playerI.move);
    printf("\nClass Damage %d -> %d", cd, playerI.classdamage);
    printf("\nIntelect %d -> %d", inte, playerI.intelect);
    printf("\n%d\n", xp_til_lvlup);
}


void capa();

void menu();

void spawnpoint(float *x, float *y, float *spawnx, float *spawny, int op);

void add_cart(int invetorio_classdamage[], int invetorio_classarmor[], int option);

int batalha(struct E_info enemyI, int inventorio_classdamage[], struct Chance chance, int posicao, int inventorio_coisas[], int special, float *x, float *y, float *spawnx, float *spawny);

void craft(int inventorio_coisas[], int inventorio_classdamage[], int inventorio_classarmor[], int condition, struct P_name name);

//-----------------------------------------------------SubWorlds-----------------------------------------------------------

void goblin_camp(struct E_info enemyI, int inventorio_classdamage[], struct Chance chance, int posicao, int inventorio_coisas[], float *x, float *y, float *spawnx, float *spawny){
    int subx=1, suby=12;
    int w, z;
    char input;
    int special;
    #define H 25 //hight
    #define W 25 //width
    printf("\n");
    do{
        input = getch();
        input=tolower(input);

        switch(input){
            case 'w':
                if(!((subx == 5 && suby - 1 == 22) || (subx == 20 && suby - 1 == 22) || (subx == 12 && suby - 1 == 3))){suby--;}
                break;
            case 's':
                if(!((subx == 5 && suby + 1 == 22) || (subx == 20 && suby + 1 == 22) || (subx == 12 && suby + 1 == 3))){suby++;}
                break;
            case 'a':
                if(!((subx - 1 == 5 && suby == 22) || (subx - 1 == 20 && suby == 22) || (subx - 1 == 12 && suby == 3))){subx--;}
                break;
            case 'd':
                if(!((subx + 1 == 5 && suby == 22) || (subx + 1 == 20 && suby == 22) || (subx + 1 == 12 && suby == 3))){subx++;}
                break;
        }

        system("cls");

        for(z=0; z<=H; z++){
            for(w=0; w<=W; w++){
                if(subx==w&&suby==z){printf("\e[0;31m\e[42mP\e[0m");}
                else if(w==5&&z==22){printf("\e[0;31m\e[42mH\e[0m");} //hobgoblin 1
                else if(w==20&&z==22){printf("\e[0;31m\e[42mH\e[0m");} //hobgoblin 2
                else if(w==12&&z==3){printf("\e[1;93m\e[42mK\e[0m");} //king goblin
                else if((w==7&&z==17)||(w==7&&z==11)||(w==18&&z==17)||(w==18&&z==11)){printf("\e[0;33m\e[42m▮\e[0m");} //aDD MORE DETAILS(make more squares arounf the squares)
                else{
                    if(z==0||z==H){printf("\e[0;31m\e[42m:\e[0m");}
                    else if(w==0||w==W){printf("\e[0;31m\e[42m:\e[0m");}
                    else{printf("\e[42m \e[0m");}
                }
            }
            printf("\n");
        }
        
        if((suby>=21&&suby<=23)&&(subx>=4&&subx<=6)){ //hobgoblin 1
            printf("\nI don't like my job, but at least i have a friend here.\nAre you ready to battle? ('Y' if yes)");
            if(input=='y'){
                special=1;
                int dump=batalha(enemyI, inventorio_classdamage, chance, posicao, inventorio_coisas, special, x, y, spawnx, spawny);
                if(dump==0){
                    dump=2;
                    subx=(-2); suby=(-2);
                    spawnpoint(x, y, spawnx, spawny, dump);
                }
            }
        }
        if((suby>=21&&suby<=23)&&(subx>=19&&subx<=21)){ //hobgoblin 2
            printf("\nI love my job! But i don't have any friends...\nAre you ready to be friends? ('Y' if yes)");
            if(input=='y'){
                printf("\nHooray! Now I have 100 friends! I can get alot of gold!");
                Sleep(1000);
                printf("\nCan you give me 9999 gold? It's only 9999 gold!");
                Sleep(1000);
                printf("\nOh... You don't have that much...");
                Sleep(1000);
                printf("\nI guess you're not my friend anymore.");
                Sleep(1000);
                int dump=batalha(enemyI, inventorio_classdamage, chance, posicao, inventorio_coisas, special, x, y, spawnx, spawny);
                if(dump==0){
                    dump=2;
                    subx=(-2); suby=(-2);
                    spawnpoint(x, y, spawnx, spawny, dump);
                }
            }
        }
        if((suby>=2&&suby<=4)&&(subx>=11&&subx<=13)){ //king goblin
            printf("\nDefeat my two fellow hobgoblins to fight with me! ('Y' if yes)");
            if(input=='y'){
                special=2;
                printf("\nOh boy... You're quite a blood thirsty fella...");
                Sleep(500);
                printf("\nNow Papa Gallen will have to put you into place...");
                Sleep(500);
                int dump=batalha(enemyI, inventorio_classdamage, chance, posicao, inventorio_coisas, special, x, y, spawnx, spawny);
                if(dump==0){
                    dump=2;
                    subx=(-2); suby=(-2);
                    spawnpoint(x, y, spawnx, spawny, dump);
                }
            }
        }

    }
    while(0<=subx&&subx<=25&&0<=suby&&suby<=25);
    system("cls");

    #undef H
    #undef W
}

void village(int inventorio_classdamage[], int posicao, int inventorio_coisas[], float *x, float *y, float *spawnx, float *spawny, struct P_name name){
    int subx=1, suby=12;
    int w, z;
    char input;
    int special;
    #define H 25 //hight
    #define W 40 //width
    printf("\n");
    do{
        input = getch();
        input=tolower(input);

        switch(input){ //é mais facil fazer assim eu acho... 
            case 'w':
                if(!(
                    (subx == 7  && suby - 1 == 4 ) || (subx == 7  && suby - 1 == 6 ) || //yes those are filters to where not go
                    (subx == 7  && suby - 1 == 8 ) || (subx == 7  && suby - 1 == 10) ||
                    (subx == 7  && suby - 1 == 12) || (subx == 7  && suby - 1 == 14) ||
                    (subx == 7  && suby - 1 == 16) || (subx == 7  && suby - 1 == 18) ||
                    (subx == 7  && suby - 1 == 20) || (subx == 7  && suby - 1 == 22) ||

                    (subx == 18 && suby - 1 == 3 ) || (subx == 18 && suby - 1 == 5 ) ||
                    (subx == 18 && suby - 1 == 7 ) || (subx == 18 && suby - 1 == 9 ) ||
                    (subx == 18 && suby - 1 == 11) || (subx == 18 && suby - 1 == 13) ||
                    (subx == 18 && suby - 1 == 15) || (subx == 18 && suby - 1 == 17) ||
                    (subx == 18 && suby - 1 == 19) || (subx == 18 && suby - 1 == 21) ||
                    (subx == 18 && suby - 1 == 23)
                )){ suby--; }
                break;

            case 's':
                if(!(
                    (subx == 7  && suby + 1 == 4 ) || (subx == 7  && suby + 1 == 6 ) ||
                    (subx == 7  && suby + 1 == 8 ) || (subx == 7  && suby + 1 == 10) ||
                    (subx == 7  && suby + 1 == 12) || (subx == 7  && suby + 1 == 14) ||
                    (subx == 7  && suby + 1 == 16) || (subx == 7  && suby + 1 == 18) ||
                    (subx == 7  && suby + 1 == 20) || (subx == 7  && suby + 1 == 22) ||

                    (subx == 18 && suby + 1 == 3 ) || (subx == 18 && suby + 1 == 5 ) ||
                    (subx == 18 && suby + 1 == 7 ) || (subx == 18 && suby + 1 == 9 ) ||
                    (subx == 18 && suby + 1 == 11) || (subx == 18 && suby + 1 == 13) ||
                    (subx == 18 && suby + 1 == 15) || (subx == 18 && suby + 1 == 17) ||
                    (subx == 18 && suby + 1 == 19) || (subx == 18 && suby + 1 == 21) ||
                    (subx == 18 && suby + 1 == 23)
                )){ suby++; }
                break;

            case 'a':
                if(!(
                    (subx - 1 == 7  && suby == 4 ) || (subx - 1 == 7  && suby == 6 ) ||
                    (subx - 1 == 7  && suby == 8 ) || (subx - 1 == 7  && suby == 10) ||
                    (subx - 1 == 7  && suby == 12) || (subx - 1 == 7  && suby == 14) ||
                    (subx - 1 == 7  && suby == 16) || (subx - 1 == 7  && suby == 18) ||
                    (subx - 1 == 7  && suby == 20) || (subx - 1 == 7  && suby == 22) ||

                    (subx - 1 == 18 && suby == 3 ) || (subx - 1 == 18 && suby == 5 ) ||
                    (subx - 1 == 18 && suby == 7 ) || (subx - 1 == 18 && suby == 9 ) ||
                    (subx - 1 == 18 && suby == 11) || (subx - 1 == 18 && suby == 13) ||
                    (subx - 1 == 18 && suby == 15) || (subx - 1 == 18 && suby == 17) ||
                    (subx - 1 == 18 && suby == 19) || (subx - 1 == 18 && suby == 21) ||
                    (subx - 1 == 18 && suby == 23)
                )){ subx--; }
                break;

            case 'd':
                if(!(
                    (subx + 1 == 7  && suby == 4 ) || (subx + 1 == 7  && suby == 6 ) ||
                    (subx + 1 == 7  && suby == 8 ) || (subx + 1 == 7  && suby == 10) ||
                    (subx + 1 == 7  && suby == 12) || (subx + 1 == 7  && suby == 14) ||
                    (subx + 1 == 7  && suby == 16) || (subx + 1 == 7  && suby == 18) ||
                    (subx + 1 == 7  && suby == 20) || (subx + 1 == 7  && suby == 22) ||

                    (subx + 1 == 18 && suby == 3 ) || (subx + 1 == 18 && suby == 5 ) ||
                    (subx + 1 == 18 && suby == 7 ) || (subx + 1 == 18 && suby == 9 ) ||
                    (subx + 1 == 18 && suby == 11) || (subx + 1 == 18 && suby == 13) ||
                    (subx + 1 == 18 && suby == 15) || (subx + 1 == 18 && suby == 17) ||
                    (subx + 1 == 18 && suby == 19) || (subx + 1 == 18 && suby == 21) ||
                    (subx + 1 == 18 && suby == 23)
                )){ subx++; }
                break;
        }

        system("cls");

        for(z=0; z<=H; z++){
            for(w=0; w<=W; w++){
                if(subx==w&&suby==z){printf("\e[1;31m\e[42mP\e[0m");}
                else if(w==7&&z==22){printf("\e[1;31m\e[42mβ\e[0m");} //shop 1 (blacksmith)
                else if(w==7&&z==14){printf("\e[1;31m\e[42mμ\e[0m");} //shop 2 (library)
                else if(w==18&&z==13){printf("\e[1;33m\e[42mδ\e[0m");} //spawnpoint
                else if(w==18&&z==7){printf("\e[1;31m\e[42mΫ\e[0m");} // shop 3 (dress-shop)
                else if((w==7&&z==20)||(w==7&&z==18)||(w==7&&z==16)||(w==7&&z==12)||(w==7&&z==10)||(w==7&&z==8)||(w==7&&z==6)||(w==7&&z==4)
                ||(w==18&&z==23)||(w==18&&z==21)||(w==18&&z==19)||(w==18&&z==17)||(w==18&&z==15)||(w==18&&z==13)||(w==18&&z==11)||(w==18&&z==9)||(w==18&&z==5)||(w==18&&z==3)){printf("\e[0;31m\e[42mΔ\e[0m");} //aDD MORE DETAILS(make more squares arounf the squares)
                else{
                    if(z==0||z==H){printf("\e[1;33m\e[42m-\e[0m");}
                    else if(w==0||w==W){printf("\e[1;33m\e[42m-\e[0m");}
                    else if(w>20){printf("\e[1;32m\e[41m.\e[0m");}
                    else{printf("\e[42m \e[0m");}
                }
                /*switch (w*100+z){ 
                    case 722:
                        printf("\e[1;31m\e[42mβ\e[0m"); // shop 1 (blacksmith)      //alternativa
                        break;                                                      //trabalha juntando w e z (x e y) num int e isto server como uma condição (722 é a mesma coisa como (w==7&&z==2))
                    case 714:
                        printf("\e[1;31m\e[42mμ\e[0m"); // shop 2 (library)
                        break;
                    case 1813:
                        printf("\e[1;33m\e[42mδ\e[0m"); // spawnpoint
                        break;
                    case 1807:
                        printf("\e[1;31m\e[42mΫ\e[0m"); // shop 3 (dress-shop)
                        break;
                    case 720: case 718: case 716: case 712: case 710: case 708: case 706: case 704: case 1823: case 1821: case 1819: case 1817: case 1815: case 1811: case 1809: case 1805: case 1803:
                        printf("\e[0;31m\e[42mΔ\e[0m");
                        break;
                    default:
                        if(w==subx&&z==suby){printf("\e[1;31m\e[42mP\e[0m");}
                        else{
                            if(z==0||z==H){printf("\e[1;33m\e[42m-\e[0m");}
                            else if(w==0||w==W){printf("\e[1;33m\e[42m-\e[0m");}
                            else if(w>20){printf("\e[1;32m\e[41m.\e[0m");}
                            else{printf("\e[42m \e[0m");}
                        }
                }*/
            }
            printf("\n");
        }
        if(subx==8&&suby==22){ //blacksmith
            printf("\nThis is a blacksmith. Do you want to enter? (y)");
            if(input=='y'){
                system("cls");
                printf("\nWelcome to the blacksmith!");
                printf("\nWhat would you like to buy?");
                printf("\n- %s (30 gold)", name.mea2);
                printf("\n- %s (50 gold)", name.ra2);
                printf("\n- %s (50 gold)", name.r2);
                printf("\n(1/2/3)");
                int op;
                scanf("%d", &op);
            }
        }
        if(subx==8&&suby==14){ //library
            printf("\nThis is a library. Do you want to enter? (y)");
            if(input=='y'){
                system("cls");
                printf("\nEnjoy your read.");
                printf("\nWhat would you like to buy?");
                printf("\n- %s (45 gold)", name.ma2);
                printf("\n- %s (60 gold)", name.maa2);
                int op;
                scanf("%d", &op);
            }
        }
        if(subx==17&&suby==13){ //spawnpoint
            printf("\nThis is a Hotel. Do you want to save your spawnpoint? (y)");
            if(input=='y'){
                int op=1;
                spawnpoint(x, y, spawnx, spawny, op);
                printf("\nNEW SPAWNPOINT SET (￣o￣) . z Z");
            }
        }
        if(subx==17&&suby==7){ //dressy-shopi
            printf("\n""Dressy-Shopi"". Do you want to enter? (y)");
            if(input=='y'){
                system("cls");
                printf("\nSmile with style!");
                printf("\nWhat would you like to buy?");
                printf("\n- %s (30 gold)", name.m1);
                printf("\n- %s (9999 gold)", name.m3);
                int op;
                scanf("%d", &op);
            }
        }

    }
    while(0<=subx&&subx<=W&&0<=suby&&suby<=H);
    system("cls");

    #undef H
    #undef W
}

//------------------------------------------------File Manipulation---------------------------------------------------------
int savingfile(int invetorio_coisas[], int inventorio_classdamage[], int inventorio_classarmor[], float *x, float *y, float *spawnx, float *spawny){
    savefile=fopen("savefile.txt", "w");
    if(!savefile){perror("error saving"); return 1;}
    fprintf(savefile, 
        "level=%d\nvida=%d\ndefense=%d\nclassdamage=%d\nintelect=%d\nadd_defense=%d\nadd_classdamage=%d\nadd_intelect=%d\nmove=%f\nadd_move=%f\nx=%f\ny=%f\nspawnx=%f\nspawny=%f\nMEHST=%ld\nRHST=%ld\nMAHST=%ld\nMEAHST=%ld\nRAHST=%ld\nMAAHST=%ld\nMHST=%ld\n", 
        playerI.level, playerI.vida, playerI.defense, playerI.classdamage, playerI.intelect, playerI.add_defense, playerI.add_classdamage, playerI.add_intelect, playerI.move, playerI.add_move, *x, *y, *spawnx, *spawny, MEHST, RHST, MAHST, MEAHST, RAHST, MAAHST, MHST);
    for(int i=0; i<50; i++){
        fprintf(savefile, "%d/", invetorio_coisas[i]);
    }
    fprintf(savefile, "\n");
    for(int i=0; i<3; i++){
        fprintf(savefile, "%d/", inventorio_classdamage[i]);
    }
    fprintf(savefile, "\n");
    for(int i=0; i<4; i++){
        fprintf(savefile, "%d/", inventorio_classarmor[i]);
    }
    fclose(savefile);
    return 0;
}

int loadingfile(int invetorio_coisas[], int inventorio_classdamage[], int inventorio_classarmor[], float *x, float *y, float *spawnx, float *spawny){
    savefile=fopen("savefile.txt", "r");
    if(!savefile){perror("error loading"); return 1;}
    fscanf(savefile, 
        "level=%d\nvida=%d\ndefense=%d\nclassdamage=%d\nintelect=%d\nadd_defense=%d\nadd_classdamage=%d\nadd_intelect=%d\nmove=%f\nadd_move=%f\nx=%f\ny=%f\nspawnx=%f\nspawny=%f\nMEHST=%ld\nRHST=%ld\nMAHST=%ld\nMEAHST=%ld\nRAHST=%ld\nMAAHST=%ld\nMHST=%ld\n", 
        &playerI.level, &playerI.vida, &playerI.defense, &playerI.classdamage, &playerI.intelect, &playerI.add_defense, &playerI.add_classdamage, &playerI.add_intelect, &playerI.move, &playerI.add_move, x, y, spawnx, spawny, &MEHST, &RHST, &MAHST, &MEAHST, &RAHST, &MAAHST, &MHST);
    for(int i=0; i<50; i++){
        fscanf(savefile, "%d/", &invetorio_coisas[i]);
    }
    fscanf(savefile, "\n");
    for(int i=0; i<3; i++){
        fscanf(savefile, "%d/", &inventorio_classdamage[i]);
    }
    fscanf(savefile, "\n");
    for(int i=0; i<4; i++){
        fscanf(savefile, "%d/", &inventorio_classarmor[i]);
    }
    fclose(savefile);
    return 0;
}



//-------------------------------------------------------Battle_inventory manipulation--------------------------------------------------------------------------
void show_battle(struct P_name name, int inventorio_classdamage[], int inventorio_classarmor[]){ //call: history(function, name, inventorio_classdamage, inventorio_classarmor);
    int op;
    int i;
        char check[20]; //why not use digitcheck? 1 - it appeared more recently, 2 - ill have to deoptimize my code in order to use that

        sprintf(check, "%ld", MEHST); //mellee

        for(i=0; i<10; i++){
            switch(check[i]){
                case '1':
                    printf("\n%s", name.me1); 
                    break;
                case '2':
                    printf("\n%s", name.me2); 
                    break;
                //case ...
            }
        }

        sprintf(check, "%ld", RHST); //range

        for(i=0; i<10; i++){
            switch(check[i]){
                case '1':
                    printf("\n%s", name.r1); 
                    break;
                case '2':
                    printf("\n%s", name.r2);
                    break;
                //case ...
            }
        }

        sprintf(check, "%ld", MAHST); //mage

        for(i=0; i<10; i++){
            switch(check[i]){
                case '1':
                    printf("\n%s", name.ma1); 
                    break;
                case '2':
                    printf("\n%s", name.ma2);
                    break;
                //case ...
            }
        }

        sprintf(check, "%ld", MEAHST); //mellee armor

        for(i=0; i<10; i++){
            switch(check[i]){
                case '1':
                    printf("\n%s", name.mea1); 
                    break;
                case '2':
                    printf("\n%s", name.mea2);
                    break;
                //case ...
            }
        }

        sprintf(check, "%ld", RAHST); //range armor

        for(i=0; i<10; i++){
            switch(check[i]){
                case '1':
                    printf("\n%s", name.ra1); 
                    break;
                case '2':
                    printf("\n%s", name.ra2);
                    break;
                //case ...
            }
        }

        sprintf(check, "%ld", MAAHST);// mage armor

        for(i=0; i<10; i++){
            switch(check[i]){
                case '1':
                    printf("\n%s", name.maa1); 
                    break;
                case '2':
                    printf("\n%s", name.maa2);
                    break;
                //case ...
            }
        }

        sprintf(check, "%ld", MHST); //move armor

        for(i=0; i<10; i++){
            switch(check[i]){
                case '1':
                    printf("\n%s", name.m1); 
                    break;
                case '2':
                    printf("\n%s", name.m2);
                    break;
                //case ...
            }
        }
}

void equip_battle(struct P_name name, int inventorio_classdamage[], int inventorio_classarmor[]){
    //change weapon/armor------------------------------------------
    int op;
    int i;
    printf("\nChange weapon/armor(1/2)\n");
    scanf("%d", &op);
        char check[20];
        //-------------------------------FILTER???????------
        if (op==1){//-------------------------------------------//change weapon
            int subop;
            int subsubop;
            int one=0,
                two=0,
                tree=0,
                four=0,
                five=0;
            printf("\nChoose class (1-Melle/2-Ranger/3-Mage)\n");
            scanf("%d", &subop);
            printf("What weapon you'll be choosing?");
            switch(subop){                     //filter 1 --- so in the first filter it will show every weapon of type [chosen] to let you choose nad then in the seconf filter it will see if you chosed corectly, if you dont have the weapon you will not equip it.
                case 1:
                    sprintf(check, "%ld", MEHST);
                    for(i=0; i<2; i++){           //mellee
                        switch(check[i]){
                            case '1':
                                one=1;
                                printf("\n1 - %s", name.me1); //printf("\nn - %s", name.);
                                break;
                            case '2':
                                two=2;
                                printf("\n2 - %s", name.me2);
                                break;
                            //case ...
                            default:printf("\nError\n");
                        }
                    }
                    printf("\n");
                    scanf("%d", &subsubop);
                    if((subsubop==one||subsubop==two)&&subsubop!=0/*...*/){ //filter 2
                        inventorio_classdamage[subop-1]=subsubop;
                    }
                    else{printf("\nU don hav dat\n");}
                    break;
                case 2:
                    sprintf(check, "%ld", RHST);
                    for(i=0; i<10; i++){           //range
                            switch(check[i]){
                                case '1':
                                    one=1;
                                    printf("\n1 - %s", name.r1);
                                    break;
                                case '2':
                                    two=2;
                                    printf("\n2 - %s", name.r1);
                                    break;
                                //case ...
                            }
                    }
                    printf("\n");
                    scanf("%d", &subsubop);
                    if((subsubop==one||subsubop==two)&&subsubop!=0/*...*/){ //filter 2
                        inventorio_classdamage[subop-1]=subsubop;
                    }
                    break;
                case 3:
                    sprintf(check, "%ld", MAHST);
                    for(i=0; i<10; i++){           //mage
                            switch(check[i]){
                                case '1':
                                    one=1;
                                    printf("\n1 - %s", name.ma1);
                                    break;
                                case '2':
                                    two=2;
                                    printf("\n2 - %s", name.ma2);
                                    break;
                                //case ...
                            }
                    }
                    printf("\n");
                    scanf("%d", &subsubop);
                    if((subsubop==one||subsubop==two)&&subsubop!=0/*...*/){ //filter 2
                        inventorio_classdamage[subop-1]=subsubop;
                    }
                    break;
            }



        }
        if(op==2){//------------------------------------------//change armor
            int subop, subsubop;
            int one,
                two,
                tree,
                four,
                five;
            printf("\nChoose class (1-Melle/2-Ranger/3-Mage)\n");
            scanf("%d", &subop);
            printf("What armor you'll be choosing?");
            switch(subop){
                case 1:
                    sprintf(check, "%ld", MEAHST);
                    for(i=0; i<2; i++){           //mellee
                        switch(check[i]){
                            case '1':
                                one=1;
                                printf("\n1 - %s", name.mea1);
                                break;
                            case '2':
                                two=2;
                                printf("\n2 - %s", name.mea2);
                                break;
                            //case ...
                        }
                    }
                    printf("\n");
                    scanf("%d", &subsubop);
                    if((subsubop==one||subsubop==two)&&subsubop!=0/*...*/){ //filter 2
                        inventorio_classarmor[subop-1]=subsubop;
                    }
                    else{printf("\nU don hav dat\n");}
                    add_cart(inventorio_classdamage, inventorio_classarmor, subop);
                    break;
                case 2:
                    sprintf(check, "%ld", RAHST);
                    for(i=0; i<10; i++){           //range
                                switch(check[i]){
                                    case '1':
                                        one=1;
                                        printf("\n1 - %s", name.ra1);
                                        break;
                                    case '2':
                                        two=2;
                                        printf("\n2 - %s", name.ra2);
                                        break;
                                    //case ...
                                }
                    }
                    printf("\n");
                    scanf("%d", &subsubop);
                    if((subsubop==one||subsubop==two)&&subsubop!=0/*...*/){ //filter 2
                        inventorio_classarmor[subop-1]=subsubop;
                    }
                    add_cart(inventorio_classdamage, inventorio_classarmor, subop);
                    break;
                case 3:
                    sprintf(check, "%ld", MAAHST);
                    for(i=0; i<10; i++){           //mage
                            switch(check[i]){
                                case '1':
                                    one=1;
                                    printf("\n1 - %s", name.maa1);
                                    break;
                                case '2':
                                    two=2;
                                    printf("\n2 - %s", name.maa2);
                                    break;
                                //case ...
                            }
                    }
                    printf("\n");
                    scanf("%d", &subsubop);
                    if((subsubop==one||subsubop==two)&&subsubop!=0/*...*/){ //filter 2
                        inventorio_classarmor[subop-1]=subsubop;
                    }
                    add_cart(inventorio_classdamage, inventorio_classarmor, subop);
                    break;
                case 4:
                    sprintf(check, "%ld", MHST);
                    for(i=0; i<10; i++){           //move
                            switch(check[i]){
                                case '1':
                                    one=1;
                                    printf("\n1 - %s", name.m1);
                                    break;
                                case '2':
                                    two=2;
                                    printf("\n2 - %s", name.m2);
                                    break;
                                //case ...
                            }
                    }
                    add_cart(inventorio_classdamage, inventorio_classarmor, subop);
                    printf("\n");
                    scanf("%d", &subsubop);
                    if((subsubop==one||subsubop==two)&&subsubop!=0/*...*/){ //filter 2
                        inventorio_classarmor[subop-1]=subsubop;
                    }
                    break;
            }
        }
}

//----------------------------------------------Inventory Manipulation--------------------------------------------------- 
void item_id_check(int posicao){
    switch (posicao) {
    case 0:
        printf("..............");
        break;
    case 1:
        printf("Gel");
        break;
    case 2:
        printf("Golden Gel");
        break;
    case 3:
        printf("Goblin Ears");
        break;
    case 4:
        printf("Goldin Ears");
        break;
    case 5:
        printf("Wolf Hide");
        break;
    case 6:
        printf("Golden Hide");
        break;
    case 7:
        printf("Spike");
        break;
    case 8:
        printf("Golden Spike");
        break;
    case 9:
        printf("Venomous Stinger");
        break;
    case 10:
        printf("Golden Stinger");
        break;
    case 11:
        printf("Antlion Claw");
        break;
    case 12:
        printf("Golden Claw");
        break;
    case 13:
        printf("Lizard Skin");
        break;
    case 14:
        printf("Gold Skin");
        break;
    case 15:
        printf("dm");
        break;
    case 16:
        printf("dmg");
        break;
    case 17:
        printf("Orc");
        break;
    case 18:
        printf("GOrc");
        break;
    case 19:
        printf("dbm1");
        break;
    case 20:
        printf("dbm1g");
        break;
    case 21:
        printf("dbm2");
        break;
    case 22:
        printf("dbm2g");
        break;
    case 23:
        printf("snow elf");
        break;
    case 24:
        printf("gelf");
        break;
    case 25:
        printf("Ice Gel");
        break;
    case 26:
        printf("spaceholder");
        break;
    case 27:
        printf("mr");
        break;
    case 28:
        printf("mrg");
        break;
    case 29:
        printf("dr");
        break;
    case 30:
        printf("drg");
        break;
    case 31:
        printf("mage elf");
        break;
    case 32:
        printf("purple elf");
        break;
    case 33:
        printf("sm1");
        break;
    case 34:
        printf("smg1");
        break;
    case 35:
        printf("mm");
        break;
    case 36:
        printf("mmg");
        break;
    case 37:
        printf("dm");
        break;
    case 38:
        printf("dmg");
        break;
    case 39:
        printf("<space_holder>");
        break;
    case 40:
        printf("<space_holder>");
        break;
    case 41:
        printf("<space_holder>");
        break;
    case 42:
        printf("<space_holder>");
        break;
    case 43:
        printf("<space_holder>");
        break;
    case 44:
        printf("<space_holder>");
        break;
    case 45:
        printf("<space_holder>");
        break;
    case 46:
        printf("<space_holder>");
        break;
    case 47:
        printf("<space_holder>");
        break;
    case 48:
        printf("<space_holder>");
        break;
    case 49:
        printf("<space_holder>");
        break;
    default:
        printf("Fora do intervalo");
        break;
    }
}

/*
void inventario_damage_check(int inventorio_classdamage[], int inventorio_classarmor[], struct P_name *name){ //to call: inventario_damage_check(inventorio_classdamage, inventorio_classarmor, &name);
    int i=0;
    do{
        if(inventorio_classdamage[0]!=0){
            switch(inventorio_classdamage[i]){
            case 1:
                strcpy(name->nameMellee, "Ass Destroyer");   //IGNORAR ESTA PARTE DO CÓDIGO 
                break;
            case 2:
                strcpy(name->nameMellee, "Goblin Club");
                break;
            }
        }
        if(inventorio_classarmor[0]!=0){
            switch(inventorio_classarmor[i]){
            case 1:
                strcpy(name->nameArmorMe, "Ass Cheeks");
                break;
            case 2:
                strcpy(name->nameArmorMe, "spaceholder");
                break;
            }
        }
        if(inventorio_classdamage[1]!=0){
            switch(inventorio_classdamage[i]){
            case 1:
                strcpy(name->nameRange, "Goblin Bow");
                break;
            case 2:
                strcpy(name->nameRange, "spaceholder");
                break;
            }
        }
        if(inventorio_classarmor[1]!=0){
            switch(inventorio_classarmor[i]){
            case 1:
                strcpy(name->nameArmorR, "ssfdsfds");
                break;
            case 2:
                strcpy(name->nameArmorR, "spaceholder");
                break;
            }
        }
        if(inventorio_classdamage[2]!=0){
            switch(inventorio_classdamage[i]){
            case 1:
                strcpy(name->nameMage, "Gel Wand");
                break;
            case 2:
                strcpy(name->nameMage, "spaceholder");
                break;
            }
        }
        if(inventorio_classarmor[2]!=0){
            switch(inventorio_classarmor[i]){
            case 1:
                strcpy(name->nameArmorMa, "Gel Robe");
                break;
            case 2:
                strcpy(name->nameArmorMa, "spaceholder");
                break;
            }
        }
        i++;
    }
    while(i!=3);
}
*/

void inventario_show(int inventorio_coisas[], int posicao, struct P_name name, int inventorio_classdamage[], int inventorio_classarmor[]){
    printf("Inventory:\n");
    do{
        if(inventorio_coisas[posicao]>0){
            printf("\n%d ", inventorio_coisas[posicao]);
            item_id_check(posicao);
            printf("\n");
        }
        posicao++;
    }
    while(posicao<50);
    show_battle(name, inventorio_classdamage, inventorio_classarmor);
    printf("\n");
}

void inventario_add(int inventorio_coisas[], int posicao, int quantity){
    inventorio_coisas[posicao]=quantity;
}

void craft(int inventorio_coisas[], int inventorio_classdamage[], int inventorio_classarmor[], int condition, struct P_name name){
    int op=0;
    int quant=1;
    switch(condition){
        case 0: //hand craft
            printf("\nYou can craft:");
            if(inventorio_coisas[1]>=2&&MEHST>=1){ //Gel Wand craft
                printf("\n1 - %s (2 Gel + 1 %s)", name.ma1, name.me1);
            }
            if(inventorio_coisas[1]>=5&&MEAHST>=1){ //Robe Gel
                printf("\n2 - %s (5 Gel + 1 %s)", name.maa1, name.mea1);
            }
            if(inventorio_coisas[5]>=4){ //Wolf Hide Jacket
                printf("\n3 - %s (4 Wolf Hide)", name.ra1);
            }
            scanf("%d", &op);
            switch(op){
                case 1:// Gel wand
                    if((digitcheck(MAHST, 1))==0){MAHST+=1; inventorio_coisas[1]-=2; MEHST-1; printf("\nCrafted %s", name.ma1); inventorio_coisas[2]-=2;}
                    else{printf("no.");}
                break;
                case 2: // Robe Gel
                    if(!(digitcheck(MAAHST, 1))){MAAHST+=1; inventorio_coisas[1]-=5; MEAHST-1; printf("\nCrafted %s", name.maa1);}
                    else{printf("no.");}
                break;
                case 3: // Wolf Hide Jacket
                    if(!(digitcheck(RAHST, 1))){RAHST+=1; inventorio_coisas[5]-=4; printf("\nCrafted %s", name.ra1);}
                    else{printf("no.");}
                break;
            }   
        break;
    }
}










//-----------------------------------------------------Battle-------------------------------------------------------------
int damage_function(struct Chance chance, int inventorio_batalha[], int foption); //damage function call


void add_cart(int invetorio_classdamage[], int invetorio_classarmor[], int option){//to call: add_cart(invetorio_classdamage, invetorio_classarmor, acessory, &playerI, op);
    int i=option; //indicates a class of armor used.
    int o; //indicates which armor is being used.
    if(i==1){
            switch (invetorio_classarmor[0]){
                case 1:
                    playerI.add_defense=1;
                    o=1;
                    break;
                case 2:
                    playerI.add_classdamage=3;
                    playerI.add_defense=2;
                    o=2;
                    break;
            }
    }
    if(i==2){
            switch (invetorio_classarmor[1]){
                case 1:
                    playerI.add_classdamage=2;
                    playerI.add_defense=3;
                    o=1;
                    break;
            } 
    }
    if(i==3){
            switch (invetorio_classarmor[2]){
                case 1:
                    playerI.add_classdamage=1;
                    playerI.add_defense=3;
                    playerI.add_intelect=2;
                    o=1;
                    break;
            }
    }
    if(i==4){
            switch (invetorio_classarmor[3]){
                case 1:
                    playerI.add_defense=2;
                    playerI.add_move=0.005;
                    o=1;
                    break;
            }
    }
    /*if(acessory[0]==1){  //ainda nao implementado
        //caracteristics 1
    }
    if(acessory[1]==1){ 
        //caracteristic 2
    }
    if(acessory[2]==1){ 
        //...
    }
    if(acessory[3]==1){ 
        
    }
    if(acessory[4]==1){ 
        
    }
    if(acessory[5]==1){ 
        
    }
    if(acessory[6]==1){ 
        
    }
    if(acessory[7]==1){ 
        
    }
    if(acessory[8]==1){ 
        
    }
    if(acessory[9]==1){ 
        
    }*/
}

int batalha(struct E_info enemyI, int inventorio_classdamage[], struct Chance chance, int posicao, int inventorio_coisas[], int special, float *x, float *y, float *spawnx, float *spawny){ // struct P_info playerI, int inventorio_batalha[]
    float enemyID;
    int quantity;
    int options=0;
    int ohyeah; //incredible drop chance
    int check=1;
    int win=0;
    enemyID = (enemyI.type_battle * 1000) + (enemyI.type_specie * 10) + (enemyI.rarity/100.00);
    printf("\n%.2f\n", enemyID);
    enemyID=(int)enemyID;
    printf("\n%.0f\n", enemyID);
    if(special==0){printf("You've been attacked by ");}
    do{
        if(special==1){//hobgoblin 1 and 2
            printf("\nYou started a battle with a hobgoblin!");
            enemyI.level=15; enemyI.HP=10; enemyI.attack=3; posicao=0; enemyI.basexp=30; //no special drop
        }
        else if(special==2){ //goblin king - San Vukonk
            printf("\nYou approached San Vukonk!");
            enemyI.level=20; enemyI.HP=30; enemyI.attack=5; posicao=0; enemyI.basexp=60; //special drop - Rii Jingle Bang
            if(win==1){printf("\nVukonk dropped Rii Jingle Bang\n"); inventorio_classdamage[0]=3; RHST+=300;}
        }
        else{
            if(win==0){
                switch ((int)enemyID) {
                // Starting Zone
                case 1110: printf("green slime\n"); enemyI.HP=5; enemyI.attack=1; posicao=1; enemyI.basexp=5; break;
                case 1111: printf("golden starting slime\n"); enemyI.HP=10; enemyI.attack=2; posicao=2; enemyI.basexp=50; break;
                case 1120: printf("goblin warrior\n"); enemyI.HP=7; enemyI.attack=2; posicao=3; enemyI.basexp=7; break;
                case 1121: printf("golden goblin warrior\n"); enemyI.HP=10; enemyI.attack=2; posicao=4; enemyI.basexp=70; break;
                case 1130: printf("hungry wolf\n"); enemyI.HP=7; enemyI.attack=1; posicao=5; enemyI.basexp=7; break;
                case 1131: printf("golden wolf\n"); enemyI.HP=20; enemyI.attack=3; posicao=6; enemyI.basexp=100; break;
                case 1140: printf("spikey\n"); enemyI.HP=5; enemyI.attack=1; posicao=7; enemyI.basexp=6; break;
                case 1141: printf("golden spikey\n"); enemyI.HP=30; enemyI.attack=1; posicao=8; enemyI.basexp=60; break;

                // Plains
                case 1210: printf("blue slime\n"); enemyI.HP=5; enemyI.attack=1; posicao=1; enemyI.basexp=5; break;
                case 1211: printf("golden plains slime\n"); enemyI.HP=10; enemyI.attack=2; posicao=2; enemyI.basexp=50; break;
                case 1220: printf("goblin\n"); enemyI.HP=5; enemyI.attack=1; posicao=3; enemyI.basexp=6; break;
                case 1221: printf("golden goblin\n"); enemyI.HP=10; enemyI.attack=5; posicao=4; enemyI.basexp=100; break;

                // Desert
                case 1310: printf("yellow slime\n"); enemyI.HP=10; enemyI.attack=3; posicao=1; enemyI.basexp=8; break;
                case 1311: printf("golden desert slime\n"); enemyI.HP=20; enemyI.attack=6; posicao=2; enemyI.basexp=80; break;
                case 1320: printf("scorpion\n"); enemyI.HP=15; enemyI.attack=5; posicao=9; enemyI.basexp=7; break;
                case 1321: printf("golden scorpion\n"); enemyI.HP=30; enemyI.attack=15; posicao=10; enemyI.basexp=70; break;
                case 1330: printf("antlion\n"); enemyI.HP=15; enemyI.attack=4; posicao=11; enemyI.basexp=10; break;
                case 1331: printf("golden antlion\n"); enemyI.HP=1; enemyI.attack=1; posicao=12; enemyI.basexp=100; break;

                // Mountains
                case 1510: printf("monstrous lizard\n"); enemyI.HP=20; enemyI.attack=5; posicao=13; enemyI.basexp=10; break;
                case 1511: printf("golden lizard\n"); enemyI.HP=40; enemyI.attack=10; posicao=14; enemyI.basexp=100; break;

                // Demon Side
                case 1610: printf("dm\n"); enemyI.HP=50; enemyI.attack=20; posicao=15; enemyI.basexp=10; break;
                case 1611: printf("dmg\n"); enemyI.HP=80; enemyI.attack=30; posicao=16; enemyI.basexp=100; break;

                // Desert
                case 2310: printf("orc\n"); enemyI.HP=20; enemyI.attack=10; posicao=17; enemyI.basexp=7; break;
                case 2311: printf("golden orc\n"); enemyI.HP=30; enemyI.attack=20; posicao=18; enemyI.basexp=70; break;
                case 2320: printf("dbm1\n"); enemyI.HP=30; enemyI.attack=5; posicao=19; enemyI.basexp=10; break;
                case 2321: printf("dbm1g\n"); enemyI.HP=30; enemyI.attack=5; posicao=20; enemyI.basexp=10; break;
                case 2330: printf("dbm2\n"); enemyI.HP=30; enemyI.attack=5; posicao=21; enemyI.basexp=10; break;
                case 2331: printf("dbm2g\n"); enemyI.HP=30; enemyI.attack=5; posicao=22; enemyI.basexp=10; break;

                // Mountains
                case 2510: printf("rock golem\n"); enemyI.HP=30; enemyI.attack=5; posicao=0; enemyI.basexp=12; break;
                case 2511: printf("gold golem\n"); enemyI.HP=30; enemyI.attack=5; posicao=0; enemyI.basexp=120; break;

                // Starting Zone
                case 3110: printf("bow goblin\n"); enemyI.HP=5; enemyI.attack=2; posicao=3; enemyI.basexp=7; break;
                case 3111: printf("golden bow goblin\n"); enemyI.HP=10; enemyI.attack=5; posicao=4; enemyI.basexp=70; break;
                case 3120: printf("exploding spikey\n"); enemyI.HP=10; enemyI.attack=0; posicao=7; enemyI.basexp=6; break; //time enemy
                case 3121: printf("golden exploding spikey\n"); enemyI.HP=20; enemyI.attack=0; posicao=8; enemyI.basexp=60; break; //time enemy
                case 3130: printf("bow goblin\n"); enemyI.HP=5; enemyI.attack=2; posicao=3; enemyI.basexp=7; break;
                case 3131: printf("golden bow goblin\n"); enemyI.HP=10; enemyI.attack=5; posicao=4; enemyI.basexp=70; break;
                case 3140: printf("exploding spikey\n"); enemyI.HP=10; enemyI.attack=0; posicao=7; enemyI.basexp=6; break; //time enemy
                case 3141: printf("golden exploding spikey\n"); enemyI.HP=20; enemyI.attack=0; posicao=8; enemyI.basexp=60; break; //time enemy

                // Icy Forest
                case 3410: printf("snow elf\n"); enemyI.HP=30; enemyI.attack=10; posicao=23; enemyI.basexp=10; break;
                case 3411: printf("golden elf\n"); enemyI.HP=25; enemyI.attack=25; posicao=24; enemyI.basexp=100; break; 
                case 3420: printf("Ice Spike Slime\n"); enemyI.HP=25; enemyI.attack=10; posicao=25; enemyI.basexp=8; break;
                case 3421: printf("Golden Spike Slime\n"); enemyI.HP=50; enemyI.attack=20; posicao=(rand() % 2 == 0) ? 2 : 8; enemyI.basexp=80; break;

                // Mountains
                case 3510: printf("mr\n"); enemyI.HP=30; enemyI.attack=5; posicao=27; enemyI.basexp=10; break;
                case 3511: printf("mrg\n"); enemyI.HP=30; enemyI.attack=5; posicao=28; enemyI.basexp=10; break;

                // Demon Side
                case 3610: printf("dr\n"); enemyI.HP=30; enemyI.attack=5; posicao=29; enemyI.basexp=10;  break;
                case 3611: printf("drg\n"); enemyI.HP=30; enemyI.attack=5; posicao=30; enemyI.basexp=10; break;

                // Icy Forest
                case 4410: printf("mage elf\n"); enemyI.HP=20; enemyI.attack=15; posicao=31; enemyI.basexp=10; break;
                case 4411: printf("purple elf\n"); enemyI.HP=100; enemyI.attack=50; posicao=32; enemyI.basexp=500; break;
                case 4420: printf("sm1\n"); enemyI.HP=30; enemyI.attack=5; posicao=33; enemyI.basexp=10; break;
                case 4421: printf("sm1g\n"); enemyI.HP=30; enemyI.attack=5; posicao=34; enemyI.basexp=10; break;

                // Mountains
                case 4510: printf("mm\n"); enemyI.HP=30; enemyI.attack=5; posicao=35; enemyI.basexp=10; break;
                case 4511: printf("mmg\n"); enemyI.HP=30; enemyI.attack=5; posicao=36; enemyI.basexp=10; break;

                // Demon Side
                case 4610: printf("dm\n"); enemyI.HP=30; enemyI.attack=5; posicao=37; enemyI.basexp=10; break;
                case 4611: printf("dmg\n"); enemyI.HP=30; enemyI.attack=5; posicao=38; enemyI.basexp=10; break;


                // Cfsssdsfdssdsfsdfdsfdsfdssdfsdsdfsdfdssdfssdfsdsdfsdfsdsdfssdsfdsfdsfdsfdsdsf
                default:
                    printf("Unknown entity ID\n");
                    break;
                }
            }
            if(win==1){
                switch ((int)enemyID) { //battle items drop chance
                // Starting Zone
                case 1110: break;
                case 1111: ohyeah=rand()%100+1; break;
                case 1120: ohyeah=rand()%4; if(ohyeah==1&&(digitcheck(MEHST, 2)==0)){printf("\nGoblin Bat\n"); inventorio_classdamage[0]=2; MEHST+=20;} break;
                case 1121: if((digitcheck(MEHST, 2)==0)){printf("\nGoblin Bat\n"); inventorio_classdamage[0]=2; MEHST+=20;} break;
                case 1130: break;
                case 1131: break;
                case 1140: break;
                case 1141: break;

                // Plains
                case 1210: break;
                case 1211: break;
                case 1220: break;
                case 1221: break;

                // Desert
                case 1310: break;
                case 1311: break;
                case 1320: break;
                case 1321: break;
                case 1330: break;
                case 1331: break;

                // Mountains
                case 1510: break;
                case 1511: break;

                // Demon Side
                case 1610: break;
                case 1611: break;

                // Desert
                case 2310: break;
                case 2311: break;
                case 2320: break;
                case 2321: break;
                case 2330: break;
                case 2331: break;

                // Mountains
                case 2510: break;
                case 2511: break;

                // Starting Zone
                case 3110: ohyeah=rand()%4; if(ohyeah==1&&(digitcheck(RHST, 1)==0)){printf("\nGoblin Bow\n"); inventorio_classdamage[1]=1; RHST+=1;} break;
                case 3111: if((digitcheck(RHST, 1)==0)){printf("\nGoblin Bow\n"); inventorio_classdamage[1]=1; RHST+=1;} break;
                case 3120: break; //time enemy
                case 3121: break; //time enemy
                case 3130: ohyeah=rand()%4; if(ohyeah==1&&(digitcheck(RHST, 1)==0)){printf("\nGoblin Bow\n"); inventorio_classdamage[1]=1; RHST+=1;} break;
                case 3131: if((digitcheck(RHST, 1)==0)){printf("\nGoblin Bow\n"); inventorio_classdamage[1]=1; RHST+=1;} break;
                case 3140: break; //time enemy
                case 3141: break; //time enemy

                // Icy Forest
                case 3410: ohyeah=rand()%4; if(ohyeah==1&&(digitcheck(RHST, 4)==0)){printf("\nIce Bow\n"); inventorio_classdamage[1]=4; RHST+=4000;} break;
                case 3411: if((digitcheck(RHST, 6)==0)){printf("\np-Ice Bow 4000\n")/*definition: It's Yellow*/; inventorio_classdamage[1]=6; RHST+=600000;} break; 
                case 3420: break;
                case 3421: break;

                // Mountains
                case 3510: break;
                case 3511: break;

                // Demon Side
                case 3610: break;
                case 3611: break;

                // Icy Forest
                case 4410: ohyeah=rand()%5; if(ohyeah==1&&(digitcheck(MAHST, 4)==0)){printf("\nElf Arm\n");/* His name is Jeff */ inventorio_classdamage[2]=4; MAHST+=4000;}  break;
                case 4411: if((digitcheck(MAHST, 1)==6)){printf("\nPurple EyeBall\n")/*His name is Cris*/; inventorio_classdamage[1]=6; MAHST+=600000;} break;
                case 4420: break;
                case 4421: break;

                // Mountains
                case 4510: break;
                case 4511: break;

                // Demon Side
                case 4610: break;
                case 4611: break;


                // Cfsssdsfdssdsfsdfdsfdsfdssdfsdsdfsdfdssdfssdfsdsdfsdfsdsdfssdsfdsfdsfdsfdsdsf
                default:
                    printf("Unknown entity ID\n");
                    break;
                }
            }
            
        }
        if(win==1){check=0;}
        else{
            //check player stats
            /*player clone*/   int defense=playerI.defense+playerI.add_defense;
            /*p attack clone*/ int p_attack=damage_function(chance, inventorio_classdamage, options);
            /*enemy clone*/    int HP=((enemyI.level/20.0)*enemyI.HP)+enemyI.HP;
            /*e attack clone*/ int e_attack=((enemyI.level/30.0)*enemyI.attack)+enemyI.attack;
            /*mob xp*/         int mobxp;
            if(enemyI.level<8){mobxp=enemyI.basexp+(enemyI.basexp*(enemyI.level/2));}
            else{mobxp=enemyI.basexp+(enemyI.basexp*(enemyI.level/5));}
            printf("----------------------------------------"); //40
            printf("\nEnemy stats: Level: %d, HP: %d, Attack: %d", enemyI.level, enemyI.HP, e_attack);
            printf("\nPlayer stats: Level: %d, Defense: %d, Attack: %d", playerI.level, defense, p_attack);
            char option;
            int end=0;
            int q=0;
            do{
                if(q>0){system("cls");}
                printf("\n----------------------------------------");
                printf("\nEnemy: %d HP", HP);
                printf("\nPlayer: %d defense", defense);
                printf("\n----------------------------------------");
                Sleep(500);
                printf("\nYour turn!");
                printf("\nAtack (t)/Action (f)/Run (r)\n");
                scanf(" %c", &option);
                option=tolower(option);
                printf("----------------------------------------");
                Sleep(1000);
                if(option == 't'){
                    HP=HP-p_attack;
                    printf("\nYour attack hit!");
                    printf("\n-%d HP", p_attack);
                    printf("\n----------------------------------------");
                    Sleep(1000);
                } // create hit chance that depends from class
                if(option == 'f'){
                    printf("\nConsume/Use/Change Class\n");
                    scanf("%d", &options);
                    printf("\n----------------------------------------");
                    if(options==1){options=1;}
                    if(options==2){options=2;}
                    if(options==3){options=3; p_attack=damage_function(chance, inventorio_classdamage, options);}
                    Sleep(1000);
                }
                if(option == 'r'){
                    int chance = rand()%2+1;
                    if(chance == 1){printf("\n\nYou escaped!\n"); end=1; check=0;}
                    else{printf("\n\nYou failed to escape!\n");}
                    Sleep(1000);
                }
                if(HP<=0){
                    printf("\nYou have defeated the enemy!");
                    Sleep(1000);
                    end=1;
                    win=1;
                    if(posicao>0){
                        quantity = rand()%3+1;
                        inventario_add(inventorio_coisas, posicao, quantity);//possible error ---> posicao changed
                        printf("\nEnemy have droped %d ", quantity);
                        item_id_check(posicao);
                    }
                    printf("\nYou've recieved %d xp", mobxp);
                    for(int i=0; i<mobxp; i++){
                        xp=xp+(mobxp/mobxp);
                        if(xp>=xp_til_lvlup){
                            lvlup(playerI);
                        }
                    }
                    printf("\nYou've recieved 5 gold");
                    gold+=5;
                    Sleep(1000);
                }
                if(end==0){
                        printf("\nEnemy's turn!");
                        printf("\n----------------------------------------");
                        Sleep(1000);
                        if(defense>0){
                            defense=defense-e_attack; //fazer um dodge chance
                            printf("\n-%d defense", e_attack);
                            if(defense<=0){printf("\nYour defense is down! One hit left!");}
                        }
                        else{
                            printf("\nYou've been hit... ");
                            int chance = rand()%3+1;
                            if(chance==1){
                                printf("But you survived!");
                            }
                            else{
                                printf("And you died...\nSending back to the spawn point");
                                end=1;
                                check=0;
                                option=2;
                                return 0;
                            }
                        }
                        Sleep(1000);
                }
                q++;
            }
            while(end==0);
        }
        
    }
    while(check==1);
    return 1;
}

int damage_function (struct Chance chance, int inventorio_batalha[], int foption){
    int p_attack;
    int option;
    int damage;
    if(foption==3){
        printf("\nWhich class you'll be using?\n(1 - mellee, 2 - ranger, 3 - mage)\n");
        scanf("%d", &option);
    }
    else{
        if(inventorio_batalha[0]!=0){
            if(inventorio_batalha[1]!=0){
                if(inventorio_batalha[2]!=0){
                    printf("\nWhich class you'll be using?\n(1 - mellee, 2 - ranger, 3 - mage)\n");
                    scanf("%d", &option);
                }
                else{
                    printf("\nWhich class you'll be using?\n(1 - mellee, 2 - ranger)\n");
                    scanf("%d", &option);
                }
            }
            else{
                printf("\nYour class - Mellee\n");
                option = 1;
            }
        }
        else if(inventorio_batalha[1]!=0){
                if(inventorio_batalha[2]!=0){
                    printf("\nWhich class you'll be using?\n(2 - ranger, 3 - mage)\n");
                    scanf("%d", &option);
                }
                else{
                    printf("\nYour class - Ranger\n");
                    option = 2;
                }
        }
        else{
            printf("\nYour class - Mage\n");
            option = 3;
        }
    }
    if(option==1){
        switch (inventorio_batalha[0]){ //caratceristics mellee
        case 1:
            damage=1;
            break;
        case 2:
            damage=2;
            break;
        case 3:
            damage=5;
            break;
        case 4:
            break;
        case 5:
            break;
        }
        p_attack=damage+playerI.classdamage+playerI.add_classdamage;
    }
    if(option==2){
        switch (inventorio_batalha[1]){ //caratceristics ranger
        case 1:
            damage=3;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            damage=10;
            break;
        case 5:
            break;
        case 6:
            damage=20;
            break;
        }
        p_attack=damage+playerI.classdamage+playerI.add_classdamage;
    }
    if(option==3){
    switch (inventorio_batalha[2]){ //caratceristics mage
        case 1:
            damage=1;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            damage=7;
            break;
        case 5:
            break;
        case 6:
            damage=15;
            break;
        }
        p_attack=(damage+playerI.classdamage)*((playerI.intelect/100)+1)+playerI.add_classdamage;
    }
    return p_attack;
}




//---------------------------------------------------------Map----------------------------------------------
void mapCriar (float x, float y){
    int z, r; //alternativas para x e y
    for(r=0; r<hight; r++){
        for(z=0; z<width; z++){
            if(z==(int)x&&r==(int)y){ //usei (int) para curtar a parte decimal, porque eu quero que um quadrado (neste caso ponto) tiha a raz�o de 10 em 1 entre posi��o, ou seja, 10 posi��es num quadrado
                switch(r){ //rendering P
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
                    printf("\e[1;32mP\e[0m"); //Zona final
                    break;
                case 13:
                case 14:
                    printf("\e[0;31m\e[47mP\e[0m"); //Zona montanhas
                    break;
                case 15:
                    if(z<=30){printf("\e[1;91m\e[43mP\e[0m");}  //zona desserta
                    if(z>30&&z<69){printf("\e[1;31m\e[42mP\e[0m");} //zona verde
                    if(z>=69){printf("\e[1;91m\e[47mP\e[0m");}  //zona de neve
                    break;
                case 16:
                    if(z<=29){printf("\e[1;91m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>29&&z<71){printf("\e[1;31m\e[42mP\e[0m");} //zona humana
                    if(z>=71){printf("\e[1;91m\e[47mP\e[0m");}  //zona dos morto
                    break;
                case 17:
                    if(z<=28){printf("\e[1;91m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>28&&z<72){printf("\e[1;31m\e[42mP\e[0m");} //zona humana
                    if(z>=72){printf("\e[1;91m\e[47mP\e[0m");}  //zona dos mortos
                    break;
                case 18:
                    if(z<=27){printf("\e[1;91m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>27&&z<73){printf("\e[1;31m\e[42mP\e[0m");} //zona humana
                    if(z>=73){printf("\e[1;91m\e[47mP\e[0m");}  //zona dos mortos
                    break;
                case 19:
                    if(z<=26){printf("\e[1;91m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>26&&z<74){printf("\e[1;31m\e[42mP\e[0m");} //zona humana
                    if(z>=74){printf("\e[1;91m\e[47mP\e[0m");}  //zona dos mortos
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
                    if(z<=25){printf("\e[1;91m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>25&&z<75){printf("\e[1;31m\e[42mP\e[0m");} //zona humana
                    if(z>=75){printf("\e[1;91m\e[47mP\e[0m");}  //zona dos mortos
                    break;
                case 33:
                    if(z<=26){printf("\e[1;91m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>26&&z<74){printf("\e[1;31m\e[42mP\e[0m");} //zona humana
                    if(z>=74){printf("\e[1;91m\e[47mP\e[0m");}  //zona dos mortos
                    break;
                case 34:
                    if(z<=27){printf("\e[1;91m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>27&&z<73){printf("\e[1;31m\e[42mP\e[0m");} //zona humana
                    if(z>=73){printf("\e[1;91m\e[47mP\e[0m");}  //zona dos mortos
                    break;
                case 35:
                    if(z<=28){printf("\e[1;91m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>28&&z<72){printf("\e[1;31m\e[42mP\e[0m");} //zona humana
                    if(z>=72){printf("\e[1;91m\e[47mP\e[0m");}  //zona dos mortos
                    break;
                case 36:
                    if(z<=29){printf("\e[1;91m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>29&&z<71){printf("\e[1;31m\e[42mP\e[0m");} //zona humana
                    if(z>=71){printf("\e[1;91m\e[47mP\e[0m");}  //zona dos morto
                    break;
                case 37:
                    if(z<=30){printf("\e[1;91m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>30&&z<69){printf("\e[1;31m\e[42mP\e[0m");} //zona humana
                    if(z>=69){printf("\e[1;91m\e[47mP\e[0m");}  //zona dos mortos
                    break;
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                    printf("\e[0;31m\e[42mP\e[0m");
                    break;
                case 43:
                    if(z>=47&&z<=53){printf("\e[1;91m\e[42mP\e[0m");}
                    if(z<47||z>53){printf("\e[0;31m\e[42mP\e[0m");}
                    break;
                case 44:
                    if(z>=44&&z<=56){printf("\e[1;93m\e[42mP\e[0m");}
                    if(z<44||z>56){printf("\e[0;31m\e[42mP\e[0m");}
                    break;
                case 45:
                    if(z>=41&&z<=59){printf("\e[1;94m\e[42mP\e[0m");}
                    if(z<41||z>59){printf("\e[0;31m\e[42mP\e[0m");}
                    break;
                case 46:
                    if(z>=39&&z<=61){printf("\e[1;95m\e[42mP\e[0m");}
                    if(z<39||z>61){printf("\e[0;31m\e[42mP\e[0m");}
                    break;
                case 47:
                    if(z>=36&&z<=64){printf("\e[1;96m\e[42mP\e[0m");}
                    if(z<36||z>64){printf("\e[0;31m\e[42mP\e[0m");}
                    break;
                case 48:
                    if(z>=33&&z<=67){printf("\e[1;91m\e[42mP\e[0m");}
                    if(z<33||z>67){printf("\e[0;31m\e[42mP\e[0m");}
                    break;
                case 49:
                    if(z>=30&&z<=70){printf("\e[1;93m\e[42mP\e[0m");}
                    if(z<30||z>70){printf("\e[0;31m\e[42mP\e[0m");}
                    break;
                case 50:
                    if(z>=28&&z<=72){printf("\e[1;94m\e[42mP\e[0m");}
                    if(z<28||z>72){printf("\e[0;31m\e[42mP\e[0m");}
                    break;
                }
            }          //porque 10 em 1? isto est� includio no meu rascunho/relatorio sobre o trabalho
            else{
                switch(r){ //rendering MAPA
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
                    printf("\e[1;31mς\e[0m"); //Zona final
                    break;
                case 13:
                case 14:
                    printf("\e[0;30m\e[47mΑ\e[0m"); //Zona montanhas
                    break;
                case 15:
                    if(z<=30){printf("\e[1;92m\e[43mψ\e[0m");}  //zona desserta
                    if(z>30&&z<69){printf("\e[1;33m\e[42mᾳ\e[0m");} //zona verde
                    if(z>=69){printf("\e[1;94m\e[47mΛ\e[0m");}  //zona de neve
                    break;
                case 16:
                    if(z<=29){printf("\e[1;92m\e[43mψ\e[0m");}  //zona dos orcos
                    if(z>29&&z<71){printf("\e[1;33m\e[42mᾳ\e[0m");} //zona humana
                    if(z>=71){printf("\e[1;94m\e[47mΛ\e[0m");}  //zona dos morto
                    break;
                case 17:
                    if(z<=28){printf("\e[1;92m\e[43mψ\e[0m");}  //zona dos orcos
                    if(z>28&&z<72){printf("\e[1;33m\e[42mᾳ\e[0m");} //zona humana
                    if(z>=72){printf("\e[1;94m\e[47mΛ\e[0m");}  //zona dos mortos
                    break;
                case 18:
                    if(z<=27){printf("\e[1;92m\e[43mψ\e[0m");}  //zona dos orcos
                    if(z>27&&z<73){printf("\e[1;33m\e[42mᾳ\e[0m");} //zona humana
                    if(z>=73){printf("\e[1;94m\e[47mΛ\e[0m");}  //zona dos mortos
                    break;
                case 19:
                    if(z<=26){printf("\e[1;92m\e[43mψ\e[0m");}  //zona dos orcos
                    if(z>26&&z<74){printf("\e[1;33m\e[42mᾳ\e[0m");} //zona humana
                    if(z>=74){printf("\e[1;94m\e[47mΛ\e[0m");}  //zona dos mortos
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
                    if(r==26){
                        if(z<=25){printf("\e[1;92m\e[43mψ\e[0m");}  //zona dos orcos
                        if(z==50){printf("\e[0;31m\e[42mΔ\e[0m");}
                        else if(z>25&&z<75){printf("\e[1;33m\e[42mᾳ\e[0m");} //zona humana
                        if(z>=75){printf("\e[1;94m\e[47mΛ\e[0m");}  //zona dos mortos
                    }
                    else{
                        if(z<=25){printf("\e[1;92m\e[43mψ\e[0m");}  //zona dos orcos
                        if(z>25&&z<75){printf("\e[1;33m\e[42mᾳ\e[0m");} //zona humana
                        if(z>=75){printf("\e[1;94m\e[47mΛ\e[0m");}  //zona dos mortos
                    }
                    break;
                case 33:
                    if(z<=26){printf("\e[1;92m\e[43mψ\e[0m");}  //zona dos orcos
                    if(z>26&&z<74){printf("\e[1;33m\e[42mᾳ\e[0m");} //zona humana
                    if(z>=74){printf("\e[1;94m\e[47mΛ\e[0m");}  //zona dos mortos
                    break;
                case 34:
                    if(z<=27){printf("\e[1;92m\e[43mψ\e[0m");}  //zona dos orcos
                    if(z>27&&z<73){printf("\e[1;33m\e[42mᾳ\e[0m");} //zona humana
                    if(z>=73){printf("\e[1;94m\e[47mΛ\e[0m");}  //zona dos mortos
                    break;
                case 35:
                    if(z<=28){printf("\e[1;92m\e[43mψ\e[0m");}  //zona dos orcos
                    if(z>28&&z<72){printf("\e[1;33m\e[42mᾳ\e[0m");} //zona humana
                    if(z>=72){printf("\e[1;94m\e[47mΛ\e[0m");}  //zona dos mortos
                    break;
                case 36:
                    if(z<=29){printf("\e[1;92m\e[43mψ\e[0m");}  //zona dos orcos
                    if(z>29&&z<71){printf("\e[1;33m\e[42mᾳ\e[0m");} //zona humana
                    if(z>=71){printf("\e[1;94m\e[47mΛ\e[0m");}  //zona dos morto
                    break;
                case 37:
                    if(z<=30){printf("\e[1;92m\e[43mψ\e[0m");}  //zona dos orcos
                    if(z>30&&z<69){printf("\e[1;33m\e[42mᾳ\e[0m");} //zona humana
                    if(z>=69){printf("\e[1;94m\e[47mΛ\e[0m");}  //zona dos mortos
                    break;
                case 38:
                case 39:
                case 40:
                case 41:
                    printf("\e[0;31m\e[42mϙ\e[0m");
                    break;
                case 42:
                    if(z==82){printf("\e[0;33m\e[42m▮\e[0m");} //----------------
                    else{printf("\e[0;31m\e[42mϙ\e[0m");}
                    break;
                case 43:
                    if(z>=47&&z<=53){printf("\e[1;91m\e[42mϝ\e[0m");}
                    if(z<47||z>53){printf("\e[0;31m\e[42mϙ\e[0m");}
                    break;
                case 44:
                    if(z>=44&&z<=56){printf("\e[1;93m\e[42mϑ\e[0m");}
                    if(z<44||z>56){printf("\e[0;31m\e[42mϙ\e[0m");}
                    break;
                case 45:
                    if(z>=41&&z<=59){printf("\e[1;94m\e[42mϸ\e[0m");}
                    if(z<41||z>59){printf("\e[0;31m\e[42mϙ\e[0m");}
                    break;
                case 46:
                    if(z>=39&&z<=61){printf("\e[1;95m\e[42mᾥ\e[0m");}
                    if(z<39||z>61){printf("\e[0;31m\e[42mϙ\e[0m");}
                    break;
                case 47:
                    if(z>=36&&z<=64){printf("\e[1;96m\e[42mρ\e[0m");}
                    if(z<36||z>64){printf("\e[0;31m\e[42mϙ\e[0m");}
                    break;
                case 48:
                    if(z>=33&&z<=67){printf("\e[1;91m\e[42mϱ\e[0m");}
                    if(z<33||z>67){printf("\e[0;31m\e[42mϙ\e[0m");}
                    break;
                case 49:
                    if(z>=30&&z<=70){printf("\e[1;93m\e[42mφ\e[0m");}
                    if(z<30||z>70){printf("\e[0;31m\e[42mϙ\e[0m");}
                    break;
                case 50:
                    if(z>=28&&z<=72){printf("\e[1;94m\e[42mτ\e[0m");}
                    if(z<28||z>72){printf("\e[0;31m\e[42mϙ\e[0m");}
                    break;
                }
            }
        }
        printf("\n");
    }
}



/* history mehcanic

v1


1+20+300+50000 = 50321
{5}


v2

011
012
014
015

022
023

031
032

111
112

122

134


*/





//------------------------------------------------------Main---------------------------------------------------
int main(){
    float x=50, y=49;
    char input;
    int yes=0;
    int PvB, PvB_Chance=100; //PvB - Player vs Bot
    int inventorio_classdamage[3]={1,0,0}; // posi��o 1 - melee; 2 - ranged; 3 - magic; 4 accesorio movement; 5 - armadura. Numero na posi��o correpsonde ao n�vel do item
    int copy_icd[3]; //a copy for inventroio_classdamage for using weapons of previous tiers
    int inventorio_classarmor[4]={1,0,0,0}; // 1 - mellee 2 - ranger 3 - mage, 4 - movement 
    int copy_ica[4];//a copy for inventorio_classarmor for using armor of previous tiers
    int invetorio_coisas[50]={0}, capacidade=5;
    int acessory[10]={0,0,0,0,0,0,0,0,0,0};

    int special=0;

    float spawnx=x, spawny=y;

    int posicao=0; //para funcoes -- o eu no passado achava que ia fazer alguma coisa sem o pointer ¯\_(ツ)_/¯

    int ccon;

    struct E_info enemyI;
    struct Chance chance;
    struct P_name name = {
        "a", //main me
        "a", //main mea
        "a",
        "a",
        "a",
        "a",
        "a",



        "A Stick", //me1 //start
        "Goblin Club", //me2 // You hear music inside it.... //drop
        "Rii Jingle Bang", //me3 // Is this a reference to Money King? //drop
        "a", //me4
        "a",//me5
        
        "Goblin Bow", //r1 //While holding this bow, you understand that its not a bow, but a bow goblin holding a bow reversed //drop
        "Flintlock", //r2 //where are the pirates? //shop
        "a", //r3
        "Ice Bow", //r4 //It's SlipperyT //drop
        "a", //r5
        "p-Ice Bow 2000", //r6 //its yellow //drop

        "Gel Wand", //ma1 // you put some gel on a stick. somehow, it works //craft
        "Slithly Torn Diary", //ma2 //it uses the power of imagination //shop
        "a", //ma3
        "Left Elf Arm", //ma4 // his name is jeff //drop
        "a", //ma5
        "Purple Eyeball", //ma6 // his name is cris //drop


        "Old Bandages", //mea1 //start
        "Cheap Armor", //mea2 //shop
        "a", //mea3
        "a", //mea4
        "a", //mea5
        
        "Wolf Hide Jacket", //ra1 //craft
        "Hunter Armor", //ra2 //shop
        "a", //ra3
        "a", //ra4
        "a", //ra5

        "Robe Gel", //maa1 //its a gel... made out of robe //craft
        "Cosplay Costume", //maa2 //its a magika girl cosplay... //shop
        "a", //maa3
        "a", //maa4
        "a", //maa5

        "Track Suit", //m1 - abibas. its fake
        "a", //m2
        "Cool Track Suit" //m3 - abadass. its cannon
    };

    playerI.defense=5;
    playerI.vida=1;
    playerI.move=0.0;
    playerI.classdamage=1;
    playerI.intelect=1;
    playerI.level=1;
    playerI.add_defense=0;
    playerI.add_move=0.0;
    playerI.add_classdamage=0;
    playerI.add_intelect=0;

    //inventario_damage_check(inventorio_classdamage, inventorio_classarmor, &name);


    system("chcp 65001");

    capa();

    srand(time(NULL));

    printf("Load/New (l/n)?\n");
    char file;
    scanf(" %c", &file);
    file=tolower(file);

    if(file=='n'){
        int dump=savingfile(invetorio_coisas, inventorio_classdamage, inventorio_classarmor, &x, &y, &spawnx, &spawny);
        printf("\nBla bla bla...");
        //Sleep(5000);
        printf("\nbla bla bla lore stuff");
        //Sleep(5000);
        printf("\nbla bla bla pls do something");
        //Sleep(5000);
        printf("\n\n\n");
    }
    if(file=='l'){
        int dump=loadingfile(invetorio_coisas, inventorio_classdamage, inventorio_classarmor, &x, &y, &spawnx, &spawny);
        if(dump==0){
            printf("\nSuccesfully loaded!\n");
        }
        else{
            printf("\nLoading failed!\n");
        }
    }


    menu();

    printf("\n\n\n");

    do{
        printf("Posicao: %.2f, %.2f\n", x, y);

        input = getch();

        switch(input){ //controlos
        case 'S':
        case 's':
            if(y<50){
                y=y+0.01+playerI.move;
            }
        break;
        case 'A':
        case 'a':
            if(x>0){
                x=x-0.02-playerI.move;
            }
        break;
        case 'W':
        case 'w':
            if(y>0){
                y=y-0.01-playerI.move;
            }
        break;
        case 'D':
        case 'd':
            if(x<100){
                x=x+0.02+playerI.move;
            }
        break;
        case 'M':
        case 'm':
            mapCriar(x, y);
            input = getch();
        break;
        case 'I':
        case 'i':
        inventario_show(invetorio_coisas, posicao, name, inventorio_classdamage, inventorio_classarmor);
        int wee=1;
        input = getch();
        break;
        case 'P':
        case 'p':
        printf("\nClassDamage: %d", playerI.classdamage);
        printf("\nDefense: %d", playerI.defense);
        printf("\nSpeed: %.3f", playerI.move);
        printf("\nIntelect: %d", playerI.intelect);
        printf("\nLevel: %d\n", playerI.level);
        printf("\n...");
        printf("\nAddClassDamage: %d", playerI.add_classdamage);
        printf("\nAddDefense: %d", playerI.add_defense);
        printf("\nAddSpeed: %.3f", playerI.add_move);
        printf("\nAddIntelect: %d", playerI.add_intelect);
        printf("\n...");
        input = getch();
        break;
        case 'V':
        case 'v':
        printf("\nSaving...");
        int save=0;

        save=savingfile(invetorio_coisas, inventorio_classdamage, inventorio_classarmor, &x, &y, &spawnx, &spawny);
        if(save==0){
            printf("\nSuccesfully saved!\n");
        }
        else{
            printf("\nSaving failed!\n");
        }
        printf("\n");
        input = getch();
        break;
        case 'L':
        case 'l':
        printf("\nLoading...");
        int load=0;
        
        load=loadingfile(invetorio_coisas, inventorio_classdamage, inventorio_classarmor, &x, &y, &spawnx, &spawny);
        if(load==0){
            printf("\nSuccesfully loaded!\n");
        }
        else{
            printf("\nLoading failed!\n");
        }
        
        printf("\n");
        input = getch();
        break;
        
        case 'E':
        case 'e':
        equip_battle(name, inventorio_classdamage, inventorio_classarmor);
            /*switch(op){
                case 1:
                printf("Equipping %s\n", name.nameArmorMe);
                break;
                case 2:
                printf("Equipping %s\n", name.nameArmorR);
                break;
                case 3:
                printf("Equipping %s\n", name.nameArmorMa);
                break;
            }*/
        input = getch();
        break;
        case 'K':
        case 'k':
        menu();
        input = getch();
        break;
        case 'C':
        case 'c':
        ccon=0;
        craft(invetorio_coisas, inventorio_classdamage, inventorio_classarmor, ccon, name);
        input = getch();
        break;
        }
        system("cls");
        if((82.00<x&&x<82.99)&&(42.00<y&&y<42.99)){
            printf("\nEntering the goblin camp... (15+ lvl)");
            goblin_camp(enemyI, inventorio_classdamage, chance, posicao, invetorio_coisas, &x, &y, &spawnx, &spawny);
        }
        if((50.00<x&&x<50.99)&&(26.00<y&&y<26.99)){
            printf("\nEntering the village...");
            village(inventorio_classdamage, posicao, invetorio_coisas, &x, &y, &spawnx, &spawny, name);
        }
        PvB = rand()%PvB_Chance+1;
        if(PvB==1){
            printf("Batalha!");
            if(y<=12){ //demon side
                enemyI.type_battle = rand()%4+1; // 1-4
                enemyI.type_specie = 60 + 1;
                enemyI.rarity = rand()%100+1; // golden if 100
                enemyI.level = rand()%26+75; //75-100
            }
            if(y>12&&y<=14){ //mountains
                enemyI.type_battle = rand()%4+1; // 1-4
                enemyI.type_specie = 50 + 1;
                enemyI.rarity = rand()%100+1; // golden if 100
                enemyI.level = rand()%16+60; //60-75
            }
            if(y>14 && y<=37 && x<=25){//dessert
                enemyI.type_battle = rand()%2+1; // 1 and 2
                enemyI.type_specie = 30 + (rand()%3+1);
                enemyI.rarity = rand()%100+1;
                enemyI.level = rand()%21+20; //20-40
            }
            if(y>14 && y<=37 && x>25 && x <75){ // plains
                enemyI.type_battle = 1; // 1
                enemyI.type_specie = 20 + (rand()%2+1);
                enemyI.rarity = rand()%100+1;
                enemyI.level = rand()%6+10; //10-15 //bug tratado acontecido na aula da apresentação  (ausenica de enemy.level=)
            }
            if(y>14 && y<=37 && x>=75){ // ice forest
                enemyI.type_battle = rand()%4+3; // 3 and 4
                enemyI.type_specie = 40 + (rand()%2+1);
                enemyI.rarity = rand()%100+1; 
                enemyI.level = rand()%21+40; //40-60 
            }
            if(y>37){ // starting zone
                int xx=(int)x;
                int yy=(int)y;
                if((yy==43&&xx>=47&&xx<=53)||(yy==44&&xx>=44&&xx<=56)||(yy==45&&xx>=41&&xx<=59)||(yy==46&&xx>=39&&xx<=61)||(yy==47&&xx>=36&&xx<=64)||(yy==48&&xx>=33&&xx<=67)||(yy==49&&xx>=30&&xx<=70)||(yy==50&&xx>=28&&xx<=72)){
                    enemyI.type_battle = (rand() % 2) * 2 + 1; // 1 and 3
                    enemyI.type_specie = 10 + (rand()%4+1);
                    enemyI.rarity = rand()%100+1;
                    enemyI.level = rand()%5+1; //1-5
                }
                else{
                    enemyI.type_battle = (rand() % 2) * 2 + 1; // 1 and 3
                    enemyI.type_specie = 10 + (rand()%4+1);
                    enemyI.rarity = rand()%100+1;
                    enemyI.level = rand()%16+5; //5-20
                }
            }
            special=0;
            int dump=batalha(enemyI, inventorio_classdamage, chance, posicao, invetorio_coisas, special, &x, &y, &spawnx, &spawny);
            if(dump==0){
                dump=2;
                spawnpoint(&x, &y, &spawnx, &spawny, dump);
            }
            printf("\n%d\n", xp_til_lvlup);
            //batalha();
            PvB_Chance=500;
            Sleep(1000);
            input = getch();
        }
        else{
            PvB_Chance--;
        }
    }
    while(yes==0);
    return 0;
}




void capa(){
    printf(
        "                                                                                                                                                                                                      \n"
        "                                                                               :5#BBBBBBBBBGBBBBBGY?^.                                :!?5PPPPPG5J?~.                                                   \n"
        "                                                                               :B@@@@@@@@@@@@@@@@@@@&GJ:                            !5#@@@@@@@@@@@@@#GY!:                                               \n"
        "                    ..:~~~!7??JJJJJJJ??!^:                                     :G@@@@@@@&#GGGGGB&@@@@@@#7                         ~P&@@#5YJJJJY55G#&@@@@#BY!:                                           \n" //ignorar estes warnings
        "                 .75B&&@@@@@@&@@@@@@@@@@&&BPJ^.                                :G@@@@@@5^.     .^!5#@@@@@7                      .Y#@@B!.          .:~7YB@@@@#Y^                                         \n"
        "                JB@@@@@?!~^^^:^!!77YPGB#&@@@@@B5~                              :G@@@@&7            ^Y&@@@&~                    :P@@@G:                  ^JG@@@#Y:                                       \n"
        "               .@@@@@@@:              ..:!JB@@@@&P!                             J@@@@#:              ~#@@@G.                  :P@@@Y.                      ^JB@@#57.                                    \n"
        "               .&@@@@@@^                    !B@@@@&Y.                           !&@@@&J               J@@@@.                 .P@@&7                          .7G@@@#7                                   \n"
        "                5@@@@@@^                     .Y&@@@&P.                          ^B@@@@5               !@@@@~                .5@@@7                              ^&@@&!                                  \n"
        "                Y@@@@@@^                       7@@@@@G.                         :G@@@@5               ~&@@&5                ?@@@5.                               ?5Y?~                                  \n"
        "                !@@@@@@^                       .P@@@@@5                          5@@@@5               ^B@@@&               :#@@&~                                                                       \n"
        "                !@@@@@@^                        !@@@@@#                          Y@@@&?               :P@@@&:              G@@@?                                                                        \n"
        "                :B@@@@@^                        ~&@@@@&                          J&@@#:                J@@@@7             J@@@5                                                                         \n"
        "                .5@@@@@^                        ~&@@@@5                          !B@@&~                ?@@@@?            :#@@#~                                                                         \n"
        "                .5@@@@@^                        ~&@@&5                            P@@&?               !B@@@@?            5@@@5                                                                          \n"
        "                 !@@@@@^                     .!YB@@G~                             5@@@B!^:      .:^!JG&@@@@G.           ^B@@#:                                                                          \n"
        "                 ^#@@@@7.:::::::::::::^!?JYG#&@@#5!                               7#@@@@@&######&&@@@@@@&BJ.            5@@@?                                                                           \n"
        "                  ?@@@@&#&&&@@@@@@@@@@@@@@@@@#5!:                                 :#@@&###########BGGP?!^.             !&@@G                                                                            \n"
        "                  !&@@@@@@@@@@@@@@@@&&#BP5Y?~.                                    :#@&^...........                    .P@@#:                                                                            \n"
        "                  .5@@&PY7!77777777!:..                                           :#@#.                               7@@@~                                                                             \n"
        "                   ?&@@&#P57^.                                                    :#@#                                7@@@.                                                                             \n"
        "                   ^G@@@@#&@@&BY7^                                                :#@#                                ?@@@:                                                                             \n"
        "                    5@@@&7.!JG#@@&GJ~.                                            :#@#                               .5@@@:                    !?!^                                                     \n"
        "                    ?#@@@G.   .~75#@@#P7^                                         :#@#:                              :G@@@:                   !&@@&B57^                                                 \n"
        "                     G@@@@J       .^J#@@&G7:                                      :#@#:                              .P@@@:                   ^7?P#@@@&BY!:                                             \n"
        "                     7#@@@&!         .7G@@@B?:                                    :#@#:                               J@@@:                       .!YB&@@@&G?^.                                         \n"
        "                      G&@@@#^           ~5&@@#5~                                  :#@#:                               7@@@:                           :~?5B&@&&~                                        \n"
        "                      ^#@@@@5.            ^J#@@&G7.                               :#@#:                               :G@@Y                               .P@@#^                                        \n"
        "                       !&@@@@!              .J&@@@#J^                             :#@#:                                ~#@@J.                            !B@@#!                                         \n"
        "                        5@@@@#.               :Y@@@@&P?:                          :#@#:                                 7#@@BY!.                       !G@@&P^                                          \n"
        "                        :B@@@@J                 ~5&@@@@#5^                        :#@#:                                  ^P@@@@BJ.                   :Y&@@5^                                            \n"
        "                         !@@@@#                   :Y&@@@@&5^                      !&@#:                                    7#@@@@B!                :J&@#Y^                                              \n"
        "                          J@@@&~                    ~P&@@@@#7                     7&@&7                                     .?B@@@&P~^:.     .:^^JP@@B?:                                                  \n"
        "                           Y&@@J                      ^?B@@@&P^                   7&@&7                                       .!5B&@@@&#B###B#&@@&GJ~.                                                    \n"
        "                           ^B@@P                        .7B@@@#Y^                 ^#@@J                                          .^?JYPB######BBY^.                                                       \n"
        "                            5@@#                          .P@@@@&5:               .#@@5                                                                                                                   \n"
        "                            !#@&7                          .J#@@@@#~              :B&&G.                                                                                                                  \n"
        "                             B@@P.                           :Y#GY~.               ..:^                                                                                                                  \n"
        "                             7#@&?                             :.                                                                                                                                        \n"
        "                             .&@@G:                                                                                                                                                                     \n"
        "                              &BPY^                                                                                                                                                                     \n"
        "                              Y~                                                                                                                                                                        \n"
        "                              ..                             ~^                                                                                                                                         \n"
        "                                                             5Y                                                                                                                                         \n"
        "                                                                                                                                                                                                         \n"
        "                                                           .7?~                                                                                                                                         \n"
        "      ?PGGGJ:  ~YYYYY7   .!???!~P5J???????7!:             ~#&P@J~7.  7Y                                                                                                                                    \n" //ignorar este warning tambem
        "      Y@J:7&G: G@?!77~  !##Y?J7.~!?J??&@JJY5!             5@? &&B#^  @#  :7JJ7.:J5YYYJ! !JJJ?!  ~?5PP5~!!~   . ?&^~!:..            ...  .:.                           .          .    ..                 \n"
        "      5@^ !&G. Y&7     .B#:           ##:                 5@!J@PGB:  @B ~&BJJ&#J7?&&??YB#J?Y@@Y5&P?~^^~G@Y. B 7G#^?G&#?^5P5!  ~YY7.5&B! JG&G~ :YPP5Y.              ^JPG5.   ^YP ?&P  J@&:  .             \n"
        "      J@Y5&G^  ?@#GG!  .##~::.       :&#                  5@#B7^&&P?7@B^#B:  !@Y ~#5 .&B:  7@Y!&#?^.   ?@~ :@ &@J  ?@?  5@Y^ ~&#7^ 5&~   ^@#: 7@Y^!~             ^P&P!^    ~&@@! @B& &@@ ^BBPPG7         \n"
        "      !&#@G    ?@J:^.   !PGG&&?      ?@J                  P@~  :G#JJJ@B?@?   P@7 ~&5.P&!   J@7 :?5P#5  7@7 ~@@ @J  B#: .G&.  !@5.  5&~  ^B@^  J@7        .      7&G^      :&# &? &! G#Y& 5&7             \n"
        "      !&J7@G:  ?&7          J@@^     5&~        .Y7       P@:  .GB: .@G!@5~7G&7  ~&5.#&7^^?&B.     &@  ~#P.~@@ @J  B#. ~#G.  .~G@7 P#~ :#@7  .P@PPY     J#~     #@! J5#@5 G@GG@5 @P   ?& 5@GPPP7         \n"
        "      !&Y ~##7!?@P7!7~ .GBJ~Y@&^     P@^        ~@5       P@:  .PB: ^@P !555?:   ~&5 ^5PPPP?.~Y7~7G&?  .P&:~@ B@J  #&. ?@!     ^&G.@B. Y@?   ~#Y!~^     Y@7     B@&BBB#PG &?  G@ B#^  ?@ &B              \n"
        "      !@J  .5@G.??JYY?. :7YPPJ^      Y&^        ?@7       ?Y.   ::  .GJ          .!^         :YPP5J^    P&.^# ~#7  7?~PB@P^  ~JP&Y^@#^Y@?   ^&P.   .~~~7&&:     .7???7: !?:   7P..^.  ?@ G#PGGB~         \n"
        "       ~.    ^:                      .^       .7@P.                                                  .7Y#@? .        .!~~!.  ~?7^.5BGG#@GPP!~@G?5Y ^PPPP5^                            ^5^ ::::.          \n"
        "                                             ?B#Y:                                                                                                                                                        \n"
        "                                             ::                                                                                                                                                          \n"
    );
    printf("\nO que está escrito na capa?\nRPG - Rest, Photosintisize, Game\n(Zoom out para ver melhor)");
    printf("Anuncio: O jogo não está completo, mas tem a base feita\n");
}


void menu(){
    printf("\n\n******************************************************"); //54
    printf("\n* W,A,S,D - Movement to the directionns              *");
    printf("\n* M - Map                                            *");
    printf("\n* I - Inventory                                      *");
    printf("\n* P - Stats                                          *");
    printf("\n* E - Equip/change armory                            *");
    printf("\n* V - Save                                           *");
    printf("\n* L - Load                                           *");
    printf("\n* K - Controls                                       *");
    printf("\n* C - Crafting                                       *");
    printf("\n******************************************************");
}

void spawnpoint(float *x, float *y, float *spawnx, float *spawny, int op){
    if(op==1){ //change spawnpoint
        *spawnx=(int)*x;
        *spawny=(int)*y;
    }
    if(op==2){ // return to spawnpoint
        *x=*spawnx;
        *y=*spawny;
    }
}


/*
make add_caracteristics function - needs configuration
add caracteristics to every enemy ✔


1->make weapons and armor drops _._ ya?
1-->make weapon and armor equip/show work (v1 - mathematics)  []~(￣▽￣)~✔
1--->make info about thing in inventory :_: maybe not

// add return to spawnpoint

2->make hotpoints (village, dungeons) - subx, suby, own map (for some) ... work in process. To make - village, dessert catacombs.

2--> make crafting for player (village, goblin camp, dungeon?, hand) ( $ _ $ ) yeah 

2--->make weapons and armor crafts yeah (oﾟvﾟ)ノ



0->make chances work

0-->make buffs and debuffs



4->creat special entities (npcs, minibosses) ... work in progress ＼(((￣(￣(￣▽￣)￣)￣)))／
 
4-->create a boss (dessert?) - finallee of demo version




in the end: balance things out
*/