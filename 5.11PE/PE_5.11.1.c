#include <stdio.h>

#define Change 60

int main(void){
    int input;

    printf("请输入分钟：");
    scanf("%d", &input);

    while (input > 0)
    {
        printf("%d 分钟是 %d 小时 %d 分钟", input, input / Change, input % Change);
        printf("\n请输入分钟：");
        scanf("%d", &input);
    }
    return 0;
}