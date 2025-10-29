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
    char nameMellee[20];
    char nameRange[20];
    char nameMage[20];
    char nameArmor[20];
    char name[20];
};

struct History{
    int ml[1];
    int r[1];
    int mg[1];
    int aml[1];
    int ar[1];
    int amg[1];
};

/*struct Boss_info{

};*/

int lvlup(struct P_info *playerI, int xp_til_lvlup){
    printf("\nYou leveled up! %d -> ", playerI->level);
    playerI->level++;
    int def=playerI->defense;
    int inte=playerI->intelect;
    int cd=playerI->classdamage;
    float mv=playerI->move;
    if(playerI->level<50){xp_til_lvlup=(int)(xp_til_lvlup*1.2);}
    if(playerI->level>50){xp_til_lvlup=(int)(xp_til_lvlup*1.5);}
    switch(playerI->level){
        case 10:
        case 20:
        case 30:
        case 40:
        case 60:
        case 70:
        case 80:
        case 90:
            playerI->defense=playerI->defense+3;
            playerI->move=playerI->move+0.01;
            playerI->classdamage=playerI->classdamage+3;
            playerI->intelect=playerI->intelect+4;
            break;
        case 25:
        case 75:
            playerI->defense=playerI->defense+5;
            playerI->move=playerI->move+0.05;
            playerI->classdamage=playerI->classdamage+5;
            playerI->intelect=playerI->intelect+6;
        break;
        case 50:
            playerI->defense=playerI->defense+10;
            playerI->move=playerI->move+0.05;
            playerI->classdamage=playerI->classdamage+10;
            playerI->intelect=playerI->intelect+10;
            break;
        case 100:
            playerI->defense=playerI->defense+10;
            playerI->move=1.0;
            playerI->classdamage=playerI->classdamage+10;
            playerI->intelect=playerI->intelect+10;
            break;
        default:
            playerI->defense=playerI->defense+1;
            playerI->move=playerI->move+0.005;
            playerI->classdamage=playerI->classdamage+1;
            playerI->intelect=playerI->intelect+2;
    }
    printf("\nDefense %d -> %d", def, playerI->defense);
    printf("\nMovement %.3f -> %.3f", mv, playerI->move);
    printf("\nClass Damage %d -> %d", cd, playerI->classdamage);
    printf("\nIntelect %d -> %d", inte, playerI->intelect);
    printf("\n%d\n", xp_til_lvlup);

    return xp_til_lvlup;
}




void menu();



//------------------------------------------------File Manipulation---------------------------------------------------------
int savingfile(struct P_info *playerI, int *invetorio_coisas[], float *x, float *y){
    savefile=fopen("savefile.txt", "w");
    if(!savefile){return 1;}
    fprintf(savefile, 
        "level=%d\nvida=%d\ndefense=%d\nclassdamage=%d\nintelect=%d\nadd_defense=%d\nadd_classdamage=%d\nadd_intelect=%d\nmove=%f\nadd_move=%f\nx=%f\ny=%f\n", 
        playerI->level, playerI->vida, playerI->defense, playerI->classdamage, playerI->intelect, playerI->add_defense, playerI->add_classdamage, playerI->add_intelect, playerI->move, playerI->add_move, x, y);
    for(int i=0; i<50; i++){
        fprintf(savefile, "%d/", invetorio_coisas[i]);
    }
    fclose(savefile);
}

int loadingfile(struct P_info *playerI, int *invetorio_coisas[], float *x, float *y){
    savefile=fopen("savefile.txt", "r");
    if(!savefile){return 1;}
    fscanf(savefile, 
        "level=%d\nvida=%d\ndefense=%d\nclassdamage=%d\nintelect=%d\nadd_defense=%d\nadd_classdamage=%d\nadd_intelect=%d\nmove=%f\nadd_move=%f\nx=%f\ny=%f\n", 
        &playerI->level, &playerI->vida, &playerI->defense, &playerI->classdamage, &playerI->intelect, &playerI->add_defense, &playerI->add_classdamage, &playerI->add_intelect, &playerI->move, &playerI->add_move, &x, &y);
    for(int i=0; i<50; i++){
        fscanf(savefile, "%d/", &invetorio_coisas[i]);
    }
    fclose(savefile);
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

void inventario_damage_check(int inventorio_classdamage[], int inventorio_classarmor[], struct P_name *name){ //to call: inventario_damage_check(inventorio_classdamage, inventorio_classarmor, &name);
    int i=0;
    do{
        if(inventorio_classdamage[0]!=0){
            switch(inventorio_classdamage[i]){
            case 1:
                strcpy(name->nameMellee, "Ass Destroyer");
                break;
            case 2:
                strcpy(name->nameMellee, "spaceholder");
                break;
            }
        }
        if(inventorio_classarmor[0]!=0){
            switch(inventorio_classarmor[i]){
            case 1:
                strcpy(name->nameArmor, "Ass Cheeks");
                break;
            case 2:
                strcpy(name->nameArmor, "spaceholder");
                break;
            }
        }
        if(inventorio_classdamage[1]!=0){
            switch(inventorio_classdamage[i]){
            case 1:
                strcpy(name->nameMellee, "Goblin Bow");
                break;
            case 2:
                strcpy(name->nameMellee, "spaceholder");
                break;
            }
        }
        if(inventorio_classarmor[1]!=0){
            switch(inventorio_classarmor[i]){
            case 1:
                strcpy(name->nameArmor, "ssfdsfds");
                break;
            case 2:
                strcpy(name->nameArmor, "spaceholder");
                break;
            }
        }
        if(inventorio_classdamage[2]!=0){
            switch(inventorio_classdamage[i]){
            case 1:
                strcpy(name->nameMellee, "Gel Wand");
                break;
            case 2:
                strcpy(name->nameMellee, "spaceholder");
                break;
            }
        }
        if(inventorio_classarmor[2]!=0){
            switch(inventorio_classarmor[i]){
            case 1:
                strcpy(name->nameArmor, "Gel Robe");
                break;
            case 2:
                strcpy(name->nameArmor, "spaceholder");
                break;
            }
        }
        i++;
    }
    while(i!=3);
}

void inventario_show(int inventorio_coisas[], int posicao, struct P_name *name){
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
    printf("\n%s", name->nameMellee);
    printf("\n%s", name->nameArmor);
    printf("\n");
    posicao=0;
}

void inventario_add(int inventorio_coisas[], int posicao, int quantity){
    inventorio_coisas[posicao]=quantity;
}







//-----------------------------------------------------Battle-------------------------------------------------------------
int damage_function(struct P_info playerI, struct Chance chance, int inventorio_batalha[], int foption); //damage function call

void batalha(struct E_info enemyI, struct P_info *playerI, int inventorio_batalha[], struct Chance chance, int posicao, int inventorio_coisas[], int xp, int *xp_til_lvlup){ // struct P_info playerI, int inventorio_batalha[]
    float enemyID;
    int quantity;
    int options=0;
    enemyID = (enemyI.type_battle * 1000) + (enemyI.type_specie * 10) + (enemyI.rarity/100.00);
    printf("\n%.2f\n", enemyID);
    enemyID = (int)enemyID;
    printf("\n%.0f\n", enemyID);
    printf("You've been attacked by ");
    switch ((int)enemyID) { 
    //entity id check

    // Starting Zone
    case 1110: printf("green slime\n"); enemyI.HP=5; enemyI.attack=1; posicao=1; enemyI.basexp=10; break;
    case 1111: printf("golden starting slime\n"); enemyI.HP=5; enemyI.attack=1; break;
    case 1120: printf("goblin warrior\n"); enemyI.HP=5; enemyI.attack=1; break;
    case 1121: printf("golden goblin warrior\n"); enemyI.HP=5; enemyI.attack=1; break;
    case 1130: printf("hungry wolf\n"); enemyI.HP=5; enemyI.attack=1; break;
    case 1131: printf("golden wolf\n"); enemyI.HP=5; enemyI.attack=1; break;
    case 1140: printf("spikey\n"); enemyI.HP=5; enemyI.attack=1; break;
    case 1141: printf("golden spikey\n"); enemyI.HP=5; enemyI.attack=1; break;

    // Plains
    case 1210: printf("blue slime\n"); break;
    case 1211: printf("golden plains slime\n"); break;
    case 1220: printf("goblin\n"); break;
    case 1221: printf("golden goblin warrior\n"); break;

    // Desert
    case 1310: printf("yellow slime\n"); break;
    case 1311: printf("golden desert slime\n"); break;
    case 1320: printf("scorpion\n"); break;
    case 1321: printf("golden scorpion\n"); break;
    case 1330: printf("arachnid\n"); break;
    case 1331: printf("golden arachnid\n"); break;

    // Mountains
    case 1510: printf("monstrous lizard\n"); break;
    case 1511: printf("golden lizard\n"); break;

    // Demon Side
    case 1610: printf("dm\n"); break;
    case 1611: printf("dmg\n"); break;

    // Desert
    case 2310: printf("Orc\n"); break;
    case 2311: printf("golden orc\n"); break;
    case 2320: printf("dbm1\n"); break;
    case 2321: printf("dbm1g\n"); break;
    case 2330: printf("dbm2\n"); break;
    case 2331: printf("dbm2g\n"); break;

    // Mountains
    case 2510: printf("rock golem\n"); break;
    case 2511: printf("gold golem\n"); break;

    // Starting Zone (again)
    case 3110: printf("bow goblin\n"); enemyI.HP=5; enemyI.attack=1; break;
    case 3111: printf("golden bow goblin\n"); enemyI.HP=5; enemyI.attack=1; break;
    case 3120: printf("exploding spikey\n"); enemyI.HP=5; enemyI.attack=1; break;
    case 3121: printf("golden exploding spikey\n"); enemyI.HP=5; enemyI.attack=1; break;
    case 3130: printf("bow goblin\n"); enemyI.HP=5; enemyI.attack=1; break;
    case 3131: printf("golden bow goblin\n"); enemyI.HP=5; enemyI.attack=1; break;
    case 3140: printf("exploding spikey\n"); enemyI.HP=5; enemyI.attack=1; break;
    case 3141: printf("golden exploding spikey\n"); enemyI.HP=5; enemyI.attack=1; break;

    // Icy Forest
    case 3410: printf("snow elf\n"); break;
    case 3411: printf("golden elf\n"); break;
    case 3420: printf("sr1\n"); break;
    case 3421: printf("sr1g\n"); break;

    // Mountains
    case 3510: printf("mr\n"); break;
    case 3511: printf("mrg\n"); break;

    // Demon Side
    case 3610: printf("dr\n"); break;
    case 3611: printf("drg\n"); break;

    // Icy Forest
    case 4410: printf("mage elf\n"); break;
    case 4420: printf("sm1\n"); break;
    case 4421: printf("sm1g\n"); break;
    case 4422: printf("purple elf\n"); break;

    // Mountains
    case 4510: printf("mm\n"); break;
    case 4511: printf("mmg\n"); break;

    // Demon Side
    case 4610: printf("dm\n"); break;
    case 4611: printf("dmg\n"); break;

    // Cfsssdsfdssdsfsdfdsfdsfdssdfsdsdfsdfdssdfssdfsdsdfsdfsdsdfssdsfdsfdsfdsfdsdsf
    default:
        printf("Unknown entity ID\n");
        break;
    }
    //check player stats
    /*player clone*/   int defense=playerI->defense;
    /*p attack clone*/ int p_attack=damage_function(*playerI, chance, inventorio_batalha, options);
    /*enemy clone*/    int HP=((enemyI.level/20.0)*enemyI.HP)+enemyI.HP;
    /*e attack clone*/ int e_attack=((enemyI.level/30.0)*enemyI.attack)+enemyI.attack;
    /*mob xp*/         int mobxp=enemyI.basexp+(enemyI.basexp*(enemyI.level/2));
    printf("----------------------------------------"); //40
    printf("\nEnemy stats: Level: %d, HP: %d, Attack: %d", enemyI.level, enemyI.HP, e_attack);
    printf("\nPlayer stats: Level: %d, Defense: %d, Attack: %d", playerI->level, defense, p_attack);
    char option;
    int end=0;
    do{
        printf("\n----------------------------------------");
        printf("\nEnemy: %d HP", HP);
        printf("\nPlayer: %d defense", defense);
        printf("\n----------------------------------------");
        printf("\nYour turn!");
        printf("\nAtack (t)/Action (f)/Run (r)\n");
        tolower(option);
        scanf(" %c", &option);
        printf("----------------------------------------");
        if(option == 't'){
            HP=HP-p_attack;
            printf("\nYour attack hit!");
            printf("\n-%d HP", p_attack);
            printf("\n----------------------------------------");
        } // create hit chance that depends from class
        if(option == 'f'){
            printf("\nConsume/Use/Change Class\n");
            scanf("%d", &options);
            printf("\n----------------------------------------");
            if(options==1){options=1;}
            if(options==2){options=2;}
            if(options==3){options=3; p_attack=damage_function(*playerI, chance, inventorio_batalha, options);}
        }
        if(option == 'r'){
            int chance = rand()%2+1;
            if(chance == 1){printf("\n\nYou escaped!\n"); end=1;}
            else{printf("\n\nYou failed to escape!\n");}
        }
        if(HP<=0){
            printf("\nYou have defeated the enemy!");
            end=1;
            if(posicao>0){
                quantity = rand()%3+1;
                inventario_add(inventorio_coisas, posicao, quantity);//possible error ---> posicao changed
                printf("\nEnemy have droped %d ", quantity);
                item_id_check(posicao);
            }
            printf("\nYou've recieved %d xp", mobxp);
            xp=xp+mobxp;
            if(xp>=*xp_til_lvlup){
                *xp_til_lvlup=lvlup(playerI, *xp_til_lvlup);
                printf("\n%d\n", mobxp);
            }
        }
        if(end==0){
                printf("\nEnemy's turn!");
                printf("\n----------------------------------------");
                if(defense>0){
                    defense=defense-e_attack; //fazer um dodge chance
                    printf("\n-%d defense", e_attack);
                    if(defense-e_attack==-1){printf("\nYour defense is down! One hit left!");}
                }
                else{
                    printf("\nYou've been hit...");
                    int chance = rand()%3+1;
                    if(chance==1){
                        printf("\nBut you survived!");
                    }
                    else{
                        printf("And you died...\nSending back to the spawn point");
                        end=1;
                    }
                }
        }
    }
    while(end==0);
}

int damage_function (struct P_info playerI, struct Chance chance, int inventorio_batalha[], int foption){
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
            break;
        case 3:
            break;
        case 4:
            break;
        }
        p_attack=damage+playerI.classdamage;
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
            break;
        }
        p_attack=damage+playerI.classdamage;
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
            break;
        }
        p_attack=(damage+playerI.classdamage)*((playerI.intelect/100)+1);
    }
    return p_attack;
}




//---------------------------------------------------------Map----------------------------------------------
void mapCriar (float x, float y){
    int z, r; //alternativas para x e y
    for(r=0; r<hight; r++){
        for(z=0; z<width; z++){
            if(z==(int)x&&r==(int)y){ //usei (int) para curtar a parte decimal, porque eu quero que um quadrado (neste caso ponto) tiha a raz�o de 10 em 1 entre posi��o, ou seja, 10 posi��es num quadrado
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
                    printf("\e[1;31mP\e[0m"); //Zona final
                    break;
                case 13:
                case 14:
                    printf("\e[0;30m\e[47mP\e[0m"); //Zona montanhas
                    break;
                case 15:
                    if(z<=30){printf("\e[1;92m\e[43mP\e[0m");}  //zona desserta
                    if(z>30&&z<69){printf("\e[1;33m\e[42mP\e[0m");} //zona verde
                    if(z>=69){printf("\e[1;94m\e[47mP\e[0m");}  //zona de neve
                    break;
                case 16:
                    if(z<=29){printf("\e[1;92m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>29&&z<71){printf("\e[1;33m\e[42mP\e[0m");} //zona humana
                    if(z>=71){printf("\e[1;94m\e[47mP\e[0m");}  //zona dos morto
                    break;
                case 17:
                    if(z<=28){printf("\e[1;92m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>28&&z<72){printf("\e[1;33m\e[42mP\e[0m");} //zona humana
                    if(z>=72){printf("\e[1;94m\e[47mP\e[0m");}  //zona dos mortos
                    break;
                case 18:
                    if(z<=27){printf("\e[1;92m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>27&&z<73){printf("\e[1;33m\e[42mP\e[0m");} //zona humana
                    if(z>=73){printf("\e[1;94m\e[47mP\e[0m");}  //zona dos mortos
                    break;
                case 19:
                    if(z<=26){printf("\e[1;92m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>26&&z<74){printf("\e[1;33m\e[42mP\e[0m");} //zona humana
                    if(z>=74){printf("\e[1;94m\e[47mP\e[0m");}  //zona dos mortos
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
                    if(z<=25){printf("\e[1;92m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>25&&z<75){printf("\e[1;33m\e[42mP\e[0m");} //zona humana
                    if(z>=75){printf("\e[1;94m\e[47mP\e[0m");}  //zona dos mortos
                    break;
                case 33:
                    if(z<=26){printf("\e[1;92m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>26&&z<74){printf("\e[1;33m\e[42mP\e[0m");} //zona humana
                    if(z>=74){printf("\e[1;94m\e[47mP\e[0m");}  //zona dos mortos
                    break;
                case 34:
                    if(z<=27){printf("\e[1;92m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>27&&z<73){printf("\e[1;33m\e[42mP\e[0m");} //zona humana
                    if(z>=73){printf("\e[1;94m\e[47mP\e[0m");}  //zona dos mortos
                    break;
                case 35:
                    if(z<=28){printf("\e[1;92m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>28&&z<72){printf("\e[1;33m\e[42mP\e[0m");} //zona humana
                    if(z>=72){printf("\e[1;94m\e[47mP\e[0m");}  //zona dos mortos
                    break;
                case 36:
                    if(z<=29){printf("\e[1;92m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>29&&z<71){printf("\e[1;33m\e[42mP\e[0m");} //zona humana
                    if(z>=71){printf("\e[1;94m\e[47mP\e[0m");}  //zona dos morto
                    break;
                case 37:
                    if(z<=30){printf("\e[1;92m\e[43mP\e[0m");}  //zona dos orcos
                    if(z>30&&z<69){printf("\e[1;33m\e[42mP\e[0m");} //zona humana
                    if(z>=69){printf("\e[1;94m\e[47mP\e[0m");}  //zona dos mortos
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
                    printf("\e[1;31m*\e[0m"); //Zona final
                    break;
                case 13:
                case 14:
                    printf("\e[0;30m\e[47m#\e[0m"); //Zona montanhas
                    break;
                case 15:
                    if(z<=30){printf("\e[1;92m\e[43m!\e[0m");}  //zona desserta
                    if(z>30&&z<69){printf("\e[1;33m\e[42m-\e[0m");} //zona verde
                    if(z>=69){printf("\e[1;94m\e[47m?\e[0m");}  //zona de neve
                    break;
                case 16:
                    if(z<=29){printf("\e[1;92m\e[43m!\e[0m");}  //zona dos orcos
                    if(z>29&&z<71){printf("\e[1;33m\e[42m-\e[0m");} //zona humana
                    if(z>=71){printf("\e[1;94m\e[47m?\e[0m");}  //zona dos morto
                    break;
                case 17:
                    if(z<=28){printf("\e[1;92m\e[43m!\e[0m");}  //zona dos orcos
                    if(z>28&&z<72){printf("\e[1;33m\e[42m-\e[0m");} //zona humana
                    if(z>=72){printf("\e[1;94m\e[47m?\e[0m");}  //zona dos mortos
                    break;
                case 18:
                    if(z<=27){printf("\e[1;92m\e[43m!\e[0m");}  //zona dos orcos
                    if(z>27&&z<73){printf("\e[1;33m\e[42m-\e[0m");} //zona humana
                    if(z>=73){printf("\e[1;94m\e[47m?\e[0m");}  //zona dos mortos
                    break;
                case 19:
                    if(z<=26){printf("\e[1;92m\e[43m!\e[0m");}  //zona dos orcos
                    if(z>26&&z<74){printf("\e[1;33m\e[42m-\e[0m");} //zona humana
                    if(z>=74){printf("\e[1;94m\e[47m?\e[0m");}  //zona dos mortos
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
                    if(z<=25){printf("\e[1;92m\e[43m!\e[0m");}  //zona dos orcos
                    if(z>25&&z<75){printf("\e[1;33m\e[42m-\e[0m");} //zona humana
                    if(z>=75){printf("\e[1;94m\e[47m?\e[0m");}  //zona dos mortos
                    break;
                case 33:
                    if(z<=26){printf("\e[1;92m\e[43m!\e[0m");}  //zona dos orcos
                    if(z>26&&z<74){printf("\e[1;33m\e[42m-\e[0m");} //zona humana
                    if(z>=74){printf("\e[1;94m\e[47m?\e[0m");}  //zona dos mortos
                    break;
                case 34:
                    if(z<=27){printf("\e[1;92m\e[43m!\e[0m");}  //zona dos orcos
                    if(z>27&&z<73){printf("\e[1;33m\e[42m-\e[0m");} //zona humana
                    if(z>=73){printf("\e[1;94m\e[47m?\e[0m");}  //zona dos mortos
                    break;
                case 35:
                    if(z<=28){printf("\e[1;92m\e[43m!\e[0m");}  //zona dos orcos
                    if(z>28&&z<72){printf("\e[1;33m\e[42m-\e[0m");} //zona humana
                    if(z>=72){printf("\e[1;94m\e[47m?\e[0m");}  //zona dos mortos
                    break;
                case 36:
                    if(z<=29){printf("\e[1;92m\e[43m!\e[0m");}  //zona dos orcos
                    if(z>29&&z<71){printf("\e[1;33m\e[42m-\e[0m");} //zona humana
                    if(z>=71){printf("\e[1;94m\e[47m?\e[0m");}  //zona dos morto
                    break;
                case 37:
                    if(z<=30){printf("\e[1;92m\e[43m!\e[0m");}  //zona dos orcos
                    if(z>30&&z<69){printf("\e[1;33m\e[42m-\e[0m");} //zona humana
                    if(z>=69){printf("\e[1;94m\e[47m?\e[0m");}  //zona dos mortos
                    break;
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                    printf("\e[0;31m\e[42m:\e[0m");
                    break;
                case 43:
                    if(z>=47&&z<=53){printf("\e[1;91m\e[42m.\e[0m");}
                    if(z<47||z>53){printf("\e[0;31m\e[42m:\e[0m");}
                    break;
                case 44:
                    if(z>=44&&z<=56){printf("\e[1;93m\e[42m.\e[0m");}
                    if(z<44||z>56){printf("\e[0;31m\e[42m:\e[0m");}
                    break;
                case 45:
                    if(z>=41&&z<=59){printf("\e[1;94m\e[42m.\e[0m");}
                    if(z<41||z>59){printf("\e[0;31m\e[42m:\e[0m");}
                    break;
                case 46:
                    if(z>=39&&z<=61){printf("\e[1;95m\e[42m.\e[0m");}
                    if(z<39||z>61){printf("\e[0;31m\e[42m:\e[0m");}
                    break;
                case 47:
                    if(z>=36&&z<=64){printf("\e[1;96m\e[42m.\e[0m");}
                    if(z<36||z>64){printf("\e[0;31m\e[42m:\e[0m");}
                    break;
                case 48:
                    if(z>=33&&z<=67){printf("\e[1;91m\e[42m.\e[0m");}
                    if(z<33||z>67){printf("\e[0;31m\e[42m:\e[0m");}
                    break;
                case 49:
                    if(z>=30&&z<=70){printf("\e[1;93m\e[42m.\e[0m");}
                    if(z<30||z>70){printf("\e[0;31m\e[42m:\e[0m");}
                    break;
                case 50:
                    if(z>=28&&z<=72){printf("\e[1;94m\e[42m.\e[0m");}
                    if(z<28||z>72){printf("\e[0;31m\e[42m:\e[0m");}
                    break;
                }
            }
        }
        printf("\n");
    }
}







//------------------------------------------------------Main---------------------------------------------------
int main(){
    float x=50, y=49;
    char input;
    int yes=0;
    int PvB, PvB_Chance=100; //PvB - Player vs Bot
    int inventorio_classdamage[4]={1,0,0}; // posi��o 1 - melee; 2 - ranged; 3 - magic; 4 accesorio movement; 5 - armadura. Numero na posi��o correpsonde ao n�vel do item
    int inventorio_classarmor[4]={1,0,0,0}; // 1 - mellee 2 - ranger 3 - mage, 4 - movement 
    int invetorio_coisas[50]={0}, capacidade=5;
    int acessorio[10]={0,0,0,0,0,0,0,0,0,0};

    int xp_til_lvlup=10;
    int xp=0;

    int posicao=0; //para funcoes
/*    int melee[]={},
        ranged[]={},
        magic[]={},
        movement[]={},
        armadura[]={},
        acessorio[]={};
        //acessorio_2[]={},
        //accesorio_3[]={};*/

    struct P_info playerI;
    struct E_info enemyI;
    struct Chance chance;
    struct P_name name;
    struct History history;

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

    inventario_damage_check(inventorio_classdamage, inventorio_classarmor, &name);



    system("chcp 65001");

    srand(time(NULL));

    printf("Load/New (l/n)?");
    int file;
    scanf(" %c", &file);
    file=tolower(file);

if(file=='n'){
    int dump=savingfile(&playerI, &invetorio_coisas, &x, &y);
    printf("Bem vindo a este mundo! O teu objetivo e matar o boss final - Keplestangerapocalipticon. Ele terrorisa os seres vivos neste mundo e so tu es capaz de mata-lo!");
    //Sleep(5000);
    printf("\nPara chegar a este boss vais ter de percorer um percurso de aventura para acabar o sofrimento do Mundo");
    //Sleep(5000);
    printf("\nComecas muito pobre, quase nao tens visao por isso vais ter de jogar usando texto.");
    //Sleep(5000);
    printf("\n\n\n");
}
if(file=='l'){
    int dump=loadingfile(&playerI, &invetorio_coisas, &x, &y);
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
        break;
        case 'I':
        case 'i':
        inventario_show(invetorio_coisas, posicao, &name);
        printf("\n%d", playerI.defense);
        printf("\n%d", playerI.classdamage);
        printf("\n%d", playerI.move);
        printf("\n%d", playerI.intelect);
        break;
        case 'P':
        case 'p':
        printf("\nClassDamage: %d", playerI.classdamage);
        printf("\nDefense: %d", playerI.defense);
        printf("\nSpeed: %.3f", playerI.move);
        printf("\nIntelect: %d", playerI.intelect);
        printf("\nLevel: %d\n.", playerI.level);
        break;
        case 'V':
        case 'v':
        printf("\nSaving...");
        int save=0;

        save=savingfile(&playerI, &invetorio_coisas, &x, &y);
        if(save==0){
            printf("\nSuccesfully saved!\n");
        }
        else{
            printf("\nSaving failed!\n");
        }
        
        printf("\n");
        break;
        case 'L':
        case 'l':
        printf("\nLoading...");
        int load=0;
        
        load=loadingfile(&playerI, &invetorio_coisas, &x, &y);
        if(load==0){
            printf("\nSuccesfully loaded!\n");
        }
        else{
            printf("\nLoading failed!\n");
        }
        
        printf("\n");
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
                enemyI.level = rand()%16+60;
            }
            if(y>14 && y<=37 && x<=25){//dessert
                enemyI.type_battle = rand()%2+1; // 1 and 2
                enemyI.type_specie = 30 + (rand()%3+1);
                enemyI.rarity = rand()%100+1;
                enemyI.level = rand()%21+20;
            }
            if(y>14 && y<=37 && x>25 && x <75){ // plains
                enemyI.type_battle = 1; // 1
                enemyI.type_specie = 20 + (rand()%2+1);
                enemyI.rarity = rand()%6+10;
            }
            if(y>14 && y<=37 && x>=75){ // ice forest
                enemyI.type_battle = rand()%4+3; // 3 and 4
                enemyI.type_specie = 40 + (rand()%2+1);
                enemyI.rarity = rand()%21+40;
            }
            if(y>37){ // starting zone
                int xx=(int)x;
                int yy=(int)y;
                if((yy==43&&xx>=47&&xx<=53)||(yy==44&&xx>=44&&xx<=56)||(yy==45&&xx>=41&&xx<=59)||(yy==46&&xx>=39&&xx<=61)||(yy==47&&xx>=36&&xx<=64)||(yy==48&&xx>=33&&xx<=67)||(yy==49&&xx>=30&&xx<=70)||(yy==50&&xx>=28&&xx<=72)){
                    enemyI.type_battle = (rand() % 2) * 2 + 1; // 1 and 3
                    enemyI.type_specie = 10 + (rand()%4+1);
                    enemyI.rarity = rand()%100+1;
                    enemyI.level = rand()%5+1;
                }
                else{
                    enemyI.type_battle = (rand() % 2) * 2 + 1; // 1 and 3
                    enemyI.type_specie = 10 + (rand()%4+1);
                    enemyI.rarity = rand()%100+1;
                    enemyI.level = rand()%16+5;
                }
            }
            batalha(enemyI, &playerI, inventorio_classdamage, chance, posicao, invetorio_coisas, xp, &xp_til_lvlup);
            printf("\n%d\n", xp_til_lvlup);
            //batalha();
            PvB_Chance=500;
            Sleep(1000);
        }
        else{
            PvB_Chance--;
        }
    }
    while(yes==0);
    return 0;
}







void menu(){
    printf("\n\n******************************************************"); //54
    printf("\n* W,A,S,D - Mover para Frente,Esquerda,Atras,Direita *");
    printf("\n* M - Mapa                                           *");
    printf("\n* I - Inventario                                     *");
    printf("\n******************************************************");
}


/*
make saving/loading fucntion ✔
make add_caracteristics function
saved
*/