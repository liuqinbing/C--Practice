/*取消线程：pthread_cancel、pthread_setcancelstate和pthread_setcanceltype*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

int main()
{
    int res;
    pthread_t a_thread;
    void *thread_result;

    //创建新线程
    //第一个参数是新线程的标识符
    //第二个参数是线程的属性
    //第三个参数是新线程从指定的thread_function函数开始执行
    res = pthread_create(&a_thread, NULL, thread_function, NULL);
    if(res != 0)
    {
        perror("Thread creation failed");
        return 0;
    }

    sleep(3);

    printf("取消线程\n");
    res = pthread_cancel(a_thread);
    if(res != 0)
    {
        perror("Thread cancelation failed");
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

    return 0;
}

void *thread_function(void *arg)
{
    printf("线程开始执行\n");

    int res;

    //设置取消状态，PTHREAD_CANCEL_ENABLE为接收取消请求，PTHREAD_CANCEL_DISABLE为忽略取消请求
    //第二个参数用来获取之前的取消状态
    res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    if(res != 0)
    {
        perror("setcancelstate failed");
        return 0;
    }

    //设置取消类型，PTHREAD_CANCEL_ASYNCHRONOUS为接收到取消请求时立即执行
    //PTHREAD_CANCEL_DEFERRED为接收到取消请求时直到当前线程执行了某些函数(例：sleep)时才执行
    //第二个参数用来获取之前的取消类型
    res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    if(res != 0)
    {
        perror("setcanceltype failed");
        return 0;
    }

    while(1)
    {
        printf("线程执行中．．．\n");
        sleep(1);
    }

    pthread_exit("执行成功");//终止线程执行，返回值。注意！！！不能返回一个局部变量（因为调用该函数后，局部变量就不存在了）
}