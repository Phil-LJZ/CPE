#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define ID 0x01
#define FONTSIZE 0x0c
#define FONTSIZE_MASK 0x3fc03f
#define ALIGN 03
#define ALIGN_MASK 0x3fffc7
#define BOLD 0
#define BOLD_MASK 0x3ffffb
#define ITALIC 0
#define ITALIC_MASK 0x3ffffd
#define UNDERLINE 0
#define UNDERLINE_MASK 0x3ffffe

void show_fi(unsigned, FILE *);
void show_options(FILE *);
char get_font_size(FILE *);
unsigned char get_options(FILE *);

int main(void)
{
    unsigned int fi = 0;
    char option;
    char font_size;
    char align;

    fi |= UNDERLINE;
    fi |= ITALIC << 1;
    fi |= BOLD << 2;
    fi |= ALIGN << 3;
    fi |= FONTSIZE << 6;
    fi |= ID << 14;

    show_fi(fi, stdout);
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
                fi &= FONTSIZE_MASK;
                fi |= (font_size << 6);
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
                    case 'l': 
                        fi &= ALIGN_MASK;
                        fi |= 0 << 3;
                        break;
                    case 'c': 
                        fi &= ALIGN_MASK;
                        fi |= 1 << 3;
                        break;
                    case 'r': 
                        fi &= ALIGN_MASK;
                        fi |= 2 << 3;
                        break;
                    default: 
                        fi &= ALIGN_MASK;
                        fi |= 0 << 3;
                        break;
                }
                break;
            case 'b': 
                if ((fi >> 2) % 2)
                    fi |= 0x4; // 关闭位
                fi ^= 0x4; // 打开位
                break;
            case 'i': 
                if ((fi >> 1) % 2)
                    fi |= 0x2; // 关闭位
                fi ^= 0x2; // 打开位
                break;
            case 'u': 
                if (fi % 2)
                    fi |= 0x1; // 关闭位
                fi ^= 1; // 打开位
                break;
            default: break;
        }
        putc('\n', stdout);
        show_fi(fi, stdout);
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
void show_fi(unsigned fi, FILE * fp)
{
    fprintf(fp, "ID     SIZE    ALIGNMENT  B    I    U\n");
    fprintf(
        fp, "%d     %d      ", // %s         %s  %s  %s
        fi >> 14, (fi & (~FONTSIZE_MASK)) >> 6);
    switch ((fi & ~(ALIGN_MASK)) >> 3)
    {
        case 0: fprintf(fp, "%s         ", "left"); break;
        case 1: fprintf(fp, "%s         ", "center"); break;
        case 2: fprintf(fp, "%s         ", "right"); break;
        default: break;
    }
    switch ((fi & ~(BOLD_MASK)) >> 2)
    {
        case 0: fprintf(fp, "%s  ", "off"); break;
        case 1: fprintf(fp, "%s  ", "on"); break;
        default: break;
    }
    switch ((fi & ~(ITALIC_MASK)) >> 1)
    {
        case 0: fprintf(fp, "%s  ", "off"); break;
        case 1: fprintf(fp, "%s  ", "on"); break;
        default: break;
    }
    switch (fi & (~UNDERLINE_MASK))
    {
        case 0: fprintf(fp, "%s  ", "off"); break;
        case 1: fprintf(fp, "%s  ", "on"); break;
        default: break;
    }
}