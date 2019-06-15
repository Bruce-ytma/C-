///*************************************************************************
///     @FileName: Socket.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-13 21:46:26
///*************************************************************************
#pragma once
namespace wd
{

class Socket
{
public:
    Socket();
    explicit
    Socket(int fd);

    int fd()const;

    void shutdownWrite();
    ~Socket();

private:
    int _fd;

};
}//end of namespace wd

