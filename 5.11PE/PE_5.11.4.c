#include <stdio.h>

int main(void){
    float input;
    
    printf("Enter a height in centimeters (<=0 to quit):");
    scanf("%f", &input);

    while (input > 0)
    {
        printf("%.1f cm = %.f feet, %.1f inches\n", input, input * 0.0328084, input * 0.39370079);
        printf("Enter a height in centimeters (<=0 to quit):");
        scanf("%f", &input);
    }
    
    return 0;
}