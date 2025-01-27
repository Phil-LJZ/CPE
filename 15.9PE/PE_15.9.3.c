#include <stdio.h>

int count_bit(int);

int main(void)
{

    printf("%d", count_bit(43));

    return 0;
}

int count_bit(int num)
{
    int temp = num;
    int count = 0;

    while (temp > 0)
    {
        if ((temp % 2) != 0)
            count++;
        temp >>= 1;
    }
    
    return count;
}