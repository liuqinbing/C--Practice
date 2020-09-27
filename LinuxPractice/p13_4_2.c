/*被p13_4_1启动的新进程*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int flie_pipe;           //管道的文件描述符
    char buffer[BUFSIZ + 1]; //管道的内置缓冲区
    int n;

    //获取管道的文件描述符
    sscanf(argv[1], "%d", &flie_pipe);

    n = read(flie_pipe, buffer, BUFSIZ);
    if (n == -1)
    {
        fprintf(stderr, "read failed!\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Read %d bytes: %s\n", n, buffer);

    return 0;
}