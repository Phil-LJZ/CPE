#include <stdio.h>

int main(void){
    int m1;
    int m2;

    for (m1 = 0; m1 < 5; m1++){
        for (m2 = 0; m2 < m1+1; m2++){
            printf("$");
        }
        printf("\n");
    }

    return 0;
}