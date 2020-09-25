/*信号量是有计数功能的锁*/
/*（POSIX扩展的）信号量：sem_init、sem_wait、sem_post和sem_destroy，实现线程同步，也可被设置成多进程共享从而实现进程同步*/
/*sem_wait和sem_post是原子操作（即互不干扰）*/
/*一个信号量单独使用，实现的是控制对临界资源的访问顺序*/


/*实现生产者与消费者*/
/*一个信号量可以实现边生产边消费，未生产不消费*/
/*两个二进制信号量可以实现一生产就消费，消费完才生产，未生产不消费*/
/*二进制信号量相当于互斥量，可完成锁的操作*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

sem_t bin_sem1;//信号量
//sem_t bin_sem2;
int apple_num;//剩余的苹果数量

void *thread_function(void *arg);

int main()
{
    printf("生产者与消费者示例\n\n");

    int res;
    pthread_t a_thread;
    void *thread_result;

    //初始化信号量
    //第一个参数是信号量
    //第二个参数控制信号量的类型，0为只能被当前进程使用，否则就可以被多进程使用
    //第三个参数是信号量的初始值
    res = sem_init(&bin_sem1, 0, 0);
    if(res != 0)
    {
        perror("Semaphore initialization failed");
        return 0;
    }

    // res = sem_init(&bin_sem2, 0, 1);
    // if(res != 0)
    // {
    //     perror("Semaphore initialization failed");
    //     return 0;
    // }

    //创建新线程
    //新线程的标识符保存在a_thread中
    //新线程从指定的thread_function函数开始执行
    res = pthread_create(&a_thread, NULL, thread_function, NULL);
    if(res != 0)
    {
        perror("Thread creation failed");
        return 0;
    }

    for(int i = 0; i < 10; i++)
    {
        // res = sem_wait(&bin_sem2);//bin_sem2信号量-1，如果信号量为0，函数等待，直到信号量不为0为止
        // if(res != 0)
        // {
        //     perror("sem_wait failed");
        //     return 0;
        // }

        apple_num++;
        printf("生产一个苹果，现在剩余%d个\n", apple_num);
        sleep(1);

        res = sem_post(&bin_sem1);//bin_sem1信号量+1
        if(res != 0)
        {
            perror("sem_post failed");
            return 0;
        }
    }

    printf("等待线程执行完毕...\n");
    res = pthread_join(a_thread, &thread_result);//等待线程执行完毕，并获取线程返回值
    if(res != 0)
    {
        perror("Thread join failed");
        return 0;
    }

    printf("线程执行完毕\n");
    printf("线程返回值：%s\n", (char *)thread_result);

    res = sem_destroy(&bin_sem1);//清理信号量的所有资源（当被清理的信号量正在被其他线程等待，则会报错）
    if(res != 0)
    {
        perror("Semaphore destroy failed");
        return 0;
    }

    // res = sem_destroy(&bin_sem2);//清理信号量的所有资源
    // if(res != 0)
    // {
    //     perror("Semaphore destroy failed");
    //     return 0;
    // }

    return 0;
}

void *thread_function(void *arg)
{
    int res;
    printf("线程开始执行\n");

    for(int i = 0; i < 10; i++)
    {
        res = sem_wait(&bin_sem1);//bin_sem1信号量-1
        if(res != 0)
        {
            perror("sem_wait failed");
            return 0;
        }

        apple_num--;
        printf("消费一个苹果，还剩%d个\n", apple_num);
        sleep(2);

        // res = sem_post(&bin_sem2);//bin_sem2信号量+1
        // if(res != 0)
        // {
        //     perror("sem_post failed");
        //     return 0;
        // }
    }

    pthread_exit(0);//终止线程执行，返回值。注意！！！不能返回一个局部变量（因为调用该函数后，局部变量就不存在了）
}