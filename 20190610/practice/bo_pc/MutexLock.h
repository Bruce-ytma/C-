///*************************************************************************
///     @FileName: MutexLock.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-10 23:32:23
///*************************************************************************
//#pragma once

#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__

#include "Noncopyable.h"
#include <stdio.h>
#include <errno.h>
#include <pthread.h>

namespace wd
{
class MutexLock:Noncopyable
{
    public:
        MutexLock()
            :_isLocking(false)
        {
            if(pthread_mutex_init(&_mutex,NULL))
            {
                perror("pthread_mutex_init");
                return;
            }
        }

        ~MutexLock()
        {
            if(pthread_mutex_destroy(&_mutex))
            {
                perror("pthread_mutex_destroy");
                return;
            }
        }

        void lock()
        {
            if(pthread_mutex_lock(&_mutex))
            {
                perror("pthread_mutex_lock");
                return;
            }
        }

        void unlock()
        {
            if(pthread_mutex_unlock(&_mutex))
            {
                perror("pthread_mutex_unlock");
                return;
            }
        }

        bool isLocking()const
        {
            return _isLocking;
        }

        pthread_mutex_t *getMutexLockPtr()
        {
            return &_mutex;
        }

private:
    pthread_mutex_t _mutex;
    bool _isLocking;
};

class MutexLockGuard
{
public:
    MutexLockGuard(MutexLock &mutex)
        :_mutex(mutex)
    {
        _mutex.lock();
    }

    ~MutexLockGuard()
    {
        _mutex.unlock();
    }

private:
    MutexLock &_mutex;
};

}//end of namespace wd

#endif

