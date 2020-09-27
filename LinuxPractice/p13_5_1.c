/*命名管道：mkfifo函数，使用FIFO文件, 实现不相关进程间通信*/

/*往管道写入数据*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "./p13_5_1_fifo"

int main()
{
    int pipe_fd;               //管道的文件描述符
    char buffer[PIPE_BUF + 1]; //管道的内置缓冲区，PIPE_BUF是FIFO文件存放数据最大长度
    int total = 0;
    int n;
    int res;

    memset(buffer, 'a', PIPE_BUF);
    buffer[PIPE_BUF] = '\0';

    //判断是否已存在该文件，不存在则创建
    if (access(FIFO_NAME, F_OK) == -1)
    {
        //创建FIFO文件
        res = mkfifo(FIFO_NAME, 0777);
        if (res != 0)
        {
            fprintf(stderr, "创建FIFO文件失败！\n");
            exit(EXIT_FAILURE);
        }
    }

    fprintf(stdout, "open FIFO O_WRONLY\n");

    //以只写的阻塞模式打开管道（即当另外的进程启动读管道时，才继续运行）
    pipe_fd = open(FIFO_NAME, O_WRONLY);
    if (pipe_fd == -1)
    {
        fprintf(stderr, "open FIFO O_WRONLY failed\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "start write\n");

    //传输数据
    while (total < (1024 * 30))
    {
        //往管道写入数据
        n = write(pipe_fd, buffer, PIPE_BUF);
        if (n == -1)
        {
            fprintf(stderr, "write failed!\n");
            exit(EXIT_FAILURE);
        }

        fprintf(stdout, "write\n");

        total += n;
    }

    //关闭文件描述符，即关闭写管道
    close(pipe_fd);

    fprintf(stdout, "write finished\n");

    return 0;
}