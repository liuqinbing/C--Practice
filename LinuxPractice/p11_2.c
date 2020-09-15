/*启动新进程：替换原先进程，原先进程不再运行，exec系列函数*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("Running ps with system\n");

    execlp("ps", "ps", "ax", (char *)0);//启动新进程后，原先进程不再运行

    printf("Done.\n");
    return 0;
}