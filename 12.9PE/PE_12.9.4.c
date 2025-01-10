#include <stdio.h>

int funcition(void);

int main(void)
{
    int count;

    for (int i = 0; i < 10; i++)
    {
        count = funcition();
    }
    printf("funcition函数被调用了%d次", count);

    return 0;
}

int funcition(void)
{
    static int count = 0;

    count++;

    return count;
}