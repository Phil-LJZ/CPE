#include <stdio.h>

int main(void){
    int num1;
    int num2;
    int total;

    printf("请输入两个数字（上限和下限）：");
    while (scanf("%d %d", &num1, &num2) == 2)
    {
        for (total = 0; num1 <= num2; num1++){
            total += num1*num1;
            }
        printf("%d\n", total);
        printf("请输入两个数字（上限和下限）：");
    }
    
    return 0;
}