#include <stdio.h>

int main(void){
    int age;

    printf("请输入你的年龄：");
    scanf("%d", &age);
    printf("\n你的生命已经过去 %d 秒", 31560000*age);

    return 0;
}