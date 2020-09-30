/*多路转接：select系统调用，测试文件描述符集中，是否有可读、可写、错误状态的描述符，阻塞等待这样的描述符出现。还可设置超时，超时也会返回*/
#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    int result, nread;

    fd_set readfds, testfds;//文件描述符构成的集合
    struct timeval timeout;//超时值

    FD_ZERO(&readfds);//将集合清空
    FD_SET(0, &readfds);//标准输出添加到集合中

    while(1)
    {
        testfds = readfds;

        //超时值设为4.5秒
        timeout.tv_sec = 4;
        timeout.tv_usec = 500000;

        //阻塞，等待标准输入可读，超时设为4.5秒（调用返回时，会初始化timeout结构，和修改描述符集合为有符合状态变化的描述符集合）
        //第一个参数是集合中最大描述符值＋１，FD_SETSIZE是最大值
        //第二个参数是可读
        //第三个参数是可写
        //第四个参数是处于异常
        //第五个参数是超时
        //返回符合状态变化的描述符总数
        result = select(FD_SETSIZE, &testfds, (fd_set *)NULL, (fd_set *)NULL, &timeout);

        switch (result)
        {
        case 0:
            printf("超时\n");
            break;
        case -1:
            perror("select");
            exit(1);
        default:
            //是否是标准输入的发生活动
            if(FD_ISSET(0, &testfds))
            {
                ioctl(0, FIONREAD, &nread);//获取缓冲区有多少个字节

                //缓冲区没有内容，说明是标准输入关闭
                if(nread == 0)
                {
                    printf("客户关闭套接字\n");
                    exit(0);
                }

                nread = read(0, buffer, nread);
                buffer[nread] = '\0';
                printf("read %d from stdin: %s", nread, buffer);
            }
            break;
        }
    }
}