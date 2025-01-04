#include <stdio.h>

int main(void){
    char zimubiao[] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;

    for (i = 0; i <= sizeof(zimubiao)/sizeof(char)-2; i++){
        printf("%c\n", zimubiao[i]);
    }

    return 0;
}