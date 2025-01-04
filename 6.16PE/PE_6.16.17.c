#include <stdio.h>

int main(void){
    float money = 100;
    int year = 0;

    while (money > 0)
    {
        money *= 1.08;
        money -= 10;
        year++;
    }
    
    printf("%d", year);
}