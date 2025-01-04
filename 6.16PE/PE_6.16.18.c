#include <stdio.h>

int main(void){
    int n = 5;
    int year = 1;

    while (n <= 150)
    {
        n -= year;
        n *= 2;
        year++;
    }
    
    printf("%d", year);
}