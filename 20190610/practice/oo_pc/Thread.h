///*************************************************************************
///     @FileName: Thread.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-10 21:12:26
///*************************************************************************
#pragma once
#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{
class Thread:Noncopyable
{
public:
    Thread()
        :_pthid(0)
        ,_isRunning(false)
    {

    }
    virtual ~Thread();
    
    void start();
    void join();

private:
    virtual void run()=0;
    static void *threadFunc(void *);
private:
    pthread_t _pthid;
    bool _isRunning;

};

}//end of namespace wd
