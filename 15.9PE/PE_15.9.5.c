#include <stdio.h>
#include <limits.h>

void show(unsigned int);
unsigned int rotate_l(unsigned int, int);

int main(void)
{
    unsigned int num = 3221225473;
    int bits = 1;

    fprintf(stdout, "%u 向左旋转 %d 位等于 ", num, bits);
    show(rotate_l(num, bits));
    putc('\n', stdout);
    show(num);
    fprintf(stdout , "(原数)");

    return 0;
}

unsigned int rotate_l(unsigned int num, int bits)
{
    unsigned int temp = 0;
    int index;
    unsigned int unsigned_bits = sizeof(unsigned int) * 8 - 1;
    unsigned int sieve = 1;

    sieve <<= unsigned_bits;

    for (index = 0; index < bits; index++)
    {    
        temp |= ((num & sieve) >> unsigned_bits);
        num <<= 1;
        if (index != bits - 1)
        {
            temp <<= 1;
        }
    }
    temp |= num;

    return temp;
}
void show(unsigned int num)
{
    unsigned int temp = num % 2;
    unsigned int new_num = num >> 1;
    if (new_num > 0)
        show(new_num);
    fprintf(stdout, "%d", temp);
}