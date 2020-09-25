/*二进制I/O：读写二进制数组，fread和fwrite函数；fopen、fclose、fseek、fflush*/
#include <stdio.h>
#include <string.h>

int main()
{
     char buffer[20];
    char c[20] = "hello world!";
    FILE *fp = fopen("p3_3.txt", "w+");

    //写入数据到文件，strlen获取字符串实际长度，不包含\0；sizeof获取字符数组长度，包含\0
    fwrite(c, strlen(c), 1, fp);

    //判断是否发生了错误
    if(ferror(fp)){
        printf("写入文件时发生错误\n");
        return 0;
    }

    //设置读写指针位置
    fseek(fp, 0, SEEK_SET);

    //读取文件，不会为字符串末尾添加\0
    fread(buffer, strlen(c), 1, fp);

    //判断是否发生了错误
    if(ferror(fp)){
        printf("读取文件时发生错误\n");
        return 0;
    }

    printf("%s\n", buffer);

    //关闭文件流，将缓冲数据全部写出（即隐含执行了一次fflush函数）
    fclose(fp);

    return 0;
}