#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

int main(void)
{
    SetConsoleOutputCP(65001); // 防止终端输出乱码
    
    char file_name[20];
    long seek = 0L;
    char ch;
    int count = 0;
    FILE * fp;

    fprintf(stdout, "请输入文件名字：");
    while ((ch = getc(stdin)) != '\n')
    {
        file_name[count] = ch;
        count++;
    }
    file_name[count] = '\0';
    while (getc(stdin) != '\n')
    {
        continue;
    }
    fprintf(stdout, "文件名是%s\n", file_name);
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        fprintf(stderr, "打开文件错误");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "请输入想要跳转的位置：");
    fscanf(stdin, "%ld", &seek);
    while (getc(stdin) != '\n')
    {
        continue;
    }
    fseek(fp, seek, SEEK_SET);
    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            break;
        }
        putc(ch, stdout);
    }
    fclose(fp);
    
    return 0;
}