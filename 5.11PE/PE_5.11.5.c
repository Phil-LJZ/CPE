#include <stdio.h>

int main(void){
    int input;

    printf("请输入天数：");
    scanf("%d", &input);

    while (input > 0)
    {
        int i;
        int total;
        for (i = 1, total = 0; i <= input; total+=i, i++);
        printf("%d\n", total);
        printf("请输入天数：");
        scanf("%d", &input);
    }
    
    return 0;
}