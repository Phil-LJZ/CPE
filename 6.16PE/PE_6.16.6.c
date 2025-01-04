#include <stdio.h>

int main(void){
    int start;
    int end;
    
    printf("请输入一个整数（作为上限）：");
    scanf("%d", &start);
    printf("请输入一个整数（作为下线）：");
    scanf("%d", &end);

    for (; start <= end; start++)
        printf("%-10.d %-10.d %-10.d\n", start, start*start, start*start*start);

    return 0;
}