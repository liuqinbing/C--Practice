/*进入和离开临界区时都打印“O”，出现连续的两个相同字符，说明信号量有效*/
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

static void semaphore_p(int num);//对信号量减一（加锁）
static void semaphore_v(int num);//对信号量加一（解锁）

int main()
{
    char op_char = 'O';//当前进程输出的符号

    //创建信号量
    //第一个参数是键，不同进程可以通过它访问同一个信号量
    //第二个参数是创建信号量的数目
    //第三个参数是一组标记，类似访问权限
    sem_id = semget((key_t)1234, 1, 0666 | IPC_CREAT);
    if(sem_id == -1)
    {
        printf("信号量创建失败！\n");
        return 0;
    }
    
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