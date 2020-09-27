/*命名管道：mkfifo函数，使用FIFO文件, 实现不相关进程间通信*/

/*从管道读取数据（写管道开启后未关闭，读管道会一直阻塞，等待写管道将全部内容写完）*/
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

    fprintf(stdout, "open FIFO O_RDONLY\n");

    //以只读的阻塞模式打开管道（即当另外的进程启动写管道时，才继续运行）
    pipe_fd = open(FIFO_NAME, O_RDONLY);
    if (pipe_fd == -1)
    {
        fprintf(stderr, "open FIFO O_RDONLY failed\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "start read\n");

    do
    {
        //从管道读取数据（直到写管道关闭，并且将管道中数据读取完毕才能结束）
        n = read(pipe_fd, buffer, PIPE_BUF);
        if (n == -1)
        {
            fprintf(stderr, "read failed!\n");
            exit(EXIT_FAILURE);
        }

        fprintf(stdout, "read\n");

        total += n;
    }while (n > 0);

    //关闭文件描述符，即关闭读管道
    close(pipe_fd);

    fprintf(stdout, "read %d bytes\n", total);

    //删除FIFO文件
    unlink(FIFO_NAME);

    return 0;
}