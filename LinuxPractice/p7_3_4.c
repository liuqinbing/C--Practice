/*文件区域锁定：fcntl系统调用（F_SETLKW，直到获取锁或收到信号才返回）*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int file_desc;
    struct flock region1; //文件划分区域1的flock结构
    int res;              //判断fcntl函数是否执行成功

    //打开一个可读写文件
    file_desc = open("./p7_3.txt", O_RDWR | O_CREAT, 0666);
    if (file_desc == -1)
    {
        printf("打开一个可读写文件失败！\n");
        return 0;
    }

    //区域1的flock结构，共享（读）锁
    region1.l_type = F_WRLCK;
    region1.l_whence = SEEK_SET;
    region1.l_start = 20;
    region1.l_len = 10;

    printf("使用F_SETLKW在同一区域加锁\n");

    res = fcntl(file_desc, F_SETLKW, &region1);
    if (res == -1)
    {
        printf("Failed to lock region1!\n");
    }
    else{
        printf("加锁成功\n");
        sleep(20);
    }

    //解锁
    printf("Unlock file!\n");
    close(file_desc);

    return 0;
}