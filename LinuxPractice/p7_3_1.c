/*文件区域锁定：fcntl系统调用（F_SETLK，设置加锁和解锁）*/
/*使用fcntl锁定文件*/
/*本进程加的锁，只能由本进程解锁*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int file_desc;
    struct flock region1;//文件划分区域1的flock结构
    struct flock region2;//文件划分区域2的flock结构
    int res;//判断fcntl函数是否执行成功

    //创建并打开一个可读写文件
    file_desc = open("./p7_3.txt", O_RDWR|O_CREAT, 0666);
    if(file_desc == -1)
    {
        printf("创建并打开一个可读写文件失败！\n");
        return 0;
    }

    //文件写入数据
    for(int i = 0; i<100; i++)
    {
        write(file_desc, "A", 1);
    }

    //区域1的flock结构，共享（读）锁
    region1.l_type = F_RDLCK;
    region1.l_whence = SEEK_SET;
    region1.l_start = 20;
    region1.l_len = 10;

    //区域2的flock结构，独占（写）锁
    region2.l_type = F_WRLCK;
    region2.l_whence = SEEK_SET;
    region2.l_start = 40;
    region2.l_len = 10;

    //设置锁
    printf("Process %d locking file!\n", getpid());
    res = fcntl(file_desc, F_SETLK, &region1);
    if(res == -1)
    {
        printf("Failed to lock region1!\n");
    }
    res = fcntl(file_desc, F_SETLK, &region2);
    if(res == -1)
    {
        printf("Failed to lock region2!\n");
    }

    /*
    在此操作临界资源
    */
   sleep(20);

   //解锁
   printf("Unlock file!\n");
   close(file_desc);//关闭文件，释放文件描述符，即可解锁

   return 0;
}