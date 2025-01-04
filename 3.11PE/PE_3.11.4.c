#include <stdio.h>

int main(void){
    float fpn;

    printf("Enter a floating-point value:");
    scanf("%f", &fpn);
    printf("\nfixed-point natation: %f", fpn);
    printf("\nexponential notation: %e", fpn);
    printf("\np notation: %.2a", fpn);

    return 0;
}