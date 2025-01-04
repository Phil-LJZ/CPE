#include <stdio.h>
#include <limits.h>

int main(void){
    printf("最大整数: %d\n", INT_MAX);
    printf("整数上溢：%d\n", INT_MAX*10);
    printf("\n");

    const float FLOAT_MAX = 2.0*32*32;
    const float FLOAT_MIN = -2.0*32*32*32*32;

    printf("单精度浮点数上溢：%f\n", FLOAT_MAX);
    printf("单精度浮点数下溢：%f\n", FLOAT_MIN);

    return 0;
}