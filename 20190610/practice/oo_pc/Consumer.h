///*************************************************************************
///     @FileName: Consumer.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-10 20:26:16
///*************************************************************************
#pragma once

#include "Thread.h"

namespace wd
{
class TaskQueue;

class Consumer:public Thread
{
public:
    Consumer(TaskQueue &taskque)
        :_taskque(taskque)
    {

    }
private:
    void run();

private:
    TaskQueue &_taskque;

};
}//end of namespace wd
