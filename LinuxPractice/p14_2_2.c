/*共享内存：shmget、shmat、shmdt和shmctl函数，实现进程间传输数据*/

/*消费者*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/sem.h>

//该联合体必须由程序员自己定义，提供给semctl函数使用
union semun {
    int val;//信号量的值
    struct semid_ds *buf;
    unsigned short *array;
};

static int sem_id;//信号量标识符

static void semaphore_p(int num);//对信号量减一（加锁）
static void semaphore_v(int num);//对信号量加一（解锁）
static int del_semvalue();//删除信号量

int main()
{
    void *shared_memory;//共享内存第一个字节的指针
    int shmid;//共享内存标识符
    char *buffer;

    //创建共享内存
    //第一个参数是键，不同进程可以通过它访问同一个共享内存（特殊值IPC_PRIVATE即0，使只有当前进程才能使用这个共享内存）
    //第二个参数是内存容量
    //第三个参数是权限标志
    shmid = shmget((key_t)3333, 1024, 0666 | IPC_CREAT);
    if(shmid == -1)
    {
        fprintf(stderr, "创建共享内存失败！\n");
        exit(EXIT_FAILURE);
    }

    //将共享内存连接到当前进程的地址空间中（否则无法使用该共享内存）
    //第一个参数是共享内存标识符
    //第二个参数是共享内存连接的地址（通常使用空指针，使其由系统来决定）
    //第三个参数是一组位标志，决定共享内存权限等
    shared_memory = shmat(shmid, (void  *)0, 0);
    if(shared_memory == (void *)-1)
    {
        fprintf(stderr, "创建共享内存失败！\n");
        exit(EXIT_FAILURE);
    }

    //将共享内存分配给buffer
    buffer = (char *)shared_memory;

    //获取信号量
    sem_id = semget((key_t)2222, 2, 0666 | IPC_CREAT);
    if(sem_id == -1)
    {
        printf("信号量获取失败！\n");
        return 0;
    }

    while(1)
    {
        semaphore_p(1);//信号量2，减一

        fprintf(stdout, "\n输出一些内容：%s", buffer);
        fflush(stdout);

        semaphore_v(0);//信号量1，加一

        if(strncmp(buffer, "end", 3) == 0)
        {
            break;
        }
    }

    //将当前的进程与共享内存分离
    if(shmdt(shared_memory) == -1)
    {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }

    //删除信号量（需放在最后使用信号量的地方删除）
    while(!del_semvalue())
    {
        sleep(2);
    }

    return 0;
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
