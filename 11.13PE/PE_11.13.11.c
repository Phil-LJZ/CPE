#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 10
#define strings 5

char * get_string(int);
char get_options(void);
int get_first_word(char *);
void sort_ASCII(char *[], int);
void sort_size(char *[], int);
void sort_word_size(char *[], int);
void copy_array(char * [], char * [], int);
void printa(char *[], int);
void printb(char *[], int);
void printc(char *[], int);
void printd(char *[], int);

int main(void)
{
    char options;
    char * array[strings];
    char * string;

    printf("请输入字符串：");
    for (int i = 0; i < strings; i++)
    {
        array[i] = get_string(SIZE);
        printf("(%.2d) %s\n", i, array[i]);
        if (strings - i - 1 != 0)
        {
            printf("请再输入字符串（还剩%d个）：", strings - i - 1);
        }
    }

    fprintf(stdout, "a : 打印源字符串列表\n");
    fprintf(stdout, "b : 以ASCII中的顺序打印字符串\n");
    fprintf(stdout, "c : 按长度递增顺序打印字符串\n");
    fprintf(stdout, "d : 按字符串中第1个单词的长度打印字符串\n");
    fprintf(stdout, "请输入选项（a, b, c, d, q）：");
    while ( (options = get_options()) != 'q')
    {
        switch (options)
        {
        case 'a':
            printf("*****************\n");
            printa(array, strings);
            printf("*****************\n");
            break;
        case 'b':
            printf("*****************\n");
            printb(array, strings);
            printf("*****************\n");
            break;
        case 'c':
            printf("*****************\n");
            printc(array, strings);
            printf("*****************\n");
            break;
        case 'd':
            printf("*****************\n");
            printd(array, strings);
            printf("*****************\n");
            break;
        default:
            break;
        }
        fprintf(stdout, "a : 打印源字符串列表\n");
        fprintf(stdout, "b : 以ASCII中的顺序打印字符串\n");
        fprintf(stdout, "c : 按长度递增顺序打印字符串\n");
        fprintf(stdout, "d : 按字符串中第1个单词的长度打印字符串\n");
        fprintf(stdout, "请输入选项（a, b, c, d, q）：");
    }
    
    return 0;
}

char * get_string(int size)
{
    char * string = (char *) calloc(size + 1, sizeof(char));
    char ch;
    int count = 0;

    while (count < size && (ch = getchar()) != '\n')
    {
        *(string + count) = ch;
        count++;
    }
    if (count == size)
    {
        while ((ch = getchar()) != '\n')
        {
            continue;
        }
        
    }
    *(string + count) = '\0';
    
    return string;
}
char get_options(void)
{
    char ch;
    ch = getc(stdin);
    while (getchar() != '\n')
    {
        continue;
    }
    
    return ch;
}
int get_first_word_size(char * string)
{
    int count = 0;
    int index = 0;
    while (*(string + index) != '\0' && *(string + index) != ' ')
    {
        count++;
        index++;
    }
    
    return count;
}
void sort_ASCII(char * array[], int size)
{
    char * p;
    bool sorting_completed = false;
    int sorted_number = 0;
    int index = 0;
    int count = 0;

    while (!sorting_completed)
    {
        if (size > 1)
        {
            for(index = 0, sorted_number = 0; index < size - 1; index++)
            {
                if (strcmp(array[index], array[index + 1]) > 0)
                {
                    p = array[index];
                    array[index] = array[index + 1];
                    array[index + 1] = p;
                }
                if (strcmp(array[size - 1 - index - 1], array[size - 1 - index]) > 0)
                {
                    sorted_number--;
                }
                else
                {
                    sorted_number++;
                }
                if (sorted_number == (size - 1))
                {
                    sorting_completed = true;
                }
            }
        }
        else
        {
            sorting_completed = true;
        }
    }
}
void sort_size(char * array[], int size)
{
    char * p;
    bool sorting_completed = false;
    int sorted_number = 0;
    int index = 0;
    int count = 0;

    while (!sorting_completed)
    {
        if (size > 1)
        {
            for(index = 0, sorted_number = 0; index < size - 1; index++)
            {
                if (strlen(array[index]) > strlen(array[index + 1]))
                {
                    p = array[index];
                    array[index] = array[index + 1];
                    array[index + 1] = p;
                }
                if (strlen(array[size - 1 - index - 1]) > strlen(array[size - 1 - index]))
                {
                    sorted_number--;
                }
                else
                {
                    sorted_number++;
                }
                if (sorted_number == (size - 1))
                {
                    sorting_completed = true;
                }
            }
        }
        else
        {
            sorting_completed = true;
        }
    }
}
void sort_word_size(char * array[], int size)
{
    char * p;
    bool sorting_completed = false;
    int sorted_number = 0;
    int index = 0;
    int count = 0;

    while (!sorting_completed)
    {
        if (size > 1)
        {
            for(index = 0, sorted_number = 0; index < size - 1; index++)
            {
                if (get_first_word_size(array[index]) > get_first_word_size(array[index + 1]))
                {
                    p = array[index];
                    array[index] = array[index + 1];
                    array[index + 1] = p;
                }
                if (get_first_word_size(array[size - 1 - index - 1]) > get_first_word_size(array[size - 1 - index]))
                {
                    sorted_number--;
                }
                else
                {
                    sorted_number++;
                }
                if (sorted_number == (size - 1))
                {
                    sorting_completed = true;
                }
            }
        }
        else
        {
            sorting_completed = true;
        }
    }
}
void copy_array(char * source[], char * target[], int size)
{
    for (int i = 0; i < size; i++){
        *(target + i) = *(source + i);
    }
}
void printa(char * array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", array[i]);
    }
}
void printb(char * array[], int size)
{
    char *(*temp) = (char *(*)) calloc(size, sizeof(char *));

    copy_array(array, temp, size);
    sort_ASCII(temp, size);
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", temp[i]);
    }
    free(temp);
}
void printc(char * array[], int size)
{
    char *(*temp) = (char *(*)) calloc(size, sizeof(char *));

    copy_array(array, temp, size);
    sort_size(temp, size);
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", temp[i]);
    }
    free(temp);
}
void printd(char * array[], int size)
{
    char *(*temp) = (char *(*)) calloc(size, sizeof(char *));

    copy_array(array, temp, size);
    sort_word_size(temp, size);
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", temp[i]);
    }
    free(temp);
}