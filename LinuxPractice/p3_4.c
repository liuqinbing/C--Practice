/*一次一个字符的I/O：读取：fgetc、getc和getchar()函数；写入：fputc、putc和putchar函数*/
#include <stdio.h>

int main()
{
    int c;

    //打开文件
    FILE *in = fopen("LinuxPractice/p3_4.in", "r+");
    FILE *out = fopen("LinuxPractice/p3_4.out", "w+");

    while (1)
    {
        c = fgetc(in); //取出一个字节，当做一个字符返回，并且该无符号字符被强转成int型再返回

        if (c == EOF)
        {
            //判断是否发生了错误
            if (ferror(in))
            {
                printf("读取文件时发生错误\n");
                return 0;
            }

            //判断是否到达文件尾
            if (feof(in))
            {
                break;
            }
        }

        printf("%c | ", c);

        fputc(c, out); //把一个字符写入输出文件流
    }
    fclose(in);
    fclose(out);

    printf("\n请输入字符：");
    c = getchar();//从标准输入读取一个字符

    printf("\n输出的字符：");
    putchar(c);//将一个字符写到标准输出
    printf("\n");

    return 0;
}