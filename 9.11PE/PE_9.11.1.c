#include <stdio.h>

float min(float, float);

int main(void){
    float num1;
    float num2;
    float min1;

    printf("输入两个数：");
    scanf("%f %f", &num1, &num2);
    printf("最小值：%f", min(num1, num2));

    return 0;
}

float min(float num1, float num2){
    float min1;

    if (num1 <= num2){
        min1 = num1;
    }
    else{
        min1 = num2;
    }

    return min1;
}