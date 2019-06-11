///*************************************************************************
///     @FileName: Thread.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-11 20:30:25
///*************************************************************************
#include "Thread.h"
#include <stdio.h>
#include <errno.h>
#include <iostream>
using namespace std;

namespace wd
{
Thread::~Thread()
{
    if(_isRunning)
    {
        pthread_detach(_pthid);
        _isRunning=false;
    }
    cout<<"~Thread()"<<endl;
}

void Thread::start()
{
    if(pthread_create(&_pthid,nullptr,threadFunc,this))
    {
        perror("pthread_create");
        return;
    }
    _isRunning=true;
}

void Thread::join()
{
    if(_isRunning)
    {
        pthread_join(_pthid,nullptr);
        _isRunning=false;
    }
}

void *Thread::threadFunc(void *arg)
{
    Thread *pthread=static_cast<Thread *>(arg);
    if(pthread)
    {
        pthread->run();
    }
    return nullptr;
}
}//end of namespace wd


