/*底层文件操作：关于open、read、write、close系统调用*/
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char block[1024];
    int in, out;
    int nread;

    in = open("p3_1.in", O_RDONLY);//打开文件
    out = open("p3_1.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    while ((nread = read(in, block, sizeof(block))) > 0)//读取文件内容，存放于block，并在末尾添加\0
    {
        write(out, block, nread);//往文件写入内容
    }

    close(in);//关闭文件，释放文件描述符
    close(out);

    write(1, "fildes controll finished!\n", 27);

    char buffer[10];
    int n;

    write(1, "请输入内容:", 17);

    if((n = read(0, buffer, 10)) == -1)//从标准输入获取内容
    {
        write(2, "read error\n", 12);//往标准错误输出内容
    }

    write(0, "输出内容:", 14);
    if(write(1, buffer, n) != n)//往标准输出输出内容
    {
        write(2, "write error\n", 13);
    }

    exit(0);
}