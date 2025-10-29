#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(){
    int card1, card2, card3, card4, card5;
    int totalP;
    int opTotalP;
    int repeat=0;
    char decision;
    char cardOne[10], cardTwo[10], cardThree[10], cardFour[10], cardFive[10];
    printf("\n\3\4\5\6BLACKJACK\6\5\4\3\n");
    printf("\nRULES:\nTo win you need to get more points than the dealer.\nDont surpass the limit of 21 points.\nEnjoy.");
    printf("\nLets start(Y/N) ");
    scanf(" %c", &decision);
    switch(decision){
        case 'y':
        case 'Y':
            printf("Lets go!");
            srand(time(NULL));
            card1=rand()%13+2; //generates numbers between 2 and 14
            switch(card1){//11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
            case 2:
               strcpy(cardOne, "Two");
               break;
            case 3:
               strcpy(cardOne, "Three");
               break;
            case 4:
               strcpy(cardOne, "Four");
               break;
            case 5:
               strcpy(cardOne, "Five");
               break;
            case 6:
               strcpy(cardOne, "Six");
               break;
            case 7:
               strcpy(cardOne, "Seven");
               break;
            case 8:
               strcpy(cardOne, "Eight");
               break;
            case 9:
               strcpy(cardOne, "Nine");
               break;
            case 10:
               strcpy(cardOne, "Ten");
               break;
            case 11:
               strcpy(cardOne, "Jack");
               break;
            case 12:
               strcpy(cardOne, "Queen");
               break;
            case 13:
               strcpy(cardOne, "King");
               break;
            case 14:
               strcpy(cardOne, "Ace");
               break;
    }
    if(card1==11||card1==12||card1==13){
        card1=10;
    }
    if(card1==14){
        card1=11;
    }
    card2=rand()%13+2;
    switch(card2){//222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
            case 2:
               strcpy(cardTwo, "Two");
               break;
            case 3:
               strcpy(cardTwo, "Three");
               break;
            case 4:
               strcpy(cardTwo, "Four");
               break;
            case 5:
               strcpy(cardTwo, "Five");
               break;
            case 6:
               strcpy(cardTwo, "Six");
               break;
            case 7:
               strcpy(cardTwo, "Seven");
               break;
            case 8:
               strcpy(cardTwo, "Eight");
               break;
            case 9:
               strcpy(cardTwo, "Nine");
               break;
            case 10:
               strcpy(cardTwo, "Ten");
               break;
            case 11:
               strcpy(cardTwo, "Jack");
               break;
            case 12:
               strcpy(cardTwo, "Queen");
               break;
            case 13:
               strcpy(cardTwo, "King");
               break;
            case 14:
               strcpy(cardTwo, "Ace");
               break;
    }
    if(card2==11||card2==12||card2==13){
        card2=10;
    }
    if(card2==14){
        card2=11;
    }
            totalP=card1+card2;
            printf("Your cards are: %s and %s\nTotal points: %d", cardOne, cardTwo, totalP);
            printf("\nDo you wish to take More cards or Open your cards?(M/O) ");
            scanf(" %c", &decision);
            do{
                if(decision=='M'||decision=='m'){ //333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
    card3=rand() % 13 + 2;
    switch(card3){
            case 2:
               strcpy(cardThree, "Two");
               break;
            case 3:
               strcpy(cardThree, "Three");
               break;
            case 4:
               strcpy(cardThree, "Four");
               break;
            case 5:
               strcpy(cardThree, "Five");
               break;
            case 6:
               strcpy(cardThree, "Six");
               break;
            case 7:
               strcpy(cardThree, "Seven");
               break;
            case 8:
               strcpy(cardThree, "Eight");
               break;
            case 9:
               strcpy(cardThree, "Nine");
               break;
            case 10:
               strcpy(cardThree, "Ten");
               break;
            case 11:
               strcpy(cardThree, "Jack");
               break;
            case 12:
               strcpy(cardThree, "Queen");
               break;
            case 13:
               strcpy(cardThree, "King");
               break;
            case 14:
               strcpy(cardThree, "Ace");
               break;
    }
    if(card3==11||card3==12||card3==13){
        card3=10;
    }
    if(card3==14){
        card3=11;
    }
    totalP=totalP+card3;
            if(totalP>21){
                    printf("Your cards are: %s, %s and %s\nTotal points: %d", cardOne, cardTwo, cardThree, totalP);
                    printf("\nYou have more than 21 points, which means...\n--------------------\nY O U  L O S E ! ! !\n--------------------\n");
            }
            else{
                printf("Your cards are: %s, %s and %s\nTotal points: %d", cardOne, cardTwo, cardThree, totalP);
                printf("\nDo you wish to take More cards or Open your cards?(M/O) ");
                scanf(" %c", &decision);
                do{
                if(decision=='M'||decision=='m'){//4444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
    card4=rand() % 13 + 2;
    switch(card4){
            case 2:
               strcpy(cardFour, "Two");
               break;
            case 3:
               strcpy(cardFour, "Three");
               break;
            case 4:
               strcpy(cardFour, "Four");
               break;
            case 5:
               strcpy(cardFour, "Five");
               break;
            case 6:
               strcpy(cardFour, "Six");
               break;
            case 7:
               strcpy(cardFour, "Seven");
               break;
            case 8:
               strcpy(cardFour, "Eight");
               break;
            case 9:
               strcpy(cardFour, "Nine");
               break;
            case 10:
               strcpy(cardFour, "Ten");
               break;
            case 11:
               strcpy(cardFour, "Jack");
               break;
            case 12:
               strcpy(cardFour, "Queen");
               break;
            case 13:
               strcpy(cardFour, "King");
               break;
            case 14:
               strcpy(cardFour, "Ace");
               break;
    }
    if(card4==11||card4==12||card4==13){
        card4=10;
    }
    if(card4==14){
        card4=11;
    }
    totalP=totalP+card4;
            if(totalP>21){
                    printf("Your cards are: %s, %s, %s and %s\nTotal points: %d", cardOne, cardTwo, cardThree, cardFour, totalP);
                    printf("\nYou have more than 21 points, which means...\n--------------------\nY O U  L O S E ! ! !\n--------------------\n");
            }
            else{
                printf("Your cards are: %s, %s, %s and %s\nTotal points: %d", cardOne, cardTwo, cardThree, cardFour, totalP);
                printf("\nDo you wish to take More cards or Open your cards?(M/O) ");
                scanf(" %c", &decision);
                do{
                if(decision=='M'||decision=='m'){//55555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
    card5=rand() % 13 + 2;
    switch(card5){
            case 2:
               strcpy(cardFive, "Two");
               break;
            case 3:
               strcpy(cardFive, "Three");
               break;
            case 4:
               strcpy(cardFive, "Four");
               break;
            case 5:
               strcpy(cardFive, "Five");
               break;
            case 6:
               strcpy(cardFive, "Six");
               break;
            case 7:
               strcpy(cardFive, "Seven");
               break;
            case 8:
               strcpy(cardFive, "Eight");
               break;
            case 9:
               strcpy(cardFive, "Nine");
               break;
            case 10:
               strcpy(cardFive, "Ten");
               break;
            case 11:
               strcpy(cardFive, "Jack");
               break;
            case 12:
               strcpy(cardFive, "Queen");
               break;
            case 13:
               strcpy(cardFive, "King");
               break;
            case 14:
               strcpy(cardFive, "Ace");
               break;
    }
    if(card5==11||card5==12||card5==13){
        card5=10;
    }
    if(card5==14){
        card5=11;
    }
    totalP=totalP+card5;
            if(totalP>21){
                    printf("Your cards are: %s, %s, %s and %s\nTotal points: %d", cardOne, cardTwo, cardThree, cardFour, totalP);
                    printf("\nYou have more than 21 points, which means...\n--------------------\nY O U  L O S E ! ! !\n--------------------\n");
            }
            else{
                printf("Your cards are: %s, %s, %s and %s\nTotal points: %d", cardOne, cardTwo, cardThree, cardFour, totalP);
                printf("\nNo more cards left so we will open...");
                opTotalP=rand()%10+12; //generates numbers between 12 and 21
                        printf("Dealer points: %d", opTotalP);
                        printf("\nWhich means...");
                        if(opTotalP<totalP){
                            printf("\n-----------------------------\nY O U  W I N ! ! ! \1 \1 \1\n-----------------------------\n");
                        }
                        else{
                            printf("\n--------------------\nY O U  L O S E ! ! !\n--------------------\n");
                        }
                        repeat=1;
            }
            repeat=0;
                }
                else if(decision=='O'||decision=='o'){
                        opTotalP=rand()%10+12; //generates numbers between 12 and 21
                        printf("Dealer points: %d", opTotalP);
                        printf("\nWhich means...");
                        if(opTotalP<totalP){
                            printf("\n-----------------------------\nY O U  W I N ! ! ! \1 \1 \1\n-----------------------------\n");
                        }
                        else{
                            printf("\n--------------------\nY O U  L O S E ! ! !\n--------------------\n");
                        }
                        repeat=0;
                }
                else{
                    repeat=1;
                    printf("Wrong Input! Try again... ");
                }
            }
            while(repeat==0);
            }
            repeat=0;
                }
                else if(decision=='O'||decision=='o'){
                        opTotalP=rand()%10+12; //generates numbers between 12 and 21
                        printf("Dealer points: %d", opTotalP);
                        printf("\nWhich means...");
                        if(opTotalP<totalP){
                            printf("\n-----------------------------\nY O U  W I N ! ! ! \1 \1 \1\n-----------------------------\n");
                        }
                        else{
                            printf("\n--------------------\nY O U  L O S E ! ! !\n--------------------\n");
                        }
                        repeat=0;
                }
                else{
                    repeat=1;
                    printf("Wrong Input! Try again... ");
                }
            }
            while(repeat==1);
            }
            repeat=0;
                }
                else if(decision=='O'||decision=='o'){
                        opTotalP=rand()%10+12; //generates numbers between 12 and 21
                        printf("Dealer points: %d", opTotalP);
                        printf("\nWhich means...");
                        if(opTotalP<totalP){
                            printf("\n-----------------------------\nY O U  W I N ! ! ! \1 \1 \1\n-----------------------------\n");
                        }
                        else{
                            printf("\n--------------------\nY O U  L O S E ! ! !\n--------------------\n");
                        }
                        repeat=0;
                }
                else{
                    repeat=1;
                    printf("Wrong Input! Try again... ");
                }
            }
            while(repeat==1);
            break;
        case 'n':
        case 'N':
            printf("\nOk...\2");
            break;
        default:
            printf("\nWrong Input");
    }
    return 0;
}
