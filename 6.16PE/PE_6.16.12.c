#include <stdio.h>

int main(void){
    float end;
    float total1 = 1;
    float total2 = 1;

    printf("请输入上限：");
    scanf("%f", &end);

    for (float i = 2; i <= end; i++){
        total1 += 1/i;
    }
    for (float i = 2; i <= end; i++){
        total2 -= 1/i;
    }
    for (float i = 3; i <= end; i++){
        total2 += 1/i;
    }

    printf("total1:%f\ntotal2:%f", total1, total2);
}