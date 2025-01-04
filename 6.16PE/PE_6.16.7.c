#include <stdio.h>
#include <string.h>

int main(void){
    char word[20];
    int count;

    printf("请输入一个单词:");
    scanf("%s", word);
    count = strlen(word)-1;

    for (int i = 0; count >= i; count--){
        printf("%c", word[count]);
    }

    return 0;
}