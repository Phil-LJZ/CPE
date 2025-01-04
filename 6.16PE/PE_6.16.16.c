#include <stdio.h> 

int main(void){
    float sum1 = 100;
    float sum2 = 100;
    int i = 0;

    do{
        sum1 += 10;
        sum2 *= 1.05;
        i++;
    } while (sum1 >= sum2);
    
    printf("%f\n%f\n%d", sum1, sum2, i);
}