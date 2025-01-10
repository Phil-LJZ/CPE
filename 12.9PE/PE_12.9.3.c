#include <stdio.h>
#include "pe12-2a1.h"
int main(void)
{
    int mode;
    int distance;
    float oil_quantity;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (getchar() != '\n')
    {
        continue;
    }
    while (mode >= 0)
    {
        get_info(mode, &distance, &oil_quantity);
        show_info(mode, &distance, &oil_quantity);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");

    return 0;
}