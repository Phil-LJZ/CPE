#include <stdio.h>
int main(void){
    char string[50];
    char ch;
    int i = 0;

    printf("请输入字符串：");
    while ((ch = getchar()) != '#' && i < 50)
    {
        string[i] = ch;
        i++;
    }
    
    for (int a = 0; a < i ; a++){
        printf("%c", string[a]);
        if (a != 0 && (a+1) % 8 == 0){
            printf("  *8\n");
        }
    }
}