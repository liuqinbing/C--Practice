/*文件结束和错误标识符：ferror、feof和clearerr函数*/
#include <stdio.h>

int main()
{
    FILE *fp;
    char c;

    fp = fopen("p3_7.out", "w");//打开一个只写文件

    c = fgetc(fp);//进行读操作，发生错误
    if (ferror(fp))
    {
        printf("读取文件 时发生错误\n");
    }
    clearerr(fp);//清空错误标识符和文件结束符
    printf("清空错误\n");
    if (ferror(fp))
    {
        printf("读取文件：file.txt 时发生错误\n");
    }
    fclose(fp);

    return (0);
}