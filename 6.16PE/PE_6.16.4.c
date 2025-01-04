#include <stdio.h>

int main(void){
    int i;
    int a;
    int d = 0;

    for (i = 1; i < 7; i++){
        for (a = d+i; d < a; d++){
            printf("%d ", d);
        }
        printf("\n");
    }

    return 0;
}