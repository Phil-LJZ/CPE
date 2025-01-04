#include <stdio.h>

int main(void){
    float mileage;
    float gq;

    printf("请输入总里程（英里）：");
    scanf("%f", &mileage);
    printf("请输入总耗油量（加仑）：");
    scanf("%f", &gq);
    printf("每加仑汽油行驶：%.1f（英里）\n", mileage/gq);
    printf("每公里消耗：%.1f（升）", (gq*3.785)/(mileage*1.609));

    return 0;
}