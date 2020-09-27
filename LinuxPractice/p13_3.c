/*管道：底层实现pipe函数，和fork函数配合完成进程间通信*/
/*由于pipe是通过文件描述符实现的管道，而fork新建的进程可以共用文件描述符，所以可以实现进程间通信*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    int file_pipes[2];//管道使用的文件描述符
    char buffer[BUFSIZ + 1];//管道的内置缓冲区
    int n;

    //使用文件描述符创建管道
    if(pipe(file_pipes) == -1)
    {
        fprintf(stderr, "pipe failed!\n");
        exit(EXIT_FAILURE);
    }

    pid = fork();//复制当前进程来创建一个新进程，并且新进程也是从当前位置继续执行。执行成功，父进程返回新进程的pid，子进程返回0

    switch(pid)
    {
        case -1:
            perror("fork failed");
            return 0;
        case 0:
            //必须要通过文件描述符0来读取数据
            n = read(file_pipes[0], buffer, BUFSIZ);
            if(n == -1)
            {
                fprintf(stderr, "read failed!\n");
                exit(EXIT_FAILURE);
            }
            fprintf(stdout, "Read %d bytes: %s\n", n, buffer);
            break;
        default:
            //必须要通过文件描述符1来写入数据
            n = write(file_pipes[1], "hello world", 11);
            if(n == -1)
            {
                fprintf(stderr, "write failed!\n");
                exit(EXIT_FAILURE);
            }
            fprintf(stdout, "Write %d bytes\n", n);
            break;
    }

    return 0;
}