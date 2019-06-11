///*************************************************************************
///     @FileName: Consumer.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-10 23:30:39
///*************************************************************************
#pragma once

namespace wd
{
class TaskQueue;

class Consumer
{
public:
    void get(TaskQueue &taskque);
};

}//end of namespace wd
