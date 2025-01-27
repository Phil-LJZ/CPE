#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

int scan_num(FILE *);
bool is_on(int, int);

int main(void)
{
    SetConsoleOutputCP(65001); // 防止终端输出乱码
    fprintf(stdout, "请输入数字：");
    int num = scan_num(stdin);
    fprintf(stdout, "请输入序号：");
    int index = scan_num(stdin);

    fprintf(stdout, "%d\n", is_on(num, index));
    while (1)
    {
        fprintf(stdout, "请输入序号：");
        index = scan_num(stdin);
        fprintf(stdout, "%d", is_on(num, index));
    }

    return 0;
}

bool is_on(int num, int index)
{
    int i;
    
    if (index == 0)
    {
        return (bool)(num % 2);
    }
    for (i = 0; i < index; i++)
    {
        num >>= 1;
    }
    if (num % 2 == 0)
    {
        return false;
    }

    return true;
}
int scan_num(FILE * fp)
{
    int temp;

    fscanf(fp, "%d", &temp);
    while (getc(fp) != '\n')
    {
        ;
    }
    
    return temp;
}