/*文件区域锁定：fcntl系统调用（F_SETLK，设置加锁和解锁）*/
/*在同一个区域加锁*/
/*1、在已有共享锁的区域加共享锁*/
/*F_GETLK获取的是先加的锁的数据，当先加的锁没了，后加的锁还在时，才获取后加的锁数据*/
/*2、独占锁无法加在已经有独占锁或共享锁的区域上，共享锁也不能加在已经有独占锁的区域上*/
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
    region1.l_type = F_RDLCK;
    region1.l_whence = SEEK_SET;
    region1.l_start = 20;
    region1.l_len = 20;

    res = fcntl(file_desc, F_SETLK, &region1);
    if (res == -1)
    {
        printf("Failed to lock region1!\n");
    }

    printf("在同一区域加共享锁\n");

    sleep(40);

    //区域1的flock结构，解锁
    region1.l_type = F_UNLCK;
    region1.l_whence = SEEK_SET;
    region1.l_start = 20;
    region1.l_len = 20;

    res = fcntl(file_desc, F_SETLK, &region1);
    if (res == -1)
    {
        printf("Failed to unlock region1!\n");
    }
    //解锁
    printf("Unlock file!\n");

    close(file_desc);

    return 0;
}