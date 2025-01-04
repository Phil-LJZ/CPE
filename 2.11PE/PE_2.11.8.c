#include <stdio.h>
void one_three(void);
void two(void);
void one_three(void){
    printf("one\n");
}
void two(void){
    printf("two\n");
}
int main(void){
    printf("starting now!\n");
    one_three();
    two();
    printf("three\n");
    return 0;
}