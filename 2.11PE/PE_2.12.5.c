#include <stdio.h>
void br(void);
void ic();
int main(void){
    br();
    printf(", ");
    ic();
    printf("\n");
    ic();
    printf("\n");
    br();
    printf("\n");
    getchar();
    return 0;
}

void br(void){
    printf("Brazil, Russia");
}
void ic(void){
    printf("India, China");
}