#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

unsigned int compute(char *);
void show(unsigned int);

int main(int argc, char * argv[])
{
    SetConsoleOutputCP(65001); // 防止终端输出乱码

    if (argc < 3)
    {
        fprintf(stderr, "参数不足");
        exit(EXIT_FAILURE);
    }

    unsigned int num1 = compute(argv[1]);
    printf("num1 = ");
    show(num1);
    putchar('\n');
    unsigned int num2 = compute(argv[2]);
    printf("num2 = ");
    show(num2);
    putchar('\n');
    
    printf("~ num1 = ");
    show((~num1)); // 如果num1为signed类型，那么取反之后num1为负值，所以输出为0
    putchar('\n');
    printf("~ num2 = ");
    show((~num2));
    putchar('\n');
    printf("num1 & num2 = ");
    show(num1 & num2);
    putchar('\n');
    printf("num1 | num2 = ");
    show(num1 | num2);
    putchar('\n');
    printf("num1 ^ num2 = ");
    show(num1 ^ num2);
    putchar('\n');

    return 0;
}

void show(unsigned int num)
{
    unsigned int temp = num % 2;
    unsigned int new_num = num >> 1;
    if (new_num > 0)
        show(new_num);
    fprintf(stdout, "%d", temp);
}
unsigned int compute(char * string)
{
    unsigned int size = 0;
    unsigned int index;
    unsigned int total = 0;
    unsigned int temp = 1;

    while (string[size] != '\0')
    {
        size++;
    }
    for (index = 0; index < size; index++, temp = 1)
    {
        if ((string[index] - 48) == 0)
        {
            continue;
        }
        for (int c = 0; c < (size - index - 1); c++)
        {
            temp *= 2;
        }
        temp *= (string[index] - 48);
        total += temp;
    }

    return total;
}