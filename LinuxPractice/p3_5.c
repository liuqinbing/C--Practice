/*一行字符串I/O：读取：fgets和gets函数；写入：fputs函数*/
#include <stdio.h>

int main()
{
    char str[2];

    FILE *in = fopen("p3_5.in", "r+");
    FILE *out = fopen("p3_5.out", "w+");

    while (1)
    {
        //读取字符串
        //1、遇到换行符时停止，也接收换行符
        //2、读取n-1个字符，末尾添加空字符\0
        //3、到达文件尾
        if (fgets(str, 2, in) != NULL)
        {
            printf("%s\n", str);

            //将字符串写入文件流，但不包括空字符\0
            fputs(str, out);
            //判断是否发生了错误
            if (ferror(out))
            {
                printf("写入文件时发生错误\n");
                return 0;
            }
        }else{
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
    }

    fclose(in);
    fclose(out);

    char s[10];

    printf("\n请输入字符串：");

    gets(s); //从标准输入获取字符串，gets没有限制字符个数，容易溢出传输缓冲区，少用

    printf("\n输出字符串：%s\n", s);

    return (0);
}