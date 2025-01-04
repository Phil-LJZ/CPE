#include <stdio.h>

int main(void){
    float cups;

    printf("请输入杯数：");
    scanf("%f", &cups);
    printf("%.f 杯等于 %f 品脱\n", cups, cups/2);
    printf("%.f 杯等于 %f 盅司\n", cups, cups*8);
    printf("%.f 杯等于 %f 大汤勺\n", cups, cups*8*2);
    printf("%.f 杯等于 %f 茶勺\n", cups, cups*8*2*3);

    return 0;
}