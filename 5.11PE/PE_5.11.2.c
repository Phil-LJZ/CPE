#include <stdio.h>

int main(void){
    int input;
    
    printf("请输入一个整数：");
    scanf("%d", &input);
    
    while (input > 0)
    {
        int i = 0;
        for (i = input; i <= input+10; i++){
            printf("%d\n", i);
        }
        printf("请输入一个整数：");
        scanf("%d", &input);
    }
    return 0;
}