#include <stdio.h>

int main(void){
    int height;

    printf("请输入身高（英寸）：");
    scanf("%d", &height);
    printf("您的身高是（厘米）：%f", height*2.54);

    return 0;
}