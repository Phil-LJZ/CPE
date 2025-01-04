#include <stdio.h>

int main(void){
    float height;
    char name[20];

    printf("输入你的名字：");
    scanf("%s", name);
    printf("输入你的身高（厘米）：");
    scanf("%f", &height);
    printf("%s, you are %f m tall", name, height / 100);

    return 0;
}