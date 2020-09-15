/*启动新进程：system函数（通过shell来运行命令），这种方法少用*/
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("Running ps with system\n");

    system("ps ax");  //该命令执行结束，才返回继续执行后续的操作
    //system("ps ax &"); //ps命令一启动就返回

    printf("Done.\n");
    return 0;
}