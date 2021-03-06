///*************************************************************************
///     @FileName: InetAddress.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-13 21:11:10
///*************************************************************************
#include "InetAddress.h"
#include <string.h>

namespace wd
{
InetAddress::InetAddress(unsigned short port)
{
    ::memset(&_addr,0,sizeof(struct sockaddr_in));
    _addr.sin_family=AF_INET;//小端模式        大端模式
    _addr.sin_port=htons(port);//主机字节序转换为网络字节序
    _addr.sin_addr.s_addr=INADDR_ANY;//inet_addr("0.0.0.0")代表本机地址(一个服务器可能有多个网卡
}

InetAddress::InetAddress(const string &ip,unsigned short port)
{
    ::memset(&_addr,0,sizeof(struct sockaddr_in));
    _addr.sin_family=AF_INET;//小端模式          大端模式
    _addr.sin_port=htons(port);//主机字节序转换为网络字节序
    _addr.sin_addr.s_addr=inet_addr(ip.c_str());
}

InetAddress::InetAddress(const struct sockaddr_in &addr)
{

}

string InetAddress::ip()const
{
    return string(::inet_ntoa(_addr.sin_addr));
}

unsigned short InetAddress::port()const
{
    return ntohs(_addr.sin_port);
}

}//end of namespace wd


