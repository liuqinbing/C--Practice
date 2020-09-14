/*文件区域锁定：fcntl系统调用（F_GETLK，获取锁信息）*/
/*测试文件上的锁*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void show_lock_info(struct flock *region)
{
    printf("l_type:%d , ", region->l_type);
    printf("l_whence:%d , ", region->l_whence);
    printf("l_start:%d , ", region->l_start);
    printf("l_len:%d , ", region->l_len);
    printf("l_pid:%d\n", region->l_pid);
}

int main()
{
    int file_desc;
    struct flock region; //文件划分区域的flock结构
    int res;             //判断fcntl函数是否执行成功
    int start;           //开始位置
    int len = 20;         //区域大小

    //打开一个可读写文件
    file_desc = open("./p7_3.txt", O_RDWR | O_CREAT, 0666);
    if (file_desc == -1)
    {
        printf("打开一个可读写文件失败！\n");
        return 0;
    }

    for (start = 0; start < 60; start += len)
    {
        //测试的锁类型，共享（读）锁
        region.l_type = F_RDLCK;
        region.l_whence = SEEK_SET;
        region.l_start = start;
        region.l_len = len;
        region.l_pid = -1;

        printf("Testing F_RDLCK on region from %d to %d\n", start, start+len);

        res = fcntl(file_desc, F_GETLK, &region);
        if(res == -1)
        {
            printf("F_GETLK failed\n");
            return 0;
        }
        //检查pid是否被修改，被修改说明该区域已被上锁
        if(region.l_pid != -1)
        {
            printf("Can not set F_RDLCK!\n");
            show_lock_info(&region);
        }
        else{
            printf("Can set F_RDLCK!\n");
        }
    }

    for (start = 0; start < 60; start += len)
    {
        //测试的锁类型，独占（写）锁
        region.l_type = F_WRLCK;
        region.l_whence = SEEK_SET;
        region.l_start = start;
        region.l_len = len;
        region.l_pid = -1;

        printf("Testing F_WRLCK on region from %d to %d\n", start, start+len);

        res = fcntl(file_desc, F_GETLK, &region);
        if(res == -1)
        {
            printf("F_GETLK failed\n");
            return 0;
        }
        //检查pid是否被修改，被修改说明该区域已被上锁
        if(region.l_pid != -1)
        {
            printf("Can not set F_WRLCK!\n");
            show_lock_info(&region);
        }
        else{
            printf("Can set F_WRLCK!\n");
        }
    }

    close(file_desc);

    return 0;
}