///*************************************************************************
///     @FileName: WorkerThread.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-11 22:43:16
///*************************************************************************
#pragma once

#include "Thread.h"
#include <iostream>
using namespace std;

namespace wd
{
class Threadpool;//防止发生头文件的循环引用

class WorkerThread:public Thread
{
public:
    WorkerThread(Threadpool &threadpool)
        :_threadpool(threadpool)
    {

    }
    ~WorkerThread()
    {
        cout<<"~WorkerThread()"<<endl;
    }

private:
    void run();

private:
    Threadpool &_threadpool;

};

}//end of namespace wd
