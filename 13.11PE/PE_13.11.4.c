#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void output_file(FILE *);

int main(int argc, char * argv[])
{
    SetConsoleOutputCP(65001); // 防止终端输出乱码
    if (argc < 2)
    {
        fprintf(stderr, "参数过少");
        exit(EXIT_FAILURE);
    }

    FILE * fp;

    for (int i = 1; i < argc; i++)
    {
        fprintf(stdout, "%s文件内容如下:\n", argv[i]);
        fp = fopen(argv[i], "r");
        output_file(fp);
        printf("\n");
        fclose(fp);
    }

    return 0;
}
void output_file(FILE * fp)
{
    char ch;
    while (fread(&ch, sizeof(char), 1, fp) > 0)
    {
        putc(ch, stdout);
    }
}