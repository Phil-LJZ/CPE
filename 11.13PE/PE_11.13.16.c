#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 31

int main(int argc, char * argv[])
{
    char * p;
    char string[SIZE];
    char ch;
    int count = 0;
    
    printf("请输入文本：");
    while ((ch = getchar()) != EOF && count < SIZE - 1)
    {
        string[count] = ch;
        count++;
    }
    string [count] = '\0';
    if (strcmp("-p", argv[1]) == 0)
    {
        p = string;
        while (*p != '\0')
        {
            putchar(*p);
            p++;
        }
    }
    else if (strcmp("-u", argv[1]) == 0)
    {
        p = string;
        while (*p != '\0')
        {
            putchar(toupper(*p));
            p++;
        }
    }
    else if (strcmp("-l", argv[1]) == 0)
    {
        for(p = string; *p != '\0'; p++)
        {
            putchar(tolower(*p));
        }
    }
    else
    {
        for(p = string; *p != '\0'; p++)
        {
            putchar(*p);
        }
    }
    
    return 0;
}