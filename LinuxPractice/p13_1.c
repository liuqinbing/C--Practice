/*管道：popen和pclose函数，使用shell命令启动另一个进程，并用管道建立连接*/

/*获取新进程输出数据*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *read_fp;
    char buffer[BUFSIZ + 1]; //存放读取内容
    int chars_read;          //读取的字节数

    //启动uname -a命令，并获取该进程的输出流
    read_fp = popen("uname -a", "r");
    if (read_fp == NULL)
    {
        fprintf(stderr, "popen failed!\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        //读取uname -a命令输出的信息（只能获取一次数据）
        chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);

        if (chars_read > 0)
        {
            buffer[chars_read] = '\0';
            fprintf(stdout, "Reading %d:\n%s\n", chars_read, buffer);
        }
        else
        {
            break;
        }
    }

    //关闭管道的文件流（只有当被启动的进程运行结束后，才返回，返回退出码）（不能在该函数之前使用wait函数）
    pclose(read_fp);

    return 0;
}