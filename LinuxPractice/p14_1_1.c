/*信号量是有计数功能的锁*/
/*(Linux)信号量：semget、semctl和semop函数，实现进程同步*/
/*Linux信号量都是针对成组的通用信号量进行操作，但一般我们只需要一个信号量*/


/*进入和离开临界区时都打印“X”，出现连续的两个相同字符，说明信号量有效*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sem.h>

//该联合体必须由程序员自己定义，提供给semctl函数使用
union semun {
    int val;//信号量的值
    struct semid_ds *buf;
    unsigned short *array;
};

static int sem_id;//信号量标识符

static void set_semvalue(int num, int val);//给信号量初始化初值
static int del_semvalue();//删除信号量
static void semaphore_p(int num);//对信号量减一（加锁）
static void semaphore_v(int num);//对信号量加一（解锁）

int main()
{
    char op_char = 'X';//当前进程输出的符号

    //创建信号量
    //第一个参数是键，不同进程可以通过它访问同一个信号量（特殊值IPC_PRIVATE即0，使只有当前进程才能使用这个信号量）
    //第二个参数是创建信号量的数目
    //第三个参数是一组标记，类似访问权限
    sem_id = semget((key_t)1234, 1, 0666 | IPC_CREAT);
    if(sem_id == -1)
    {
        printf("信号量创建失败！\n");
        return 0;
    }

    //在当前进程中初始化信号量的值，其他进程中不能初始化进程的值
    set_semvalue(0, 1);
    
    for(int i =0; i < 10; i++)
    {
        semaphore_p(0);//信号量-1
        
        fprintf(stdout, "%c", op_char);
        fflush(stdout);

        sleep(2);

        fprintf(stdout, "%c\n", op_char);
        fflush(stdout);

        semaphore_v(0);//信号量+1

        sleep(1);
    }

    //删除信号量
    while(!del_semvalue())
    {
        sleep(2);
    }

    return 0;
}

//给信号量初始化初值
static void set_semvalue(int num, int val)
{
    union semun sem_union;

    sem_union.val = val;
    
    //控制信号量信息
    //第一个参数是信号量标识符
    //第二个参数是信号量编号（由于是信号量组，所以需要编号来选择一个）
    //第三个参数是采取的动作（SETVAL表示设置信号量初值）
    //第四个参数是信号量要设置的初始参数
    if(semctl(sem_id, num, SETVAL, sem_union) == -1)
    {
        fprintf(stderr, "初始化信号量失败！\n");
        exit(EXIT_FAILURE);
    }
}

//删除信号量
static int del_semvalue()
{
    union semun sem_union;

    //控制信号量信息
    //第一个参数是信号量标识符
    //第二个参数是信号量编号（由于是信号量组，所以需要编号来选择一个）
    //第三个参数是采取的动作（IPC_RMID表示删除信号量标识符）
    //第四个参数是信号量要设置的初始参数
    if(semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
    {
        fprintf(stderr, "信号量删除失败！\n");
        return 0;
    }
    return 1;
}

//对信号量减一（加锁）
static void semaphore_p(int num)
{
    struct sembuf sem_b;

    sem_b.sem_num = num;//信号量编号
    sem_b.sem_op = -1;//对信号量值的操作
    sem_b.sem_flg = SEM_UNDO;//程序终止前自动释放信号量

    //修改信号量的值
    //第一个参数是信号量标识符
    //第二个参数是信号量的值的操作
    //第三个参数是操作的个数
    if(semop(sem_id, &sem_b, 1) == -1)
    {
        fprintf(stderr, "信号量p操作失败！\n");
        exit(EXIT_FAILURE);
    }
}

static void semaphore_v(int num)
{
    struct sembuf sem_b;

    sem_b.sem_num = num;//信号量编号
    sem_b.sem_op =  1;//对信号量值的操作
    sem_b.sem_flg = SEM_UNDO;//程序终止前自动释放信号量

    //修改信号量的值
    //第一个参数是信号量标识符
    //第二个参数是信号量的值的操作
    //第三个参数是操作的个数
    if(semop(sem_id, &sem_b, 1) == -1)
    {
        fprintf(stderr, "信号量v操作失败！\n");
        exit(EXIT_FAILURE);
    }
}