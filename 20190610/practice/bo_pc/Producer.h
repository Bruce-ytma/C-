///*************************************************************************
///     @FileName: Producer.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-11 20:10:01
///*************************************************************************
#pragma once

namespace wd
{

class TaskQueue;//前向声明(不完全类型)，可以减少头文件的依赖

class Producer
{
public:
    void create(TaskQueue &taskque);

};
}//end of namespace wd
