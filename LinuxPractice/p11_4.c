/*等待一个进程结束：使用wait函数等待子进程结束，并获取子进程返回的状态信息（waitpid函数可以指定具体的进程）*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    int exit_code;//退出码
    
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
            exit_code = 37;
            break;
        default:
            for(int i=0; i<3; i++){
                printf("I am parent\n");
                sleep(1);
            }
            exit_code = 0;
            break;
    }

    if(pid != 0)
    {
        int stat_val;//子进程返回的状态信息
        pid_t child_pid;

        child_pid = wait(&stat_val);//等待子进程结束，获取子进程main函数或exit函数返回的状态信息。执行成功，返回子进程pid

        if(WIFEXITED(stat_val))//使用宏来解释获取的状态信息
        {
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        }
        else{
            printf("Child finished abnormally\n");
        }
    }

    exit(exit_code);
}