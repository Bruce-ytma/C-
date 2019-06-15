///*************************************************************************
///     @FileName: TcpServer.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-13 23:24:58
///*************************************************************************
#pragma once
#include "Acceptor.h"
#include "EventLoop.h"
#include "TcpConnection.h"

namespace wd
{
using TcpConnectionPtr=std::shared_ptr<TcpConnection>;
using TcpConnectionCallback=std::function<void(const TcpConnectionPtr &)>;

class TcpServer
{
public:
    TcpServer(const string &ip,unsigned short port);
    void start();

    void setConnectionCallback(TcpConnectionCallback &&cb);
    void setMessageCallback(TcpConnectionCallback &&cb);
    void setCloseCallback(TcpConnectionCallback &&cb);
private:
    Acceptor _acceptor;
    EventLoop _loop;
};
}//end of namespace wd

