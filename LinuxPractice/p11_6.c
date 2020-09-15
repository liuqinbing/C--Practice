/*信号接收并处理：signal函数，但不推荐使用该函数。例：处理SIGINT信号（即Ctrl+C）*/
//第一次按Ctrl+C将处理方式恢复为默认行为，第二次按，则终止进程
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void ouch(int sig)
{
    //信号处理函数中使用printf这样的函数是不安全的，最好使用书中表11-8中规定的函数

    printf("收到信号：%d\n", sig);
    
    printf("恢复处理SIGINT信号的默认行为\n");
    signal(SIGINT, SIG_DFL);
}

int main()
{
    signal(SIGINT, ouch);//接收信号，并处理（信号处理完后继续之前代码位置执行代码，不会从该函数后执行）

    printf("start!\n");

    while(1)
    {
        printf("hello world!\n");
        sleep(1);
    }

    return 0;
}