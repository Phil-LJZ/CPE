#include <stdio.h>

#define SPACE " "

int main(void){
    char end;
    char start;
    char temp;

    printf("请输入一个大写字母:");
    scanf("%c", &end);

    for (start = 'A'; start <= end; start++){
        for (temp = 0; temp <= (end - start); temp++)
            printf(" ");
        for (temp = 'A'; temp <= start; temp++)
            printf("%c", temp);
        for (temp = start; temp > 'A'; temp--)
            printf("%c", temp-1);
        printf("\n");
    }
}