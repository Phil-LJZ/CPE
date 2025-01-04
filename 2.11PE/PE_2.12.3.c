#include <stdio.h>
int main(void){
    int n1 = 365;
    int age;

    printf("input your age: ");
    scanf("%d", &age);
    printf("\nyour age is %d\n", age*n1);

    return 0;
}