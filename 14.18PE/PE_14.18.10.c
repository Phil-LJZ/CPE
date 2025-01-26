#include <stdio.h>

void fun1(void);
void fun2(void);
void fun3(void);
void fun4(void);
char get_options(FILE *);

int main(void)
{
    char option;
    void (*pf[4]) (void) = {
        fun1, fun2, fun3, fun4
    };

    fprintf(stdout, "这是一个函数菜单\n");
    fprintf(
        stdout, "%s\n%s\n%s\n%s\n",
        "a) void fun1(void)", 
        "b) void fun2(void)",
        "c) void fun3(void)",
        "d) void fun4(void)"
    );
    fprintf(stdout, "请输入选项（输入q退出）：");
    option = get_options(stdin);
    while (option != 'q')
    {
        switch (option)
        {
        case 'a':
            pf[0]();
            break;
        case 'b':
            pf[1]();
            break;
        case 'c':
            pf[2]();
            break;
        case 'd':
            pf[3]();
            break;
        
        default:
            break;
        }
        fprintf(stdout, "这是一个函数菜单\n");
        fprintf(
            stdout, "%s\n%s\n%s\n%s\n",
            "a) void fun1(void)", 
            "b) void fun2(void)",
            "c) void fun3(void)",
            "d) void fun4(void)"
        );
        fprintf(stdout, "请输入选项（输入q退出）：");
        option = get_options(stdin);
    }

    return 0;
}

void fun1(void)
{
    fprintf(stdout, "这里是fun1\n");
}
void fun2(void)
{
    fprintf(stdout, "这里是fun2\n");
}
void fun3(void)
{
    fprintf(stdout, "这里是fun3\n");
}
void fun4(void)
{
    fprintf(stdout, "这里是fun4\n");
}
char get_options(FILE * fp)
{
    char ch;
    fscanf(fp, "%c", &ch);
    while (getc(fp) != '\n')
    {
        ;
    }
    return ch;
}