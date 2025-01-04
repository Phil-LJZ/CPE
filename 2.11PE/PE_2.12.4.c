# include <stdio.h>
void jolly(void);
void deny(void);//必须声明函数才能定义函数
int main(void){
    jolly();
    jolly();
    jolly();
    deny();
}
void jolly(void){
    printf("For he's a jolly good fellow\n");
}
void deny(void){
    printf("Which nobody can deny");
}