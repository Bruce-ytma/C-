///*************************************************************************
///     @FileName: InetAddress.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-13 20:51:54
///*************************************************************************
#pragma once
#include <arpa/inet.h>
#include <string>
using std::string;

namespace wd
{
class InetAddress
{
public:
    explicit//只对构造函数起作用，用来抑制隐式转换
    InetAddress(unsigned short port);
    InetAddress(const string &ip,unsigned short port);
    InetAddress(const struct sockaddr_in &addr);

    string ip()const;
    unsigned short port()const;
    struct sockaddr_in *getInetAddressPtr()
    {
        return &_addr;
    }
private:
    struct sockaddr_in _addr;
};
}//end of namespace wd

