/*健壮的信号接口：sigaction函数。信号推荐使用函数*/
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void ouch(int sig)
{
    //信号处理函数中使用printf这样的函数是不安全的，最好使用书中表11-8中规定的函数

    printf("收到信号：%d\n", sig);
}

int main()
{
    struct sigaction act;

    act.sa_handler = ouch;//设置信号处理函数
    sigemptyset(&act.sa_mask);//设置信号集为空
    act.sa_flags = SA_RESETHAND;//处理一次信号后，恢复默认处理函数

    sigaction(SIGINT, &act, 0);//接收并处理信号（信号处理完后继续之前代码位置执行代码，不会从该函数后执行）

    printf("start!\n");

    while(1)
    {
        printf("hello world!\n");
        sleep(1);
    }

    return 0;
}