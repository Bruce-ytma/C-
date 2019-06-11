///*************************************************************************
///     @FileName: Producer.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-10 20:52:58
///*************************************************************************
#pragma once

#include "Thread.h"

namespace wd
{
//前向声明(不完全类型)，可以减少头文件的依赖
class TaskQueue;

class Producer:public Thread
{
public:
    Producer(TaskQueue &taskque)
        :_taskque(taskque)
    {

    }

private:
    void run();

private:
    TaskQueue &_taskque;

};

}//end of namespace wd
