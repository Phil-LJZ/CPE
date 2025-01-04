#include <stdio.h>

int main(void){
    float download_speed;
    float file_size;

    printf("请输入下载速度（Mb/s）：");
    scanf("%f", &download_speed);
    printf("请输入下载文件大小（MB）：");
    scanf("%f", &file_size);
    printf("At %.2f megabits per second, a file of %.2f megabytes\ndownloads in %.2f seconds.",
        download_speed, file_size, file_size / (download_speed / 8));
}