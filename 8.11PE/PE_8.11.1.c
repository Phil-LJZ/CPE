#include <stdio.h>

int main(void){
    char string[40];
    char ch;
    char c;
    int count = 0;

    printf("请输入文字：");
    while ((ch = getchar()) != EOF && count < 40)
    {
        string[count] = ch;
        count++;
    }
    
    for (int i = 0; i <= count; i++){
        c = string[i];
        printf("%c", c);
    }

    printf("\n你输入了 %d 个字符", count);
    printf("%c", string[count]);
    return 0;
}