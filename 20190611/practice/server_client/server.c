///*************************************************************************
///     @FileName: server.c
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-12 16:34:06
///*************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int listenfd=socket(AF_INET,SOCK_STREAM,0);//默认情况下是阻塞的
    if(-1==listenfd)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

#if 0
    //一个服务器程序主动关闭后，立马可以重启
    int on=1;
    if(setsockopt(listen,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))<0)
    {
        perror("setsockopt error");
        close(listenfd);
        exit(EXIT_FAILURE);
    }

    //实现系统级别的负载均衡，一个服务器程序可以在同一台物理主机的同一时刻启动
    if(setsockopt(listenfd,SOL_SOCKET,SO_REUSEPORT，&on,sizeof(on))<0)
    {
        perror("setsockopt error");
        close(listenfd);
        exit(EXIT_FAILURE);
    }
#endif

    struct sockaddr_in serverAddr;
    printf("sizeof(struct sockaddr_in)=%ld\n",sizeof(struct sockaddr_in));
    memset(&serverAddr,0,sizeof(struct sockaddr_in));
    serverAddr.sin_family=AF_INET;//小端模式  大端模式
    serverAddr.sin_port=htons(8888);//主机字节序转换成为网络字节序
    serverAddr.sin_addr.s_addr=INADDR_ANY;//inet+addr("0.0.0.0") 代表本机地址

    int ret=bind(listenfd,(struct sockaddr *)&serverAddr,sizeof(struct sockaddr));
    if(-1==ret)
    {
        perror("bind");
        close(listenfd);
        exit(EXIT_FAILURE);
    }

    ret=listen(listenfd,10);//第二个参数的作用是，处理半链接状态的客户端的最大数量
    if(-1==ret)
    {
        perror("listen");
        close(listenfd);
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        //accept返回的文件描述符，默认情况下也是阻塞的
        int peerfd=accept(listenfd,NULL,NULL);//由accept与客户端的connect完成三次握手
        char buff[1024]="welcome to server.";//用户态的应用缓冲区
        ret=write(peerfd,buff,strlen(buff));//将应用缓冲区的数据直接copy到内核(发送缓冲区)
        memset(buff,0,1024);
        printf(">pls client data:\n");
        ret=read(peerfd,buff,1024);//将内核接受缓冲区中的数据直接copy到应用缓冲区
        printf("%s\n",buff);
    }
    close(listenfd);
    return 0;
}

