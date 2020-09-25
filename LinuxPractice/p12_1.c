/*线程：pthread_create、pthread_join和pthread_exit函数*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_function(void *arg);

char message[] = "hello world!";

int main()
{
    int res;
    pthread_t a_thread;
    void *thread_result;

    //创建新线程
    //第一个参数是新线程的标识符
    //第二个参数是线程的属性
    //第三个参数是新线程从指定的thread_function函数开始执行
    res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
    if(res != 0)
    {
        perror("Thread creation failed");
        return 0;
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
    printf("全局变量message值：%s\n", message);

    return 0;
}

void *thread_function(void *arg)
{
    printf("线程开始执行\n");
    sleep(3);
    strcpy(arg, "Bye");

    pthread_exit("执行成功");//终止线程执行，返回值。注意！！！不能返回一个局部变量（因为调用该函数后，局部变量就不存在了）
}