///*************************************************************************
///     @FileName: Thread.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-14 20:35:13
///*************************************************************************
#pragma once
#include "Noncopyable.h"
#include <pthread.h>
#include <functional>

namespace wd
{
class Thread:Noncopyable
{
public:
    using ThreadCallback=std::function<void()>;

    Thread(ThreadCallback &&cb)
        :_pthid(0)
        ,_isRunning(false)
        ,_cb(std::move(cb))
    {

    }

    ~Thread();

    void start();
    void join();
private:
    static void *threadFunc(void *);
private:
    pthread_t _pthid;
    bool _isRunning;
    ThreadCallback _cb;

};
}//end of namespace wd
