#include <stdio.h>

void clean(char *);

int main(void){
    char string[20] = "hello world .";

    clean(string);
    for (int i = 0; string[i] != '\0'; i++){
        putchar(string[i]);
    }

    return 0;
}

void clean(char * s){
    char * p;

    while (*s != '\0')
    {
        if (*s == ' '){
            p = s;
            while (*p != '\0')
            {
                *p = *(p+1);
                p++;
            }
        }
        else{
            s++;
        }
    }
}