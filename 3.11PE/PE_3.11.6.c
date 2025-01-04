#include <stdio.h>

int main(void){
    int input_quart;

    printf("请输入夸脱数：");
    scanf("%d", &input_quart);
    printf("%d 夸脱水有 %e 个水分子", input_quart, input_quart*950/3.0e-23);

    return 0;
}