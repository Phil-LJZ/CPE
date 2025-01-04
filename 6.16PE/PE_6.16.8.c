#include <stdio.h>

int main(void){
    float num1;
    float num2;

    printf("请输入两个浮点数（用空格空开）：");

    while (scanf("%f %f", &num1, &num2) == 2)
    {
        printf("%f\n", (num1-num2)/(num1*num2));
        printf("请输入两个浮点数（用空格空开）：");
    }

    return 0;
}