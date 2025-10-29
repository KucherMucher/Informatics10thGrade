#include <stdio.h>
#include <windows.h>

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

FILE *savefile;

int main(){
    int inv[50]={0}; //use pointers if in function

    struct P_info playerI;

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

    savefile=fopen("savefiletest.txt", "w");
    if(!savefile){perror("Error pls help me"); Sleep(10000); return 1;}
    fprintf(savefile, 
        "level=%d\nvida=%d\ndefense=%d\nclassdamage=%d\nintelect=%d\nadd_defense=%d\nadd_classdamage=%d\nadd_intelect=%d\nmove=%f\nadd_move=%f\n", 
        playerI.level, playerI.vida, playerI.defense, playerI.classdamage, playerI.intelect, playerI.add_defense, playerI.add_classdamage, playerI.add_intelect, playerI.move, playerI.add_move);
    for(int i=0; i<50; i++){
        fprintf(savefile, "%d/", inv[i]);
    }
    fclose(savefile);

    /*
    // Reset values to test loading - thanks for doint it chatgpt :P
    playerI.level=0; playerI.vida=0; playerI.defense=0; playerI.classdamage=0; playerI.intelect=0;
    playerI.add_defense=0; playerI.add_classdamage=0; playerI.add_intelect=0; playerI.move=0.0; playerI.add_move=0.0;
    for(int i=0;i<50;i++) inv[i]=-1;
    */

    savefile=fopen("savefiletest.txt", "r");
    if(!savefile){perror("Error pls help me"); Sleep(10000); return 1;}
    fscanf(savefile, 
        "level=%d\nvida=%d\ndefense=%d\nclassdamage=%d\nintelect=%d\nadd_defense=%d\nadd_classdamage=%d\nadd_intelect=%d\nmove=%f\nadd_move=%f\n", 
        &playerI.level, &playerI.vida, &playerI.defense, &playerI.classdamage, &playerI.intelect, &playerI.add_defense, &playerI.add_classdamage, &playerI.add_intelect, &playerI.move, &playerI.add_move);
    for(int i=0; i<50; i++){
        fscanf(savefile, "%d/", &inv[i]);
    }
    fclose(savefile);

    printf("level=%d\nvida=%d\ndefense=%d\nclassdamage=%d\nintelect=%d\nadd_defense=%d\nadd_classdamage=%d\nadd_intelect=%d\nmove=%f\nadd_move=%f\n", 
        playerI.level, playerI.vida, playerI.defense, playerI.classdamage, playerI.intelect, 
        playerI.add_defense, playerI.add_classdamage, playerI.add_intelect, playerI.move, playerI.add_move);
    for(int i=0; i<50; i++){
        printf("%d/", inv[i]);
    }
    Sleep(10000);
    return 0;
}