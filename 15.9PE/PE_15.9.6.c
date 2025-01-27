#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

struct font_inf {
    char id : 8;
    unsigned char size : 8;
    unsigned align : 2;
    unsigned int bold : 1;
    unsigned int italic : 1;
    unsigned int underline : 1;
};

void show_fi(struct font_inf *, FILE *);
void show_options(FILE *);
char get_font_size(FILE *);
unsigned char get_options(FILE *);

int main(void)
{
    struct font_inf fi = 
    {
        .id = 1,
        .size = 12,
        .align = 0,
        .bold = false,
        .italic = false,
        .underline = false
    };
    char option;
    char font_size;
    char align;

    show_fi(&fi, stdout);
    putc('\n', stdout);
    show_options(stdout);
    putc('\n', stdout);
    while ((option = get_options(stdin)) != 'q')
    {
        switch (option)
        {
            case 's':
                fprintf(stdout, "Enter font size(0-127): ");
                font_size = get_font_size(stdin);
                fi.size = font_size;
                break;
            case 'a':
                fprintf(
                    stdout, 
                    "Slect alignment:\n"
                    "l)left  c)center  r)right"
                    );
                align = get_options(stdin);
                switch (align)
                {
                    case 'l': fi.align = 0; break;
                    case 'c': fi.align = 1; break;
                    case 'r': fi.align = 2; break;
                    default : fi.align = 0; break;
                }
                break;
            case 'b': fi.bold = ~fi.bold; break;
            case 'i': fi.italic = ~fi.italic; break;
            case 'u':  fi.underline = ~fi.underline; break;
            default: break;
        }
        putc('\n', stdout);
        show_fi(&fi, stdout);
        putc('\n', stdout);
        show_options(stdout);
        putc('\n', stdout);
    }
    

    return 0;
}

unsigned char get_options(FILE * fp)
{
    char temp;

    temp = getc(fp);
    while (getc(fp) != '\n')
        ;
    
    return tolower(temp);
}
char get_font_size(FILE * fp)
{
    unsigned temp;
    
    fscanf(fp, "%d", &temp);
    while (getc(fp) != '\n')
        ;
    if (temp > 127 || temp < 0)
        return 0;
    
    return temp;
}
void show_options(FILE * fp)
{
    fprintf(
        fp, 
        "f) change font  s)change size  "
        "a) change alignment\nb)toggle bold  "
        "i)toggle italic u)toggle underline"
    );
}
void show_fi(struct font_inf * fi, FILE * fp)
{
    fprintf(fp, "ID     SIZE    ALIGNMENT  B    I    U\n");
    fprintf(
        fp, "%d     %d      ", // %s         %s  %s  %s
        fi->id, fi->size);
    switch (fi->align)
    {
        case 0: fprintf(fp, "%s         ", "left"); break;
        case 1: fprintf(fp, "%s         ", "center"); break;
        case 2: fprintf(fp, "%s         ", "right"); break;
        default: break;
    }
    switch (fi->bold)
    {
        case false: fprintf(fp, "%s  ", "off"); break;
        case true: fprintf(fp, "%s  ", "on"); break;
        default: break;
    }
    switch (fi->italic)
    {
        case false: fprintf(fp, "%s  ", "off"); break;
        case true: fprintf(fp, "%s  ", "on"); break;
        default: break;
    }
    switch (fi->underline)
    {
        case false: fprintf(fp, "%s  ", "off"); break;
        case true: fprintf(fp, "%s  ", "on"); break;
        default: break;
    }
}