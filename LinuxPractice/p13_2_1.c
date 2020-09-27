/*管道：popen和pclose函数，使用shell命令启动另一个进程，并用管道建立连接*/

/*向新进程输入数据（最后一次输入数据后，另一个进程才继续执行，前面输入的全部数据当做一个整体）*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *write_fp;
    char buffer[BUFSIZ + 1]; //存放读取内容

    sprintf(buffer, "ahsknsofihssoifh");

    //运行p13_2_1进程，并向其输入内容
    write_fp = popen("./p13_2_2", "w");
    if (write_fp == NULL)
    {
        fprintf(stderr, "popen failed!\n");
        exit(EXIT_FAILURE);
    }

    //向文件流输入数据
    fwrite(buffer, sizeof(char), strlen(buffer), write_fp);

    //继续向文件流输入数据（最后一次输入数据后，另一个进程才继续执行，前面输入的全部数据当做一个整体）
    fwrite(buffer, sizeof(char), strlen(buffer), write_fp);

    //关闭管道的文件流（只有当被启动的进程运行结束后，才返回，返回退出码）（不能在该函数之前使用wait函数）
    pclose(write_fp);

    return 0;
}