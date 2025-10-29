#include <stdio.h>
#include <stdlib.h>

void ip();
void time();

int main(){
    int option;
    printf("1 - IPs\n2 - Time");
    scanf("%d", &option);
    switch(option){
    case 1:
        ip();
        break;
    case 2:
        time();
        break;
    }
    return 0;
}

void ip(){
    int w=0, x=0, y=0, z=0;
    int ips=1;
    do{
        printf("%d.%d.%d.%d\n", w, x, y, z);
        if(w!=255 || x!=255 || y!=255 || z!=255){
            if(x==255){
            w++;
            x=0;
            }
            else{
                if(y==255){
                    x++;
                    y=0;
                }
                else{
                    if(z==255){
                        y++;
                        z=0;
                    }
                    else{
                        z++;
                    }
                }
            }
        }
        ips++;
    }
    while(w!=255 || x!=255 || y!=255 || z!=255);
    printf("%d", ips);
}

void time(){
    int s=0, ms=0;
    int mcrs=1;
    do{
        printf("%d.%d\n", s, ms);
        if(ms==999){
            ms=0;
            s++;
        }
        else{
            ms++;
        }
        mcrs++;

    }
    while(s!=60);
    printf("%d", mcrs);
}
