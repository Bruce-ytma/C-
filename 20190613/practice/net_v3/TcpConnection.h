///*************************************************************************
///     @FileName: TcpConnection.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-14 09:21:42
///*************************************************************************
#pragma once
#include "Socket.h"
#include "InetAddress.h"
#include "SocketIO.h"
#include "Noncopyanle.h"
#include <string>
#include <memory>
#include <functional>
using namespace std;

namespace wd
{
class TcpConnection;
using TcpConnectionPtr=std::shared_ptr<TcpConnection>;
using TcpConnectionPtrCallback=function<void(const TcpConnectionPtr &)>;

class TcpConnection:Noncopyanle,public std::enable_shared_from_this<TcpConnection>
{
public:
    TcpConnection(int fd);
    ~TcpConnection();

    string receive();
    void send(const string &msg);

    string toString()const;
    void shutdown();

    void setConnectionCallback(const TcpConnectionPtrCallback &cb);
    void setMessageCallback(const TcpConnectionPtrCallback &cb);
    void setCloseCallback(const TcpConnectionPtrCallback &cb);

    void handleConnectionCallback();
    void handleMessageCallback();
    void handleCloseCallback();

private:
    InetAddress getLocalAddr(int fd);
    InetAddress getPeerAddr(int fd);

private:
    Socket _sock;
    SocketIO _socketIo;
    InetAddress _localAddr;
    InetAddress _peerAddr;
    bool _isShutdownWrite;

    TcpConnectionPtrCallback _onConnection;
    TcpConnectionPtrCallback _onMessage;
    TcpConnectionPtrCallback _onClose;

};

}//end of namespace wd
