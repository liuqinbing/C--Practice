/*锁文件：通过锁文件来完成锁的功能*/
/*关键函数：*/
/*1、open(lock_file, O_RDWR|O_CREAT|O_EXCL, 0444);*/
/*2、unlink()*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

const char *lock_file = "./p7_2.txt";

int main()
{
    int file_desc;
    int tries = 5;//对临界资源的操作次数

    while(tries){
        file_desc = open(lock_file, O_RDWR|O_CREAT|O_EXCL, 0444);//如果文件不存在，则创建文件并返回文件描述符；如果文件存在，则创建文件失败，返回-1
        
        if(file_desc == -1)
        {
            printf("%d - %d - 临界区已被锁住，无法访问！\n", getpid(), tries);
            sleep(2);
        }
        else{
            printf("%d - %d - 临界区未被锁住，现在加锁后，进行访问！\n", getpid(), tries);
            /*
            在此操作临界资源
            */
           sleep(2);

           //执行完后解锁
           close(file_desc);//关闭文件
           unlink(lock_file);//删除文件
           printf("%d - %d - 访问完后解锁！\n", getpid(), tries);
           
           sleep(1);
           tries--;
        }
    }

    return 0;
}