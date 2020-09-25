/*消息队列：msgget、msgsnd、msgrcv和msgctl函数*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>

struct my_msg_st
{
    long int my_msg_type;//消息类型
    char some_text[BUFSIZ];//消息的内容
};

int main()
{
    int msgid;
    struct my_msg_st some_data;

    //获取消息队列
    //第一个参数是键，不同进程可以通过它访问同一个消息队列（特殊值IPC_PRIVATE即0，使只有当前进程才能使用这个消息队列）
    //第二个参数是权限标志
    msgid = msgget((key_t)1111, 0666 | IPC_CREAT);
    if(msgid == -1)
    {
        fprintf(stderr, "消息队列获取失败！\n");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        //把消息队列中获取消息
        //第一个参数是消息队列标识符
        //第二个参数是消息的指针
        //第三个参数是消息的长度
        //第四个参数是接收消息的优先级
        //第五个参数是没有相应消息时，发生的事件
        if(msgrcv(msgid, (void *)&some_data, BUFSIZ, 0, 0) == -1)
        {
            fprintf(stdout, "msgrcv failed! \n");
            exit(EXIT_FAILURE);
        }

        fprintf(stdout, "\n输出内容：%s", some_data.some_text);

        if(strncmp(some_data.some_text, "end", 3) == 0)
        {
            break;
        }
    }

    if(msgctl(msgid, IPC_RMID, 0) == -1)
    {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
