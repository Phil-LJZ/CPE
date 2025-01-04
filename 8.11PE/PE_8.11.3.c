#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void){
    char string[40];
    int count = 0;
    char ch;
    int u_times = 0;
    int l_times = 0;

    printf("请输入文本：");
    while ((ch = getchar()) != EOF && count < 40)
    {
        if (isupper(ch))
        {
            u_times++;
        }
        else if (islower(ch))
        {
            l_times++;
        }
        string[count] = ch;
        count++;
    }
    
    printf("文本中有 %d 个大写字母 %d 个小写字母", u_times, l_times);
    return 0;
}