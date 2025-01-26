/* booksave.c -- saves structure contents in a file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAXTITL  40
#define MAXAUTL  40
#define MAXBKS   10             /* maximum number of books */
struct book {                   /* set up book template    */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void get_options(char *, FILE *);
void get_book_if(struct book *);
struct book * delete_book_inf(struct book *, int, int *);
void get_index(int *, FILE *);
void my_gets(char *, int, FILE *);
void my_scanf(float *, FILE *);
void output_library(struct book *, int);
void save_library(struct book *, int, FILE *);

int main(void)
{
    SetConsoleOutputCP(65001); // 防止终端输出乱码
    struct book * library = (struct book *) malloc(MAXBKS * sizeof(struct book)); /* array of structures     */
    struct book temp; // 缓存，临时记录输入
    int count = 0;
    int index = 0;
    FILE * pbooks;
    size_t size = sizeof (struct book);
    char options;
    
    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }
    
    rewind(pbooks);            /* go to start of file     */
    for (index = 0; index < MAXBKS && fread(&library[index], size, 1, pbooks) == 1; index++, count++)
    {
        if (!index)
            puts("Current contents of book.dat:");
        printf("（%.2d）%s by %s: $%.2f\n", index, library[index].title, library[index].author, library[index].value);
    }

    fprintf(stdout, "你想修改还是删除\n");
    fprintf(stdout, "(%c) 修改\n(%c) 删除\n", 'a', 'b' );
    fprintf(stdout, "请输入：");
    get_options(&options, stdin);
    while (options != 'q')
    {
        switch (options)
        {
        case 'a':
            fprintf(stdout, "请输入序号：");
            get_index(&index, stdin);
            if (index < count && index > 0)
            {
                get_book_if(&library[index]);
                save_library(library, count, pbooks);
                break;
            }
            fprintf(stderr, "超出数组范围\n");
            break;
        case 'b':
            fprintf(stdout, "请输入序号：");
            get_index(&index, stdin);
            if (index < count && index >= 0)
            {
                library = delete_book_inf(library, index, &count);
                printf("结构数组总数为%d\n", count);

                fprintf(stdout, "修改后的内容如下：\n");
                save_library(library, count, pbooks);
                break;
            }
            fprintf(stderr, "超出数组范围\n");
            break;

        default:
            break;
        }
        fprintf(stdout, "你想修改还是删除\n");
        fprintf(stdout, "(%c) 修改\n(%c) 删除\n", 'a', 'b' );
        fprintf(stdout, "请输入：");
        get_options(&options, stdin);
    }

    fclose(pbooks);
    free(library);
    
    return 0;
}

void my_gets(char * string, int size, FILE * fp)
{
    char temp;
    int count = 0;

    while ((temp = getc(fp)) != '\n')
    {
        if (count > size - 1)
        {
            while (getc(fp) != '\n')
            {
                continue;
            }
            string[size - 1] = '\0';
            break;
        }
        string[count] = temp;
        count++;
    }
    string[count] = '\0';
}
void my_scanf(float * num, FILE * fp)
{
    fscanf(fp, "%f", num);
    while (getc(stdin) != '\n')
    {
        ;
    }
}
void get_options(char * ch, FILE * fp)
{
    fscanf(fp, "%c", ch);
    while (getc(fp) != '\n')
    {
        ;
    }
}
void get_index(int * num, FILE * fp)
{
    fscanf(fp, "%d", num);
    while (getc(fp) != '\n')
    {
        ;
    }
}
void get_book_if(struct book * bf)
{
    fprintf(stdout, "请输入书名 : ");
    my_gets(bf->title, MAXTITL, stdin);
    fprintf(stdout, "请输入作者名 : ");
    my_gets(bf->author, MAXAUTL, stdin);
    fprintf(stdout, "请输入价格 : ");
    my_scanf(&(bf->value), stdin);
}
struct book * delete_book_inf(struct book * array, int target_sn, int * size)
{
    if (target_sn < * size && *size > 0)
    {
        struct book * new_array = (struct book *) malloc((*size - 1) * sizeof(struct book));
        int new_array_index;
        int array_index;
        
        for (new_array_index = 0, array_index = 0; new_array_index < *size - 1; new_array_index++, array_index++)
        {
            if (array_index == target_sn)
            {
                array_index++;
            }
            new_array[new_array_index] = array[array_index];
        }
        *size = *size - 1;
        free(array);
        return new_array;
    }

    return array;
}
void output_library(struct book * library, int size)
{
    for (int index = 0; index < size; index++)
    {
        if (!index)
            puts("Current contents of book.dat:");
        printf("（%.2d）%s by %s: $%.2f\n", index, library[index].title, library[index].author, library[index].value);
    }   
}
void save_library(struct book * library, int size, FILE * pbooks)
{
    fclose(pbooks);
    if ((pbooks = fopen("book.dat", "w+b")) == NULL)
    {
        fprintf(stderr, "打开文件失败");
        exit(EXIT_FAILURE);
    }
    rewind(pbooks);
    for (int i = 0; i < size; i++)
    {
        if (fwrite(library+i, sizeof(struct book), 1, pbooks) != 1)
        {
            fprintf(stderr, "写入文件失败");
            free(library);
            fclose(pbooks);
            exit(EXIT_FAILURE);
        }
        printf("（%.2d）%s by %s: $%.2f\n", i, library[i].title,
            library[i].author, library[i].value);
    }
}
