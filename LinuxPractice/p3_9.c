/*错误处理：函数或系统调用运行失败原因存储在外部变量errno，使用perror和strerror函数获取错误*/
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("p3_9.txt", "r");//打开一个不存在的文件，发生错误，将错误信息保存在errno中

    if(fp == NULL)
    {
        //输出错误方式１
        perror("Error");//将errno中存储的当前错误，写到标准错误输出。（错误信息前加上""中的字符串，再加上：，再加上空格）

        //输出错误方式２
        fprintf(stderr, "Value of errno: %d\n", errno);//输出所属错误的编号
        fprintf(stderr, "Error: %s\n", strerror(errno));//输出错误原因
    }
    else{
        fclose(fp);
    }

    return 0;
}