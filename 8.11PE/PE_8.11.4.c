#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void){
    int words_number = 0;
    int total_pure_letter = 0;
    int count = 0;
    char ch;
    char string[40];
    bool word_start = true;

    printf("请输入:");
    while ((ch = getchar()) != EOF && count < 40)
    {
        if (isalpha(ch) && word_start)
        {
            words_number++;
            word_start = false;
        }
        else if (isblank(ch) && !word_start)
        {
            word_start = true;
        }

        string[count] = ch;
        count++;
    }
    
    printf("单词数：%d\n", words_number);
    printf("%s", string); // 不建议使用
    return 0;
}