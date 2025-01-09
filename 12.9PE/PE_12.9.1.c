#include <stdio.h>

void critic(int *);

int main(void)
{
    int units;

    printf("请输入数字：");
    scanf("%d", &units);
    while (units != 56)
    {
        critic(&units);
    }
    printf("猜对了！:)");
    
    return 0;
}

void critic(int * units)
{
    printf("猜错了 :(，请重新输入：");
    scanf("%d", units);
}