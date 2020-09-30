/*套接字：socket、bind、listen、accept、connect和close系统调用，read和write系统调用*/

/*客户端*/
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int sockfd;//套接字描述符
    int len;//套接字地址长度
    struct sockaddr_in address;//套接字地址

    int result;

    // １、为客户端创建连接套接字
    //第一个参数是套接字域
    //第二个参数是套接字类型（SOCK_STREAM、TCP、流套接字）（SOCK_DGRAM、UDP、数据报套接字）
    //第三个参数是通信协议（通常取0，默认协议）
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //设置服务端套接字地址（用来连接服务器）
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");//（在客户端）设置要连接的服务器地址，（在服务器）设置允许连接的计算机地址
    address.sin_port = htons(9734);//端口整数从主机字节序转成网络字节序，以保证不同类型计算机得到的整数值一致（长整数使用htonl，inet_addr也有这个功能）
    len = sizeof(address);

    // ２、请求连接
    //第二个参数是服务端套接字地址（根据域决定地址类型，最后转成通用类型struct sockaddr *）
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if(result == -1)
    {
        perror("Client");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        char  buffer[1024];

        printf("\n请输入内容：");
        fgets(buffer, sizeof(buffer), stdin);

        if(strncmp(buffer, "end", 3) == 0)
        {
            break;
        }

        // ３、与服务器通信
        write(sockfd, buffer, strlen(buffer)+1);
        printf("send\n");

        read(sockfd,  buffer, sizeof(buffer));//阻塞，直到服务端发送信息
        printf("\nchar from server : %s", buffer);
    }

    // ４、关闭套接字，向服务器发送一个空消息
    close(sockfd);

    return 0;
}