/*线程的属性：pthread_attr_init、pthread_attr_destroy和一些pthread_attr_set...、pthread_attr_get...函数*/
/*设置脱离线程，即新线程无需返回给主线程，不能调用pthread_join来获得新线程的的退出状态*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

int thread_finished = 0;//线程是否结束的状态

int main()
{
    int res;
    pthread_t a_thread;
    void *thread_result;
    pthread_attr_t thread_attr;

    //初始化线程属性
    res = pthread_attr_init(&thread_attr);
    if(res != 0)
    {
        perror("Attribute initialization failed");
        return 0;
    }

    //设置线程属性为脱离状态（不能调用pthread_join来获得新线程的的退出状态）
    res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
    if(res != 0)
    {
        perror("Setting attribute  failed");
        return 0;
    }

    //创建新线程
    //第一个参数是新线程的标识符
    //第二个参数是线程的属性
    //第三个参数是新线程从指定的thread_function函数开始执行
    res = pthread_create(&a_thread, &thread_attr, thread_function, NULL);
    if(res != 0)
    {
        perror("Thread creation failed");
        return 0;
    }

    //清理并回收线程属性
    res = pthread_attr_destroy(&thread_attr);
    if(res != 0)
    {
        perror("attribute destroy failed");
        return 0;
    }

    while(!thread_finished)
    {
        printf("等待线程结束．．．\n");
        sleep(1);
    }

    return 0;
}

void *thread_function(void *arg)
{
    printf("线程开始执行\n");
    sleep(3);
    thread_finished = 1;
}
