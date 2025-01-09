#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    double dishu = atof(argv[1]);
    int zhishou = atoi(argv[2]);
    double result = 1;

    if (dishu > 0 || dishu < 0)
    {
        if(zhishou >= 0)
        {
            for(int i = 0; i < zhishou; i++)
            {
                result *= dishu;
            }
        }
        else
        {
            for(int i = 0; i < zhishou; i--)
            {
                result *= (1 / dishu);
            }
        }
    }
    else if (dishu == 0)
    {
        printf("底数为0没有意义\n");
    }
    printf("%f", result);
    
    return 0;
}