#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void get_fn(char *, int);

int main(void)
{
    int ch;
    FILE * fp;
    unsigned long count = 0;
    char file_name[20];

    fprintf(stdout, "请输入文件名：");
    get_fn(file_name, 20);
    if (*(file_name) == '\0')
    {
        fprintf(stderr, "文件名输入错误");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(file_name, "w+")) == NULL)
    {
        printf("打开文件错误: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    while ((ch  = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", file_name, count);

    return 0;
}
void get_fn(char * file_name, int size)
{
    char temp;
    int count = 0;
    while ((temp = getchar()) != '\n' && count < size)
    {
        file_name[count] = temp;
        count++;
    }
    file_name[count] = '\0';
}