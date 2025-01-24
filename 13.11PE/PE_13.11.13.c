#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <ctype.h>

#define ROW 20
#define COL 30

int main(void)
{
    SetConsoleOutputCP(65001); // 防止终端输出乱码

    int row = 20;
    int col = 30;

    int raw_data[row][col+1];
    char data[row][col+1];
    char ch;
    FILE * fp_source;
    FILE * fp_target;

    if ((fp_source = fopen("PE_13_11_12.txt", "r")) == NULL) 
    {
        fprintf(stderr, "打开PE_13_11_12_txt文件错误\n");
        exit(EXIT_FAILURE);
    }
    if ((fp_target = fopen("PE_13_11_13_target.txt", "w")) == NULL)
    {
        fprintf(stderr, "创建PE_13_11_12_target.txt文件错误\n");
        exit(EXIT_FAILURE);
    }

    rewind(fp_source);

    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            ch = getc(fp_source);
            putc(ch, stdout);
            raw_data[row][col] = ch - 48;
        }
        getc(fp_source); // 清除末尾换行符
    }

    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            switch (raw_data[row][col])
            {
            case 0:
                data[row][col] = ' ';
                break;
            case 1:
                data[row][col] = '.';
                break;
            case 2:
                data[row][col] = '`';
                break;
            case 3:
                data[row][col] = ':';
                break;
            case 4:
                data[row][col] = '~';
                break;
            case 5:
                data[row][col] = '*';
                break;
            case 6:
                data[row][col] = '=';
                break;
            case 8:
                data[row][col] = '%';
                break;
            case 9:
                data[row][col] = '#';
                break;
            default:
                break;
            }
        }
        data[row][COL] = '\n';
    }
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL + 1; col++)
        {
            putc(data[row][col], fp_target);
        }
    }

    fclose(fp_source);
    fclose(fp_target);

    return 0;
}