/*套接字：socket、bind、listen、accept、connect和close系统调用，select、read和write系统调用*/
/*套接字类似文件描述符*/

/*服务端*/
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int server_sockfd, client_sockfd;  //套接字描述符
    int server_len, client_len;        //套接字地址长度
    struct sockaddr_in server_address; //服务端套接字地址
    struct sockaddr_in client_address; //客户端地址

    // １、为服务器创建监听套接字
    //第一个参数是套接字域
    //第二个参数是套接字类型（SOCK_STREAM、TCP、流套接字）（SOCK_DGRAM、UDP、数据报套接字）
    //第三个参数是通信协议（通常取0，默认协议）
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //设置套接字地址
    server_address.sin_family = AF_INET;
    //server_address.sin_addr.s_addr = htonl(INADDR_ANY);//允许连接任何地址的计算机
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");//（在服务器）设置允许连接的计算机地址，（在客户端）设置要连接的服务器地址
    server_address.sin_port = htons(9734);//端口整数从主机字节序转成网络字节序，以保证不同类型计算机得到的整数值一致（长整数使用htonl，inet_addr也有这个功能）
    server_len = sizeof(server_address);

    // ２、命名套接字
    //第二个参数是套接字地址（根据域决定地址类型，最后转成通用类型struct sockaddr *）
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

    // ３、创建连接队列
    //第二个参数是队列长度（队列满时，拒绝其他连接）
    listen(server_sockfd, 2);

    while (1)
    {
        char buffer[1024];
        printf("server waiting ...\n");

        // ４、接受连接
        //（默认是阻塞，直到有客户连接，也可设置O_NONBLOCK不阻塞）
        //（每调用一次，从队列中接受一个客户连接）
        //调用返回后，获取（１）连接套接字（用来与客户通信），（２）客户地址，（３）客户地址实际长度
        client_len = sizeof(client_address); //设置地址最大长度，超过则截断
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);

        printf("a client connect successfully\n");

        while (1)
        {
            int n;

            // ５、与客户通信
            n = read(client_sockfd, buffer, sizeof(buffer));//阻塞，直到客户发送信息
            //读取缓冲区内容为空，说明客户关闭套接字（原因：close也会发送消息）
            if(n == 0)
            {
                break;
            }
            printf("received\n");

            buffer[strlen(buffer)-1] = '\0';//将'\n'去掉
            strcat(buffer," hello"); //拼接字符串

            write(client_sockfd, buffer, strlen(buffer)+1);
            printf("send\n");
        }

        printf("disconnect\n");

        // ６、关闭新的套接字
        close(client_sockfd);
    }
}