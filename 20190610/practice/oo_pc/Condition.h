///*************************************************************************
///     @FileName: Condition.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-10 20:06:26
///*************************************************************************
//#pragma once

#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

#include "Noncopyable.h"
#include "MutexLock.h"

#include <pthread.h>

namespace wd
{
class Condition:Noncopyable
{
public:
    Condition(MutexLock &mutex)
        :_mutex(mutex)
    {
        if(pthread_cond_init(&_cond,nullptr))
        {
            perror("pthread_cond_init");
        }
    }

    void wait()
    {
        if(pthread_cond_wait(&_cond,_mutex.getMutexLockPtr()))
        {
            perror("pthread_cond_init");
        }
    }

    void notify()
    {
        if(pthread_cond_signal(&_cond))
        {
            perror("pthread_cond_signal");
        }
    }

    void notifyAll()
    {
        if(pthread_cond_broadcast(&_cond))
        {
            perror("pthread_cond_broadcast");
        }
    }

    ~Condition()
    {
        if(pthread_cond_destroy(&_cond))
        {
            perror("pthread_cond_destroy");
        }
    }

private:
    pthread_cond_t _cond;
    MutexLock &_mutex;
};
}//end of namespace wd

#endif

