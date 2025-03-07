/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * s_gets(char * st, int n);
#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   100              /* maximum number of books  */

struct book {                     /* set up book template     */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int compar1(const void *, const void *);
int compar2(const void *, const void *);

int main(void)
{
    struct book library[MAXBKS]; /* array of book structures */
    int count = 0;
    int index;
    
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;          /* clear input line         */
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
        printf("Here is the list of your books(按标题字母声明顺序):\n");
        qsort(library, count, sizeof(struct book), compar1);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
        printf("Here is the list of your books(按价格升序顺序):\n");
        qsort(library, count, sizeof(struct book), compar2);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);

    }
    else
    	printf("No books? Too bad.\n");
    
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}
int compar1(const void * p1, const void * p2)
{
    if (strcmp(((struct book *) p1)->title, ((struct book *) p2)->title) > 0)
        return 1;
    else if (strcmp(((struct book *) p1)->title, ((struct book *) p2)->title) < 0)
        return -1;
    else if (strcmp(((struct book *) p1)->title, ((struct book *) p2)->title) == 0)
        return 0;
}
int compar2(const void * p1, const void * p2)
{
    if (((struct book *) p1)->value < ((struct book *) p2)->value)
        return 1;
    else if (((struct book *) p1)->value > ((struct book *) p2)->value)
        return -1;
    else if (((struct book *) p1)->value == ((struct book *) p2)->value)
        return 0;
}