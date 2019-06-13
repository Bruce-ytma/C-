///*************************************************************************
///     @FileName: TcpServer.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-13 23:31:42
///*************************************************************************
#include "TcpServer.h"

namespace wd
{
TcpServer::TcpServer(const string &ip,unsigned short port)
    :_acceptor(ip,port)
    ,_loop(_acceptor)
    {

    }

void TcpServer::start()
{
    _acceptor.ready();
    _loop.loop();
}

void TcpServer::setConnectionCallback(TcpConnectionCallback &&cb)
{
    _loop.setConnectionCallback(std::move(cb));
}

void TcpServer::setMessageCallback(TcpConnectionCallback &&cb)
{
    _loop.setConnectionCallback(std::move(cb));
}

void TcpServer::setCloseCallback(TcpConnectionCallback &&cb)
{
    _loop.setCloseCallback(std::move(cb));
}
}//end of namespace wd

