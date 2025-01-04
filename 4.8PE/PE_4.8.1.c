#include <stdio.h>

int main(void){
    char name[10];
    char surname[10];

    printf("请输入名和姓（名,姓)：");
    scanf("%s %s", name, surname);
    printf("%s,%s\n", name, surname);

    return 0;
}