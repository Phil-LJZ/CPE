#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "参数不全");
        exit(EXIT_FAILURE);
    }

    FILE * fp_s;
    FILE * fp_t;
    static char temp[4096];
    size_t bytes = 0;
    
    fp_s = fopen(argv[1], "r");
    fp_t = fopen(argv[2], "a");

    while ((bytes = fread(temp, sizeof(char), 4096, fp_s)) > 0)
    {
        fwrite(temp, sizeof(char), bytes, fp_t);
    }

    return 0;
}