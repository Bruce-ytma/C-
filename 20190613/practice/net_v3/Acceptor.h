///*************************************************************************
///     @FileName: Acceptor.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-13 16:38:47
///*************************************************************************
//#pragma once
#ifndef __WD_ACCEPTOR_H__
#define __WD_ACCEPTOR_H__

#include "InetAddress.h"
#include "Socket.h"

namespace wd
{
class Acceptor
{
public:
    Acceptor(unsigned short port);
    Acceptor(const string &ip,unsigned short port);
    void ready();
    int accept();
    int fd()const
    {
        return _listensock.fd();
    }

private:
    void setReuseAddr(bool on);
    void setReusePort(bool on);
    void bind();
    void listen();
private:
    InetAddress _addr;
    Socket _listensock;

};

}//end of namespace wd
#endif
