/*管道：底层实现pipe函数，和exec函数配合完成进程间通信*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int file_pipes[2]; //管道使用的文件描述符
    char buffer[BUFSIZ];//保存文件描述符
    int n;

    //使用文件描述符创建管道
    if (pipe(file_pipes) == -1)
    {
        fprintf(stderr, "pipe failed!\n");
        exit(EXIT_FAILURE);
    }

    //必须要通过文件描述符1来写入数据
    n = write(file_pipes[1], "hello world", 11);
    if (n == -1)
    {
        fprintf(stderr, "write failed!\n");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Write %d bytes\n", n);

    //保存文件描述符
    sprintf(buffer, "%d", file_pipes[0]);

    //停止运行原进程，启动新进程，将文件描述符作为命令的参数传递给新进程
    //第一个参数是文件路径
    //之后的参数是命令，可以有很多个，使用(char *)0标记结束
    execl("p13_4_2", "p13_4_2", buffer, (char *)0);

    return 0;
}