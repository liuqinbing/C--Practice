/*互斥量就是锁*/
/*互斥量：pthread_mutex_init、pthread_mutex_lock、pthread_mutex_unlock和pthread_mutex_destroy，实现多线程同步*/
/*一个互斥量单独使用，实现的是每次只能一个线程访问临界资源*/


/*实现生产者与消费者*/
/*一个互斥量无法完成未生产不消费，因为没有信号量那样的计数功能，但可以设一个全局变量来完成计数功能*/
/*两个互斥量实现一生产就消费，消费完才生产，未生产不消费*/
/*互斥量相当于二进制信号量，可完成锁的操作*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mutex1;//互斥量
pthread_mutex_t mutex2;
int apple_num;//剩余的苹果数量

void *thread_function(void *arg);

int main()
{
    printf("生产者与消费者示例\n\n");

    int res;
    pthread_t a_thread;
    void *thread_result;

    //初始化互斥量
    //第一个参数是互斥量
    //第二个参数设置互斥量的属性，控制互斥量的行为
    res = pthread_mutex_init(&mutex1, NULL);
    if(res != 0)
    {
        perror("Mutex initialization failed");
        return 0;
    }

    res = pthread_mutex_init(&mutex2, NULL);
    if(res != 0)
    {
        perror("Mutex initialization failed");
        return 0;
    }

    res = pthread_mutex_lock(&mutex2);//给mutex2互斥量加锁，控制消费者线程后执行
    if(res != 0)
    {
        perror("pthread_mutex_unlock failed");
        return 0;
     }

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
        res = pthread_mutex_lock(&mutex1);//给mutex1互斥量加锁
        if(res != 0)
        {
            perror("pthread_mutex_lock failed");
            return 0;
        }

        apple_num++;
        printf("生产一个苹果，现在剩余%d个\n", apple_num);
        sleep(1);

        res = pthread_mutex_unlock(&mutex2);//给mutex2互斥量解锁
        if(res != 0)
        {
            perror("pthread_mutex_unlock failed");
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

    res = pthread_mutex_destroy(&mutex1);//清理互斥量的所有资源（当被清理的互斥量未解锁，则会报错）
    if(res != 0)
    {
        perror("Mutex destroy failed");
        return 0;
    }

    res = pthread_mutex_unlock(&mutex2);//给mutex2互斥量解锁，因为线程最后加锁，需要解锁
    if(res != 0)
    {
        perror("pthread_mutex_unlock failed");
        return 0;
    }

    res = pthread_mutex_destroy(&mutex2);//清理互斥量的所有资源（当被清理的互斥量未解锁，则会报错）
    if(res != 0)
    {
        perror("Mutex destroy failed");
        return 0;
    }

    return 0;
}

void *thread_function(void *arg)
{
    int res;
    printf("线程开始执行\n");

    for(int i = 0; i < 10; i++)
    {
        res = pthread_mutex_lock(&mutex2);//给mutex2互斥量加锁
        if(res != 0)
        {
            perror("pthread_mutex_lock failed");
            return 0;
        }

        apple_num--;
        printf("消费一个苹果，还剩%d个\n", apple_num);
        sleep(1);

        res = pthread_mutex_unlock(&mutex1);//给mutex1互斥量解锁
        if(res != 0)
        {
            perror("pthread_mutex_unlock failed");
            return 0;
        }
    }

    pthread_exit(0);//终止线程执行，返回值。注意！！！不能返回一个局部变量（因为调用该函数后，局部变量就不存在了）
}