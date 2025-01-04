#include <stdio.h>

int main(void){
    char start;
    char end;

    for (start = 'F'; start >= 'A'; start--){
        for (end = 'F'; end >= start; end--){
            printf("%c", end);
        }
        printf("\n");
    }
    
    return 0;
}