#include <stdio.h>

int main(void){
    char string[255];
    char temp;
    int i = 0;
    int i1 = 0;

    printf("请输入文字：");
    scanf("%c", &temp);// hel
    while (temp != '\n')
    {
        string[i] = temp;
        i++;
        temp = 0;
        scanf("%c", &temp);
    }
    
    while (i1 < i)
    {
        printf("%c", string[i-1-i1]);
        i1++;
    }
    
}