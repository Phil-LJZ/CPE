#include <stdio.h>

int main(void){
    char name[10];

    printf("请输入你的名字：");
    scanf("%s", name);
    printf("*\"%s\"*\n", name);
    printf("*%20s*\n", name);
    printf("*%-20s*\n", name);
    printf("*%7s*", name);

    return 0;
}