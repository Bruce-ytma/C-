///*************************************************************************
///     @FileName: Noncopyable.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-10 20:43:16
///*************************************************************************
#pragma once

namespace wd
{
class Noncopyable
{
public:
    Noncopyable() {}
    ~Noncopyable() {}

    Noncopyable(const Noncopyable &)=delete;
    Noncopyable &operator=(const Noncopyable &)=delete;

};

}//end of namespace wd
