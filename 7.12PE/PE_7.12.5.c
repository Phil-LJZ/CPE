#include <stdio.h>

int main(void){
    char string[40];
    int count = 0;
    int count1;
    char ch;

    printf("请输入内容：");
    while ((ch = getchar()) != '#' && count < 40)
    {
        switch (ch){
        case '.':{
            string[count] = '!';
            count++;
            count1++;
            break;
            }
        case '!':{
            string[count] = ch;
            if (count < 40){
                string[++count] = ch;
                count++;
                count1++;
                }
            break;
            }
        default:{
            string[count] = ch;
            count++;
            }}
    }
    
    for (int i = 0; i <= count; i++){
        printf("%c", string[i]);
    }
    printf("\n进行了%d次转换", count1);

    return 0;
}