#include <stdio.h>

int main() {
    int num;
    printf ("ENTER ANY NUMBER ");
    scanf ("%d", &num);

    if (num > 0){
        printf("%d is positive", num);
    }
    else if (num < 0){
        printf("%d is negative", num);
    }
    else{
        printf("%d equals 0", num);
    }

    return 0;
}
