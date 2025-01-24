#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    SetConsoleOutputCP(65001); // 防止终端输出乱码

    if (argc < 3)
    {
        fprintf(stderr, "参数不足");
        exit(EXIT_FAILURE);
    }

    char * string = argv[1];
    char * file_name = argv[2];
    FILE * fp;
    char temp[256];
    
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        fprintf(stderr, "打开文件错误");
        exit(EXIT_FAILURE);
    }

    while(strstr(string, fgets(temp, 256, fp)) != EOF)
    {
        fputs(temp, stdout);
    }
    fclose(fp);

    return 0;
}