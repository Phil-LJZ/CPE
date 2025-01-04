#include <stdio.h>

int main(void){
    int num;
    int isPN = 1;
    int i;

    printf("请输入整数：");
    while ((scanf("%d", &num)) == 1 && num > 0)
    {
        for (i = 1, isPN = 1; i < num && isPN == 1; i++){
            if (num % i == 0 && i != 1){
                isPN = 0;
                break;
            }
        }
        if (isPN){
            printf("是素数\n");
            printf("请输入整数：");
        }
        else{
            printf("不是素数\n");
            printf("请输入整数：");
        }
    }
    
    return 0;
}