#include <stdio.h>

int main(void){
    float fpn;

    printf("输入一个浮点数：");
    scanf("%f", &fpn);
    printf("The input is %.1f or %.1e\n", fpn, fpn);
    printf("The input is %+.3f or %.3e\n", fpn, fpn);

    return 0;
}