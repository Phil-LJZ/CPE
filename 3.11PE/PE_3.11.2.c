#include <stdio.h>

int main(void){
    char character;

    printf("请输入一个ASCII码值:");
    scanf("%d", &character);
    printf("你输入的字符是：%c", character);

    return 0;
}