#include <stdio.h>
#include <string.h>

int main(void){
    char name[20];
    char surname[20];

    printf("Please input your 名字：");
    scanf("%s", name);
    printf("请输入你的姓：");
    scanf("%s", surname);
    printf("%s %s\n", name, surname);
    printf("%-*.d %-*.d\n", strlen(name), strlen(name), strlen(surname), strlen(surname));
    printf("%s %s\n", name, surname);
    printf("%*.d %*.d", strlen(name), strlen(name), strlen(surname), strlen(surname));

    return 0;
}