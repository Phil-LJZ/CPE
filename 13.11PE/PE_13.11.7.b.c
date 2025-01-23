#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

bool file_put(FILE *);

int main(int argc, char * argv[])
{
    SetConsoleOutputCP(65001); // 防止终端输出乱码
    if (argc != 3)
    {
        fprintf(stderr, "参数错误");
        exit(EXIT_FAILURE);
    }

    FILE * fp1 = fopen(argv[1], "r");
    FILE * fp2 = fopen(argv[2], "r");
    bool fp1_done = false;
    bool fp2_done = false;
    
    while ((! fp1_done) || (! fp2_done))
    {
        if (! fp1_done)
        {
            fp1_done = file_put(fp1);
        }
        if (! fp2_done)
        {
            fp2_done = file_put(fp2);
        }
        printf("\n");
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
bool file_put(FILE * fp)
{
    char ch;

    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            return false;
        }
        putc(ch, stdout);
    }
    return true;
}