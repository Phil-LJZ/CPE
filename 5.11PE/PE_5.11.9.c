#include <stdio.h>

void temperature(float input);

int main(void){
    float input;

    printf("请输入华氏温度：");

    while (scanf("%f", &input) == 1)
    {
        temperature(input);
        printf("请输入华氏温度：");
    }
    
}

void temperature(float input){
    printf("%.2f 华氏度\n", input);
    printf("%.2f 华氏度是 %.2f 摄氏度\n", input, 5.0 / 9.0 * (input - 32.0) );
    printf("%.2f 华氏度是 %.2f 开氏度\n", input, 5.0 / 9.0 * (input - 32.0) + 273.16);
}