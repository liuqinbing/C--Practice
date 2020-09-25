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
    char buffer[BUFSIZ];

    //创建消息队列
    //第一个参数是键，不同进程可以通过它访问同一个消息队列（特殊值IPC_PRIVATE即0，使只有当前进程才能使用这个消息队列）
    //第二个参数是权限标志
    msgid = msgget((key_t)1111, 0666 | IPC_CREAT);
    if(msgid == -1)
    {
        fprintf(stderr, "消息队列创建失败！\n");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        fprintf(stdout, "\n请输入内容：");
        fgets(buffer, BUFSIZ, stdin);

        some_data.my_msg_type = 1;

        strcpy(some_data.some_text, buffer);

        //把消息添加到消息队列中
        //第一个参数是消息队列标识符
        //第二个参数是消息的指针
        //第三个参数是消息的长度
        //第四个参数是消息队列满或到达系统限制范围时，发生的事件
        if(msgsnd(msgid, (void *)&some_data, BUFSIZ, 0) == -1)
        {
            fprintf(stdout, "msgsnd failed! \n");
            exit(EXIT_FAILURE);
        }

        if(strncmp(buffer, "end", 3) == 0)
        {
            break;
        }
    }

    return 0;
}
