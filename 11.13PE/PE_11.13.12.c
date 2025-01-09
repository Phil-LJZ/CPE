#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
    int words = 0;
    int upper_count = 0;
    int lower_count = 0;
    int punct_count = 0;
    int number_count = 0;
    char ch;
    bool is_word = true;

    printf("请输入文本：");
    while ((ch = getchar()) != EOF)
    {
        if (is_word && isalpha(ch))
        {
            words++;
            is_word = false;
        }
        else if (!is_word && isblank(ch) || !is_word && ispunct(ch))
        {
            is_word = true;
        }
        if (isupper(ch))
        {
            upper_count++;
        }
        else if (islower(ch))
        {
            lower_count++;
        }
        else if (ispunct(ch))
        {
            punct_count++;
        }
        else if (isdigit(ch))
        {
            number_count++;
        }
    }
    
    printf("************************\n");
    printf("(01) 单词数：%d\n", words);
    printf("(02) 大写字母数：%d\n", upper_count);
    printf("(03) 小写字母数：%d\n", lower_count);
    printf("(03) 标点符号数：%d\n", punct_count);
    printf("(04) 数字字符数：%d\n", number_count);

    return 0;
}