#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

int count_letter(char, FILE * restrict);

int main(int argc, char * argv[])
{
    int count = 0;
    char ch;

    SetConsoleOutputCP(65001); // 防止终端输出乱码
    if (argc < 2)
    {
        fprintf(stderr, "参数不足");
        exit(EXIT_FAILURE);
    }
    else if (argc < 3)
    {
        ch = *(argv[1]);
        fprintf(stdout, "请输入字符(按下control+z推出)：");
        count = count_letter(ch, stdin);
        fprintf(stdout, "%c 字符在输入中出现了 %d 次", ch, count);
        return 0;
    }

    ch = *(argv[1]);

    FILE * fp;
    for (int i = 2; i < argc; i++)
    {
        fp = fopen(argv[i], "r");
        count = count_letter(ch, fp);
        fprintf(stdout, "%c 字符在 %s 文件中出现了 %d 次\n", ch, argv[i], count);
        fclose(fp);
        count = 0;
    }
    
    return 0;
}
int count_letter(char target_ch, FILE * restrict fp)
{
    int count = 0;
    char ch;

    while ((ch = getc(fp)) != EOF)
    {
        if (ch == target_ch)
        {
            count++;
        }
    }

    return count;
}