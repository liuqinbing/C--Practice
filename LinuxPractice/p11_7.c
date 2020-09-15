/*发送信号：kill函数；闹钟功能：alarm函数；暂停执行直到收到信号：parse函数。但不推荐使用这些函数。*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

static int flag = 0;

void ding(int sig)
{
    flag = 1;
}

int main()
{
    signal(SIGALRM, ding);

    alarm(5);//5秒后向本进程发送一个SIGALRM信号

    printf("暂停5秒\n");
    pause();//把程序挂起，直到有一个信号出现

    //相当于以上代码的作用
    //sleep(5);
    //kill(getpid(), SIGALRM);

    if(flag)
    {
        printf("ding!\n");
    }

    printf("Done.\n");

    return 0;
}
