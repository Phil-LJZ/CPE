#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void){
    char ch;
    printf("请输入文本:");
    ch = get_first();
    printf("%c", ch);
    
    return 0;
}

char get_first(void){
    char ch;
    char clean;

    while ((ch = getchar()) != EOF && isblank(ch))
    {
        continue;
    }
    while ((clean = getchar()) != '\n')
    {
        continue;
    }
    
    return ch;
}