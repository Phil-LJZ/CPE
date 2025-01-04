#include <stdio.h>

int main(void){
    char string[40];
    char ch;
    int count = 0;
    int times = 0;

    printf("请输入文本：");
    while ((ch = getchar()) != '#' && count < 40)
    {
        if (ch == 'i' && count > 0){
            if (string[count-1] == 'e'){
                times++;
            }
        }
        string[count] = ch;
        count++;
    }
    
    for (int i = 0; i < count; i++){
        printf("%c", string[i]);
    }
    printf("次数%d", times);
}