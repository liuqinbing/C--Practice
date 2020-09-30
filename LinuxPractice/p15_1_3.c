/*使用select实现一个可与多客户同时交互的服务器*/
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    int server_sockfd, client_sockfd;  //套接字描述符
    int server_len, client_len;        //套接字地址长度
    struct sockaddr_in server_address; //服务端套接字地址
    struct sockaddr_in client_address; //客户端地址
    int result;                        //select调用结果
    fd_set readfds, testfds;           //套接字构成的集合

    // １、为服务器创建监听套接字
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //设置套接字地址
    server_address.sin_family = AF_INET;
    //server_address.sin_addr.s_addr = htonl(INADDR_ANY);//允许连接任何地址的计算机
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); //（在服务器）设置允许连接的计算机地址，（在客户端）设置要连接的服务器地址
    server_address.sin_port = htons(9734);                   //端口整数从主机字节序转成网络字节序，以保证不同类型计算机得到的整数值一致（长整数使用htonl，inet_addr也有这个功能）
    server_len = sizeof(server_address);

    // ２、命名套接字
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

    // ３、创建连接队列
    listen(server_sockfd, 3);

    FD_ZERO(&readfds);
    FD_SET(server_sockfd, &readfds); //将监听套接字添加到select监听的集合中

    while (1)
    {
        char buffer[1024];
        int fd;
        int nread; //缓冲区内的字节数

        testfds = readfds;

        printf("server waiting ...\n");

        // ４、阻塞，监听套接字是否有活动发生
        result = select(FD_SETSIZE, &testfds, (fd_set *)0, (fd_set *)0, (struct timeval *)0);

        if (result < 1)
        {
            perror("server");
            exit(1);
        }

        // ５、遍历套接字集合，找到发生活动的套接字并处理
        for (fd = 0; fd < FD_SETSIZE; fd++)
        {
            //判断该套接字是否发生活动
            if (FD_ISSET(fd, &testfds))
            {
                // ６、如果是监听套接字发生活动，接受客户连接，并将该客户的连接套接字添加到select监听的集合中
                if (fd == server_sockfd)
                {
                    client_len = sizeof(client_address);
                    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len); //接受连接

                    FD_SET(client_sockfd, &readfds); //将该客户的连接套接字添加到select监听的集合中
                    printf("add a client on socket %d", client_sockfd);
                }
                // ７、如果是连接套接字发生活动，进行通信
                else
                {
                    ioctl(fd, FIONREAD, &nread); //获取缓冲区有多少个字节

                    //如果字节数为0，说明n = 是close活动，客户关闭了套接字
                    if (nread == 0)
                    {
                        close(fd);            //关闭连接套接字
                        FD_CLR(fd, &readfds); //将套接字从select监听的集合中删除
                        printf("remove a client on socket %d", fd);
                    }
                    //否则进行通信
                    else
                    {
                        read(fd, buffer, sizeof(buffer)); //阻塞，直到客户发送信息
                        printf("received\n");

                        buffer[strlen(buffer) - 1] = '\0'; //将'\n'去掉
                        strcat(buffer, " hello");          //拼接字符串

                        write(fd, buffer, strlen(buffer) + 1);
                        printf("send\n");
                    }
                }
            }
        }
    }
}
