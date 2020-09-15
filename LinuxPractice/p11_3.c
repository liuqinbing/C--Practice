/*启动新进程：复制原先进程，两个进程同时运行，fork函数*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    
    printf("fork program starting\n");

    pid = fork();//复制当前进程来创建一个新进程，并且新进程也是从当前位置继续执行。执行成功，父进程返回新进程的pid，子进程返回0

    switch(pid)
    {
        case -1:
            perror("fork failed");
            return 0;
        case 0:
            for(int i=0; i<5; i++){
                printf("I am child\n");
                sleep(1);
            }
            break;
        default:
            for(int i=0; i<3; i++){
                printf("I am parent\n");
                sleep(1);
            }
            break;
    }

    //I am child与I am parent交叉输出，所以两个进程同时运行

    return 0;
}