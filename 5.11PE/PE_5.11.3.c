#include <stdio.h>

int main(void){
    int input;

    printf("请输入天数：");
    scanf("%d", &input);

    while (input > 0)
    {
        printf("%d days are %d weeks, %d days\n", input, input / 7, input % 7);
        printf("请输入天数：");
        scanf("%d", &input);
    }
    
    return 0;
}