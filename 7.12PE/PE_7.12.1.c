#include <stdio.h>

int main(void){
    char string[20];
    char ch;
    int i = 0;

    printf("请输入字符：");
    ch = getchar();
    while (ch != '#' && i < 20)
    {
        string[i] = ch;
        i++;
        ch = getchar();
    }
    
    printf("输出如下：\n%s", string);
}