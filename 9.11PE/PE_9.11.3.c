#include <stdio.h>

void chline(char, int, int);

int main(void){
    char ch;
    int i1;
    int i2;

    printf("请输入字符、行数、列数：");
    scanf("%c %d %d", &ch, &i1, &i2);
    chline(ch, i1, i2);
    
    return 0;
}

void chline(char ch, int i, int j){
    int i1;
    int i2;

    for (i1 = 0; i1 <= j; i1++){
        for (i2 = 0; i2 <= i; i2++){
            putchar(ch);
        }
        putchar('\n');
    }
}