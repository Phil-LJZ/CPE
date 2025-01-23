#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    SetConsoleOutputCP(65001); // 防止终端输出乱码
    if (argc < 2)
    {
        fprintf(stderr, "参数不足");
        exit(EXIT_FAILURE);
    }

    FILE * fp;
    char * file_name = argv[1];
    char ch;
    size_t bytes;
    long count = 0L;

    // if ((fp = fopen(argv[1], "a+")) != 0)
    // {
    //     fprintf(stderr, "打开文件错误");
    //     exit(EXIT_FAILURE);
    // }
    fp = fopen(argv[1], "r+");
    while ((bytes = fread(&ch, sizeof(char), 1, fp)) > 0)
    {
        ch = toupper(ch);
        fseek(fp, count, SEEK_SET);
        fwrite(&ch, sizeof(char), 1, fp);
        count++;
        fseek(fp, count, SEEK_SET);
    }

    fclose(fp);
    return 0;
}