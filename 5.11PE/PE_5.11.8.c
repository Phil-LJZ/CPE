#include <stdio.h>

int main(void){
    int input1;
    int input2;

    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand：");
    scanf("%d", &input2);
    printf("Now enter the first operand: ");
    scanf("%d", &input1);
    
    while (input1 > 0)
    {
        printf("%d %% %d is %d\n", input1, input2, input1 % input2);
        printf("Enter next number for first operand (<= 0 to quit) :");
        scanf("%d", &input1);
    }
    
    printf("done.");
    return 0;
}