#include <stdio.h>

int main(void){
    char string[40];
    char ch;
    int count = 0;
    char c;

    printf("请输入文字：");
    while ((ch = getchar()) != EOF && count < 40)
    {
        string[count] = ch;
        count++;
    }

    for (int i = 0; i < count; i++){
        c = string[i];

        if (c != '\n' && c != '\t')
        {
            printf("<%c %d>", c, c);
        }
        else if (c == '\n')
        {
            printf("\n\\n\n");
        }
        else if (c == '\t')
        {
            printf("\\t");
        }

        if (i != 0 && (i+1) % 10 == 0)
        {
            printf("\n");
        }
    }

    return 0;
}