#include <stdio.h>

int main(void){
    float input;

    printf("请输入一个double数：");
    scanf("%f", &input);

    while (input > 0)
    {
        printf("%f 的立方是 %f\n", input, input*input*input);
        printf("请输入一个double数：");
        scanf("%f", &input);
    }
    
    printf("done.");
    return 0;
}