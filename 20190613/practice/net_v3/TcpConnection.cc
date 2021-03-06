///*************************************************************************
///     @FileName: TcpConnection.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-14 12:56:35
///*************************************************************************

#include "TcpConnection.h"
#include "InetAddress.h"
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sstream>

namespace wd
{
TcpConnection::TcpConnection(int fd)
    :_sock(fd)
    ,_socketIo(fd)
    ,_localAddr(getLocalAddr(fd))
    ,_peerAddr(getPeerAddr(fd))
    ,_isShutdownWrite(false)
    {

    }

TcpConnection::~TcpConnection()
{
    if(!_isShutdownWrite)
    {
        shutdown();
    }
}

string TcpConnection::receive()
{
    char buff[65535]={0};
    _socketIo.readline(buff,sizeof(buff));
    return string(buff);
}

void TcpConnection::shutdown()
{
    if(!_isShutdownWrite)
    {
        _isShutdownWrite=true;
        _sock.shutdownWrite();
    }
}

string TcpConnection::toString()const
{
    std::ostringstream oss;
    oss<<_localAddr.ip()<<":"<<_localAddr.port()<<"-->"
        <<_peerAddr.ip()<<":"<<_peerAddr.port();
    return oss.str();
}

InetAddress TcpConnection::getLocalAddr(int fd)
{
    struct sockaddr_in addr;
    socklen_t len=sizeof(struct sockaddr);
    if(getsockname(_sock.fd(),(struct sockaddr *)&addr,&len)==-1)
    {
        perror("getsockname");
    }
    return InetAddress(addr);
}

void TcpConnection::setConnectionCallback(const TcpConnectionPtrCallback &cb)
{
    _onConnection=std::move(cb);
}

void TcpConnection::setMessageCallback(const TcpConnectionPtrCallback &cb)
{
    _onMessage=std::move(cb);
}

void TcpConnection::setCloseCallback(const TcpConnectionPtrCallback &cb)
{
    _onClose=std::move(cb);
}

void TcpConnection::handleConnectionCallback()
{
    if(_onConnection)
    {
        _onConnection(shared_from_this());
    }
}

void TcpConnection::handleMessageCallback()
{
    if(_onMessage)
    {
        _onMessage(shared_from_this());
    }
}

void TcpConnection::handleCloseCallback()
{
    if(_onClose)
    {
        _onClose(shared_from_this());
    }
}

}//end of namespace wd


