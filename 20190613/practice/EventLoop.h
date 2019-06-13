///*************************************************************************
///     @FileName: EventLoop.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-13 17:17:48
///*************************************************************************
//#pragma once

#ifndef __WD_EVENTLOOP_H__
#define __WD_EVENTLOOP_H__

namespace wd
{
class Acceptor;
class TcpConnection;

class EventLoop
{
public:
    using TcpConnectionPtr=std::shared_ptr<TcpConnection>;
    using TcpConnectionCallback=std::function<void(const TcpConnectionPtr &)>;
    EventLoop(Acceptor &acceptor);
    void loop();
    void unloop();
    void setConnectionCallback(TcpConnectionCallback &&cb)
    {
        _onConnection=std::move(cb);
    }

    void setMessageCallback(TcpConnectionCallback &&cb)
    {
        _onMessage=std::move(cb);
    }

    void setCloseCallback(TcpConnectionCallback &&cb)
    {
        _onClose=std::move(cb);
    }

private:
    void waitEpollFd();
    void handleNewConnection();
    void handleMessage(int fd);
    int createEpollFd();

    void addEpollFdRead(int fd);
    void delEpollFdRead(int fd);
    bool isConnectionClosed(int fd);

private:
    int _efd;
    Acceptor &_acceptor;
    vector<struct epoll_event> _eventList;
    map<int,TcpConnectionPtr> _conns;
    bool _isLooping;

    TcpConnectionCallback _onConnection;
    TcpConnectionCallback _onMessage;
    TcpConnectionCallback _onClose;
};
}//end of namesapce wd

#endif

