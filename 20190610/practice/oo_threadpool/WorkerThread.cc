///*************************************************************************
///     @FileName: WorkerThread.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-11 22:46:52
///*************************************************************************
#include "WorkerThread.h"
#include "Threadpool.h"
namespace  wd
{
void WorkerThread::run()
{
    _threadpool.threadFunc();
}
}//end of namespace wd


