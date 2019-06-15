///*************************************************************************
///     @FileName: SocketIO.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-13 21:56:20
///*************************************************************************
#pragma once

namespace wd
{
class SocketIO
{
public:
    explicit
    SocketIO(int fd);
    int readn(char *buff,int len);
    int readline(char *buff,int maxlen);
    int writen(const char *buff,int len);
private:
    int recvPeek(char *buff,int len);
private:
    int _fd;
};

}//end of namespace wd
